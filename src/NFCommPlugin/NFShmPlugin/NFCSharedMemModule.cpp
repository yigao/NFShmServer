// -------------------------------------------------------------------------
//    @FileName         :    NFCSharedMemModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFCSharedMemModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

#include <cassert>
#include <errno.h>
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFGlobalID.h"
#include "NFIDRuntimeClass.h"
#include "NFShmObjSeg.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "NFShmIdx.h"
#include "NFShmTimerManager.h"
#include "NFTransMng.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFShmEventMgr.h"

NFCSharedMemModule::NFCSharedMemModule(NFIPluginManager *p) : NFISharedMemModule(p)
{
    m_pObjPluginManager = p;
    m_pSharedMemMgr = NULL;
    m_enRunMode = EN_OBJ_MODE_RECOVER;
    m_enCreateMode = EN_OBJ_MODE_RECOVER;
    m_siShmSize = 0;
    m_nRunTimeFileID = p->GetAppID();

    m_iObjSegSizeTotal = 0;
    m_iTotalObjCount = 0;
    m_nObjSegSwapCounter.resize(EOT_MAX_TYPE);
    m_pGlobalID = NULL;
}

NFCSharedMemModule::~NFCSharedMemModule()
{
}

bool NFCSharedMemModule::AfterLoadAllPlugin()
{
    std::list<NFIPlugin *> listPlugin = m_pObjPluginManager->GetListPlugin();

    for (auto iter = listPlugin.begin(); iter != listPlugin.end(); ++iter)
    {
        NFIPlugin *pPlugin = *iter;
        if (pPlugin)
        {
            pPlugin->InitShmObjectRegister();
        }
    }

    /*
        分配共享内存
    */
    AllocShm();

    /*
        初始化共享内存里的对象
    */
    InitializeAllObj();

    /*
        创建一些全局性对象
    */
    InitShmObjectGlobal();

    return true;
}

bool NFCSharedMemModule::ReadyExecute()
{
    return true;
}

bool NFCSharedMemModule::Execute()
{
    NFShmTimerManager *pTimerMng = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pTimerMng)
    {
        pTimerMng->OnTick(NFTime::Now().UnixMSec());
    }
    NFTransMng *pTransManager = (NFTransMng *) GetHeadObj(EOT_TRANS_MNG);
    if (pTransManager)
    {
        pTransManager->TickNow(m_pObjPluginManager->GetCurFrameCount());
    }
    return true;
}

bool NFCSharedMemModule::Finalize()
{
    DestroyShareMem();
    return true;
}

bool NFCSharedMemModule::OnReloadConfig()
{
    return true;
}

bool NFCSharedMemModule::AfterOnReloadConfig()
{
    for (int i = 0; i < (int) m_nObjSegSwapCounter.size(); i++)
    {
        NFShmObjSeg *pObjSeg = m_nObjSegSwapCounter[i].m_pObjSeg;
        if (pObjSeg)
        {
            for(auto iter = pObjSeg->begin(); iter != pObjSeg->end(); iter++)
            {
                iter->AfterOnReloadConfig();
            }
        }
    }
    return true;
}

int NFCSharedMemModule::ReadRunMode()
{
    if (m_pObjPluginManager->IsInitShm())
    {
        m_enRunMode = EN_OBJ_MODE_INIT;
    }
    else
    {
        m_enRunMode = EN_OBJ_MODE_RECOVER;
    }
    return 0;
}

/**
* 分配共享内存
*/
int NFCSharedMemModule::AllocShm()
{
    return AllocShm(NFServerIDUtil::GetShmObjKey(m_pObjPluginManager->GetBusName()), GetAllObjSize());
}

int NFCSharedMemModule::AllocShm(int iKey, size_t siShmSize)
{
    int iRet = 0;
    ReadRunMode();

    if (m_enRunMode == EN_OBJ_MODE_RECOVER)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "run by RECOVER mode");
    }
    else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "run by INIT mode");
    }

    m_siShmSize = siShmSize;
    m_pSharedMemMgr = CreateShareMem(iKey, m_siShmSize, m_enRunMode, true);
    if (!m_pSharedMemMgr)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "create shm fail");
        iRet = -1;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "--end-- ret {}", iRet);

    return iRet;
}

/**
* 从共享内存里获得一块内存
*/
void *NFCSharedMemModule::CreateSegment(size_t siSize)
{
    if (m_pSharedMemMgr)
    {
        return m_pSharedMemMgr->CreateSegment(siSize);
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
    return NULL;
}

/**
* 共享内存模式
*/
EN_OBJ_MODE NFCSharedMemModule::GetInitMode()
{
    if (m_pSharedMemMgr)
    {
        return m_pSharedMemMgr->GetInitMode();
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
    return EN_OBJ_MODE_INIT;
}

void NFCSharedMemModule::SetInitMode(EN_OBJ_MODE mode)
{
    if (m_pSharedMemMgr)
    {
        return m_pSharedMemMgr->SetInitMode(mode);
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
}

/**
* 共享内存创建对象模式
*/
EN_OBJ_MODE NFCSharedMemModule::GetCreateMode()
{
    return m_enCreateMode;
}

/**
* 共享内存创建对象模式
*/
void NFCSharedMemModule::SetCreateMode(EN_OBJ_MODE mode)
{
    m_enCreateMode = mode;
}

/**
* @brief  对象seq自增
*/
int NFCSharedMemModule::IncreaseObjSeqNum()
{
    if (m_pSharedMemMgr)
    {
        return m_pSharedMemMgr->IncreaseObjSeqNum();
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
    return 0;
}

/**
* @brief  获得偏移地址
*/
size_t NFCSharedMemModule::GetAddrOffset()
{
    if (m_pSharedMemMgr)
    {
        return m_pSharedMemMgr->GetAddrOffset();
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
    return 0;
}

/**
* @brief  NFGlobalID
*/
NFGlobalID *NFCSharedMemModule::GetGlobalID()
{
    return m_pGlobalID;
}

/**
* @brief  设置功能内存初始化成功
*/
void NFCSharedMemModule::SetShmInitSuccessFlag()
{
    if (m_pSharedMemMgr)
    {
        m_pSharedMemMgr->SetShmInitSuccessFlag();
    }
    NF_ASSERT_MSG(m_pSharedMemMgr, "m_pSharedMemMgr == NULL");
}

/**
* @brief  运行时文件ID
*/
uint32_t NFCSharedMemModule::GetRunTimeFileId()
{
    return m_nRunTimeFileID;
}

NFCSharedMem *NFCSharedMemModule::CreateShareMem(int iKey, size_t siSize, EN_OBJ_MODE enInitFlag, bool bCheckShmInitSuccessFlag)
{
    NFCSharedMem *pShm = NULL;
    size_t siTempShmSize = 0;
    void *pAddr = NULL;
#if NF_PLATFORM == NF_PLATFORM_WIN
    HANDLE			hShmID = nullptr;
    long			sPageSize = 4096;
#else
    int hShmID = 0;
    long sPageSize = getpagesize();;
#endif

    siTempShmSize = siSize;
    siTempShmSize += sizeof(NFCSharedMem);


    if (siTempShmSize % sPageSize)
    {
        siTempShmSize = (siTempShmSize / sPageSize + 1) * sPageSize;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "--begin-- key:{},  size:{}M, pagesize:{}, mode:{} ", iKey, siTempShmSize / 1024.0 / 1024.0, sPageSize,
              enInitFlag);

#if NF_PLATFORM == NF_PLATFORM_WIN
    std::string tempFileName = NF_FORMAT("{}_shm_key_{}.bus", m_pObjPluginManager->GetAppName(), iKey);
    std::wstring shmFileName = NFStringUtility::s2ws(tempFileName);
    hShmID = OpenFileMapping(FILE_MAP_ALL_ACCESS, false, shmFileName.c_str());

    if (hShmID == nullptr)
    {
        HANDLE hFileID = CreateFile(shmFileName.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

        if (hFileID == nullptr)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem CreateFile error:{}, {}", errno, strerror(errno));
            NFSLEEP(1);
            exit(-1);
        }

        hShmID = CreateFileMapping(hFileID, nullptr, PAGE_READWRITE, 0, static_cast<DWORD>(siTempShmSize), shmFileName.c_str());

        if (hShmID == nullptr)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem CreateFile error:{}, {}", errno, strerror(errno));
            NFSLEEP(1);
            exit(-1);
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm ori mode {} change to mode {}(mode 1:Init, 2:Recover)", enInitFlag, EN_OBJ_MODE_INIT);

        enInitFlag = EN_OBJ_MODE_INIT;
    }

    pAddr = (void*)MapViewOfFile(hShmID, FILE_MAP_ALL_ACCESS, 0, 0, siTempShmSize);
    if (pAddr == nullptr)
    {
        CloseHandle(hShmID);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem MapViewOfFile error:{}, {}", errno, strerror(errno));
        NFSLEEP(1);
        exit(-1);
    }
    else
    {
        NFCSharedMem::pbCurrentShm = (char*)pAddr;
        NFCSharedMem::s_bCheckInitSuccessFlag = enInitFlag;
        pShm = new NFCSharedMem(iKey, siTempShmSize, enInitFlag, hShmID);
    }

#else

    //注意_bCreate的赋值位置:保证多线程用一个对象的时候也不会有问题
    //试图创建
    if ((hShmID = shmget(iKey, siTempShmSize, IPC_CREAT | IPC_EXCL | 0666)) < 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CreateShareMem failed for error:{}, {}, server will try to attach it", errno, strerror(errno));
        //no space left
        if (errno == 28 || errno == 12)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem failed for error:{}, {}", errno, strerror(errno));
            NFSLEEP(1000);
            exit(-1);
        }

        //有可能是已经存在同样的key_shm,则试图连接
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "same shm  exist, now try to attach it ... ");
        if ((hShmID = shmget(iKey, siTempShmSize, 0666)) < 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem failed for error:{}, {}", errno, strerror(errno));
            if ((hShmID = shmget(iKey, 0, 0666)) < 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem failed for error:{}, {}", errno, strerror(errno));
                NFSLEEP(1000);
                exit(-1);
            }
            else
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "rm the exsit shm ...");
                if (EN_OBJ_MODE_INIT == enInitFlag)
                {
                    if (shmctl(hShmID, IPC_RMID, NULL))
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem rm failed for {}, {}", errno, strerror(errno));
                        NFSLEEP(1000);
                        exit(-1);
                    }

                    if ((hShmID = shmget(iKey, siTempShmSize, IPC_CREAT | IPC_EXCL | 0666)) < 0)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem alloc failed for  {}, {}", errno, strerror(errno));
                        NFSLEEP(1000);
                        exit(-1);
                    }
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem shm already exist, but size not match, alloc failed for  {}, {}", errno,
                               strerror(errno));
                    NFSLEEP(1000);
                    exit(-1);
                }
            }
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "attach succ ");
        }
    }
    else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shm ori mode {} change to mode {}(mode 1:Init, 2:Recover)", enInitFlag, EN_OBJ_MODE_INIT);
        enInitFlag = EN_OBJ_MODE_INIT;
    }

    struct shmid_ds stDs;

    int iRetCode = shmctl(hShmID, IPC_STAT, &stDs);
    if (iRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CSharedMem shmctl Failed");
        return NULL;
    }

    if (siTempShmSize != stDs.shm_segsz)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CSharedMem Invalid ReqShmSize With Shm, ReqShmSize:{}  ActShmSize:{} ShmID:{} ShmKey:{}", siTempShmSize,
                   stDs.shm_segsz, hShmID, iKey);
        return NULL;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CSharedMem ReqShmSize:{}M ActShmSize:{}M ShmID:{} ShmKey:{}", siTempShmSize / 1024.0 / 1024.0,
              stDs.shm_segsz / 1024.0 / 1024.0, hShmID, iKey);
    //try to access shm
    if ((pAddr = shmat(hShmID, NULL, 0)) == (char *) -1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem shmat failed for  {}, {}", errno, strerror(errno));
        NFSLEEP(1000);
        exit(-1);
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "shmat return {}", (void *) pAddr);

    if (pAddr != (void *) -1)
    {
        NFCSharedMem::pbCurrentShm = (char *) pAddr;
        NFCSharedMem::s_bCheckInitSuccessFlag = enInitFlag;
        pShm = new NFCSharedMem(iKey, siTempShmSize, enInitFlag, hShmID);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "shmat failed for  {}, {}", errno, strerror(errno));
        NFSLEEP(1000);
        exit(-1);
    }
#endif

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, " --end-- pShm:{}", (void *) pShm);

    return pShm;
}

/**
* 摧毁共享内存
*/
int NFCSharedMemModule::DestroyShareMem()
{
// 	if (m_pSharedMemMgr == NULL)
// 	{
// 		return 0;
// 	}
// 
// #if NF_PLATFORM == NF_PLATFORM_WIN
// 	if (m_pSharedMemMgr->pbCurrentShm != NULL)
// 	{
// 		UnmapViewOfFile(m_pSharedMemMgr->pbCurrentShm);
// 		CloseHandle(m_pSharedMemMgr->m_shemID);
// 
// 		m_pSharedMemMgr->m_shemID = NULL;
// 		m_pSharedMemMgr->pbCurrentShm = NULL;
// 	}
// #else
// 	int hShmID = shmget(m_pSharedMemMgr->m_nShmKey, 0, 0666);
// 	if (((int64_t)hShmID) < 0)
// 	{
// 		NFLogError(NF_LOG_SYSTEMLOG, 0, "Error, touch to shm failed {}", strerror(errno));
// 		return -1;
// 	}
// 	else
// 	{
// 		NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Now remove the exist share memory:{}", hShmID);
// 
// 		if (shmctl(hShmID, IPC_RMID, NULL))
// 		{
// 			NFLogError(NF_LOG_SYSTEMLOG, 0, "Remove share memory failed : {}", strerror(errno));
// 			return -1;
// 		}
// 
// 		NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Remove shared memory(id = {}, key = {}) succeed.", hShmID, m_pSharedMemMgr->m_nShmKey);
// 	}
// 
// #endif

    return 0;
}


std::string NFCSharedMemModule::GetClassName(int bType)
{
    NF_ASSERT_MSG((int) bType < (int) m_nObjSegSwapCounter.size(), "bType < (int)m_nObjSegSwapCounter.size()");
    return m_nObjSegSwapCounter[bType].m_szClassName;
}

int NFCSharedMemModule::GetClassType(int bType)
{
    NF_ASSERT_MSG((int) bType < (int) m_nObjSegSwapCounter.size(), "bType < (int)m_nObjSegSwapCounter.size()");
    return m_nObjSegSwapCounter[bType].m_iObjType;
}

NFShmObjSegSwapCounter *NFCSharedMemModule::CreateCounterObj(int bType)
{
    NF_ASSERT_MSG((int) bType < (int) m_nObjSegSwapCounter.size(), "bType < (int)m_nObjSegSwapCounter.size()");
    return &m_nObjSegSwapCounter[bType];
}

int NFCSharedMemModule::InitAllObjSeg()
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "total obj shm size: {}M", m_iObjSegSizeTotal / 1024.0 / 1024.0);
    int iRet = 0;

    for (int i = 0; i < (int) m_nObjSegSwapCounter.size(); i++)
    {
        m_nObjSegSwapCounter[i].m_iObjType = i;
        m_nObjSegSwapCounter[i].m_pidRuntimeClass.m_iObjType = i;
        if (m_nObjSegSwapCounter[i].m_nObjSize > 0 && m_nObjSegSwapCounter[i].m_iItemCount > 0)
        {
            NFShmObjSeg *pObjSeg = NFShmObjSeg::CreateObject(m_pObjPluginManager);
            NFShmObjSegSwapCounter *pObjSegSwapCounter = &m_nObjSegSwapCounter[i];
            pObjSegSwapCounter->SetObjSeg(pObjSeg);
            NFShmMgr::Instance()->m_pTempPluginManager = m_pObjPluginManager;
            NFShmMgr::Instance()->m_iType = i;
            iRet = pObjSeg->SetAndInitObj(pObjSegSwapCounter->m_nObjSize,
                                          pObjSegSwapCounter->m_iItemCount,
                                          pObjSegSwapCounter->m_pResumeFn, pObjSegSwapCounter->m_iUseHash);

            NFShmMgr::Instance()->m_pTempPluginManager = NULL;
            NFShmMgr::Instance()->m_iType = INVALID_ID;

            if (iRet)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFShmObjSeg::InitAllObj failed!");
                return iRet;
            }
            else
            {
                size_t sObjSegSize = pObjSeg->GetMemSize();

                if (sObjSegSize / 1024.0 / 1024.0 >= 1.0)
                {
                    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "{} count {}   --- ObjStart:{}, size:{}({}MB)", pObjSegSwapCounter->m_szClassName,
                              pObjSegSwapCounter->m_iItemCount,
                              (void *) pObjSeg->m_pObjs, sObjSegSize, (float) sObjSegSize / 1024.0 / 1024.0);
                }
                else {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{} count {}   --- ObjStart:{}, size:{}({}MB)", pObjSegSwapCounter->m_szClassName,
                                 pObjSegSwapCounter->m_iItemCount,
                                 (void *) pObjSeg->m_pObjs, sObjSegSize, (float) sObjSegSize / 1024.0 / 1024.0);
                }
            }
        }
    }

    return 0;
}

void
NFCSharedMemModule::RegisterClassToObjSeg(int bType, size_t nObjSize, int iItemCount, NFShmObj *(*pfResumeObj)(NFIPluginManager *pPluginManager, void *),
                                   NFShmObj *(*pCreatefn)(NFIPluginManager *pPluginManager),
                                   void(*pDestroy)(NFIPluginManager *pPluginManager, NFShmObj *), int parentType, const std::string &pszClassName,
                                   bool useHash, bool singleton)
{
    NFShmObjSegSwapCounter *pCounter = CreateCounterObj(bType);
    bool add = false;
    if (pCounter->m_nObjSize > 0)
    {
        add = true;
        NF_ASSERT(pCounter->m_nObjSize == nObjSize);
        NF_ASSERT(pCounter->m_iObjType == bType);
        NF_ASSERT(pCounter->m_singleton == singleton);
        NF_ASSERT(pCounter->m_pResumeFn == pfResumeObj);
        NF_ASSERT(pCounter->m_szClassName == pszClassName);
        NF_ASSERT(pCounter->m_pidRuntimeClass.m_iObjType == bType);
        NF_ASSERT(pCounter->m_pCreatefn == pCreatefn);
        NF_ASSERT(pCounter->m_pDestroyFn == pDestroy);

        NF_ASSERT(pCounter->m_iUseHash == useHash);
        if (singleton)
        {
            return;
        }
    }
    pCounter->m_nObjSize = nObjSize;
    pCounter->m_iItemCount += iItemCount;
    pCounter->m_iObjType = bType;
    pCounter->m_singleton = singleton;

    if (pCounter->m_iItemCount < 0)
    {
        pCounter->m_iItemCount = 0;
    }

    if (singleton)
    {
        pCounter->m_iItemCount = 1;
    }

    pCounter->m_pResumeFn = pfResumeObj;
    pCounter->m_szClassName = pszClassName;

    pCounter->m_pidRuntimeClass.m_iObjType = bType;
    pCounter->m_pCreatefn = pCreatefn;
    pCounter->m_pDestroyFn = pDestroy;
    if (parentType < 0)
    {
        pCounter->m_pidRuntimeClass.m_pParent = NULL;
    }
    else
    {
        pCounter->m_pidRuntimeClass.m_pParent = GetIDRuntimeClass(parentType);
        NFIDRuntimeClass *pParentClass = pCounter->m_pidRuntimeClass.m_pParent;
        while (pParentClass)
        {
            pParentClass->m_childrenObjType.insert(bType);
            pCounter->m_pidRuntimeClass.m_parentObjType.insert(pParentClass->m_iObjType);
            pParentClass = pParentClass->m_pParent;
        }
    }
    pCounter->m_pObjSeg = NULL;
    pCounter->m_szClassName = pszClassName;
    pCounter->m_iUseHash = useHash;

    size_t siThisObjSegTotal = 0;
    if (!add)
    {
        siThisObjSegTotal += sizeof(NFShmObjSeg);
        siThisObjSegTotal += NFShmDyList<NFShmIdx>::CountSize(pCounter->m_iItemCount);
        if (pCounter->m_iUseHash)
        {
            siThisObjSegTotal += NFShmObjSeg::GetHashSize(pCounter->m_iItemCount);
        }
        siThisObjSegTotal += pCounter->m_nObjSize * pCounter->m_iItemCount;

        m_iObjSegSizeTotal += siThisObjSegTotal;
        m_iTotalObjCount += pCounter->m_iItemCount;

        if (siThisObjSegTotal / 1024.0 / 1024.0 >= 1)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "class {} objsize {} M count {} tablesize {} M total obj count {}", pszClassName,
                         pCounter->m_nObjSize / 1024.0 / 1024.0, pCounter->m_iItemCount, siThisObjSegTotal / 1024.0 / 1024.0, m_iTotalObjCount);
        }
        else
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "class {} objsize {} byte count {} tablesize {} M total obj count {}", pszClassName,
                      pCounter->m_nObjSize, pCounter->m_iItemCount, siThisObjSegTotal / 1024.0 / 1024.0, m_iTotalObjCount);
        }
    }
    else {
        siThisObjSegTotal += NFShmDyList<NFShmIdx>::CountSize(iItemCount);
        if (pCounter->m_iUseHash)
        {
            siThisObjSegTotal += NFShmObjSeg::GetHashSize(iItemCount);
        }
        siThisObjSegTotal += pCounter->m_nObjSize * iItemCount;

        m_iObjSegSizeTotal += siThisObjSegTotal;
        m_iTotalObjCount += iItemCount;

        if (siThisObjSegTotal / 1024.0 / 1024.0 >= 10)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "append class {} objsize {} M count {} tablesize {} M total obj count {}", pszClassName,
                         pCounter->m_nObjSize / 1024.0 / 1024.0, iItemCount, siThisObjSegTotal / 1024.0 / 1024.0, m_iTotalObjCount);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "append class {} objsize {} byte count {} tablesize {} M total obj count {}", pszClassName,
                      pCounter->m_nObjSize, iItemCount, siThisObjSegTotal / 1024.0 / 1024.0, m_iTotalObjCount);
        }
    }

    CHECK_EXPR_NOT_RET(m_iTotalObjCount < MAX_GLOBALID_NUM * 0.8, "the shm obj too much, m_iTotalObjCount:{} < MAX_GLOBALID_NUM:{}*0.8",
                       m_iTotalObjCount, MAX_GLOBALID_NUM);
}

void NFShmObjSegSwapCounter::SetObjSeg(NFShmObjSeg *pObjSeg)
{
    m_pObjSeg = pObjSeg;
}

//////////////////////////////////////////////////////////////////////////
int NFCSharedMemModule::InitializeAllObj()
{
    int iRet = InitAllObjSeg();

    if (iRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "failed!");
        return -1;
    }

    //对象内存分配完毕后，统一把创建方式改为Init.
    NFShmMgr::Instance()->SetCreateMode(EN_OBJ_MODE_INIT);
    SetCreateMode(EN_OBJ_MODE_INIT);
    return 0;
}

size_t NFCSharedMemModule::GetAllObjSize()
{
    return m_iObjSegSizeTotal;
}

int NFCSharedMemModule::InitShmObjectGlobal()
{
    int iRet = 0;

    if (GetInitMode() == EN_OBJ_MODE_RECOVER)
    {
        m_pGlobalID = (NFGlobalID *) FindModule<NFISharedMemModule>()->GetObjByObjId(EOT_GLOBAL_ID, 0);
    }
    else
    {
        m_pGlobalID = (NFGlobalID *) NFGlobalID::CreateObject(m_pObjPluginManager);
        //CreateObjByHashKey(EOT_TYPE_TIMER_MNG);
        for (int i = EOT_GLOBAL_ID + 1; i < (int) m_nObjSegSwapCounter.size(); i++)
        {
            if (m_nObjSegSwapCounter[i].m_nObjSize > 0 && m_nObjSegSwapCounter[i].m_iItemCount > 0)
            {
                NFShmObjSegSwapCounter *pObjSegSwapCounter = &m_nObjSegSwapCounter[i];
                if (pObjSegSwapCounter->m_singleton)
                {
                    CreateObj(i);
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Create Shm Global Obj:{}", pObjSegSwapCounter->m_szClassName);
                }
            }
        }
    }

    InitSpecialShmObj();

    return iRet;
}

int NFCSharedMemModule::InitSpecialShmObj()
{
    NFTransMng *pManager = (NFTransMng *) GetHeadObj(EOT_TRANS_MNG);
    if (pManager)
    {
        /**
         * @brief 平衡处理，大概一帧处理200个trans
         */
        pManager->Init(1, 200);
    }

    if (GetInitMode() == EN_OBJ_MODE_RECOVER)
    {
        NFTransMng *pManager = (NFTransMng *) GetHeadObj(EOT_TRANS_MNG);
        if (pManager)
        {
            pManager->RebuildTransObjPointerListForResume();
        }
    }

    return 0;
}

NFShmObjSeg *NFCSharedMemModule::GetObjSeg(int iType)
{
    if (iType >= 0 && iType < (int) m_nObjSegSwapCounter.size()
        && m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        return m_nObjSegSwapCounter[iType].m_pObjSeg;
    }

    return NULL;
}

NFShmObjSegSwapCounter *NFCSharedMemModule::GetObjSegSwapCounter(int iType)
{
    if (iType >= 0 && iType < (int) m_nObjSegSwapCounter.size())
    {
        return &m_nObjSegSwapCounter[iType];
    }
    
    return NULL;
}

int NFCSharedMemModule::GetItemCount(int iType)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        return pObjSeg->GetItemCount();
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now GetItemCount iType:{} null objseg", iType);
    return 0;
}

int NFCSharedMemModule::GetUsedCount(int iType)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        return pObjSeg->GetUsedCount();
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now GetUsedCount iType:{} null objseg", iType);
    return 0;
}

int NFCSharedMemModule::GetFreeCount(int iType)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        return pObjSeg->GetFreeCount();
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now GetFreeCount iType:{} null objseg", iType);
    return 0;
}

void *NFCSharedMemModule::AllocMemForObject(int iType)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        void *p = pObjSeg->AllocMemForObject();

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{} type:{} objsize:{} AllocMem:{} usedCount:{} allCount:{}", m_nObjSegSwapCounter[iType].m_szClassName,
                   m_nObjSegSwapCounter[iType].m_iObjType, m_nObjSegSwapCounter[iType].m_nObjSize, p, pObjSeg->GetUsedCount(), pObjSeg->m_iItemCount);
        return p;
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now AllocMemForObject iType:{} null objseg", iType);
    return NULL;
}

void NFCSharedMemModule::FreeMemForObject(int iType, void *pMem)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        int iRet = pObjSeg->FreeMemForObject(pMem);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "nFreeMemForObject Failed, the pMem is no the class data, classType:{}, className:{}", iType, m_nObjSegSwapCounter[iType].m_szClassName);
        }
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now FreeMemForObject iType:{} null objseg", iType);
    return;
}

NFShmObj *NFCSharedMemModule::GetObjByObjId(int iType, int iIndex)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        return pObjSeg->GetObj(iIndex);
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now GetObjByObjId iType:{} null objseg", iType);
    return 0;
}

NFIDRuntimeClass *NFCSharedMemModule::GetIDRuntimeClass(int iType)
{
    if (iType >= 0 && iType < (int) m_nObjSegSwapCounter.size())
    {
        return &m_nObjSegSwapCounter[iType].m_pidRuntimeClass;
    }
    return NULL;
}

bool NFCSharedMemModule::IsEnd(int iType, int iIndex)
{
    assert(IsTypeValid(iType));

    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        return m_nObjSegSwapCounter[iType].m_pObjSeg->IsEnd(iIndex);
    }

    return true;
}

size_t NFCSharedMemModule::IterIncr(int iType, size_t iPos)
{
    assert(IsTypeValid(iType));

    return m_nObjSegSwapCounter[iType].m_pObjSeg->IterIncr(iPos);
}

size_t NFCSharedMemModule::IterDecr(int iType, size_t iPos)
{
    assert(IsTypeValid(iType));

    return m_nObjSegSwapCounter[iType].m_pObjSeg->IterDecr(iPos);
}

NFCSharedMemModule::iterator NFCSharedMemModule::IterBegin(int iType)
{
    assert(IsTypeValid(iType));

    return iterator(this, iType, m_nObjSegSwapCounter[iType].m_pObjSeg->IterBegin());
}

NFCSharedMemModule::iterator NFCSharedMemModule::IterEnd(int iType)
{
    assert(IsTypeValid(iType));

    return iterator(this, iType, m_nObjSegSwapCounter[iType].m_pObjSeg->IterEnd());
}

NFCSharedMemModule::const_iterator NFCSharedMemModule::IterBegin(int iType) const
{
    assert(IsTypeValid(iType));

    return const_iterator(this, iType, m_nObjSegSwapCounter[iType].m_pObjSeg->IterBegin());
}

NFCSharedMemModule::const_iterator NFCSharedMemModule::IterEnd(int iType) const
{
    assert(IsTypeValid(iType));

    return const_iterator(this, iType, m_nObjSegSwapCounter[iType].m_pObjSeg->IterEnd());
}

NFCSharedMemModule::iterator NFCSharedMemModule::Erase(NFCSharedMemModule::iterator iter)
{
    NFCSharedMemModule::iterator next_iter(this, iter.m_type, m_nObjSegSwapCounter[iter.m_type].m_pObjSeg->IterNext(iter.m_pos));
    if (iter != IterEnd(iter.m_type))
    {
        DestroyObj(iter.GetObj());
    }
    return next_iter;
}

NFShmObj* NFCSharedMemModule::GetIterObj(int iType, size_t iPos)
{
    assert(IsTypeValid(iType));

    return m_nObjSegSwapCounter[iType].m_pObjSeg->GetIterObj(iPos);
}


const NFShmObj* NFCSharedMemModule::GetIterObj(int iType, size_t iPos) const
{
    assert(IsTypeValid(iType));

    return m_nObjSegSwapCounter[iType].m_pObjSeg->GetIterObj(iPos);
}

bool NFCSharedMemModule::IsTypeValid(int iType) const
{
    if (iType < 0 || iType >= (int) m_nObjSegSwapCounter.size())
    {
        return false;
    }

    return true;
}

NFTransBase *NFCSharedMemModule::CreateTrans(int iType)
{
    CHECK_EXPR(IsTypeValid(iType), NULL, "iType:{} is not valid", iType);

    NFTransMng *pManager = (NFTransMng *) GetHeadObj(EOT_TRANS_MNG);
    if (pManager)
    {
        return pManager->CreateTrans(iType);
    }
    return NULL;
}

NFTransBase *NFCSharedMemModule::GetTrans(uint64_t ullTransId)
{
    NFTransMng *pManager = (NFTransMng *) GetHeadObj(EOT_TRANS_MNG);
    if (pManager)
    {
        return pManager->GetTransBase(ullTransId);
    }
    return NULL;
}

NFShmObj *NFCSharedMemModule::CreateObjByHashKey(int iType, ShmObjHashKey hashKey)
{
    assert(IsTypeValid(iType));

    NFShmObj *pObj = NULL;
    if (!m_nObjSegSwapCounter[iType].m_iUseHash)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "the obj can't not use hash");
        return NULL;
    }

    if (m_nObjSegSwapCounter[iType].m_pObjSeg->HashFind(hashKey))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "the hash key:{} exist.........", hashKey);
        return NULL;
    }

    NFShmMgr::Instance()->m_pTempPluginManager = m_pObjPluginManager;
    NFShmMgr::Instance()->m_iType = iType;
    pObj = m_nObjSegSwapCounter[iType].m_pCreatefn(m_pObjPluginManager);
    NFShmMgr::Instance()->m_pTempPluginManager = NULL;
    NFShmMgr::Instance()->m_iType = INVALID_ID;
    if (pObj)
    {
        int iGlobalID = pObj->GetGlobalId();
        int iObjId = pObj->GetObjId();

        if (iGlobalID >= 0 && iObjId >= 0)
        {
            if (m_nObjSegSwapCounter[iType].m_pObjSeg)
            {
                int hashRet = m_nObjSegSwapCounter[iType].m_pObjSeg->HashInsert(hashKey, iObjId);
                if (hashRet < 0)
                {
                    NFLogDebug(NF_LOG_SYSTEMLOG, hashKey, "CreateObjByHashKey Fail! hashKey:{} type:{} className:{} GlobalID:{} UsedCount:{} AllCount:{}", hashKey, iType, m_nObjSegSwapCounter[iType].m_szClassName, iGlobalID, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
                    m_nObjSegSwapCounter[iType].m_pDestroyFn(m_pObjPluginManager, pObj);
                    pObj = NULL;
                    NF_ASSERT(false);
                }
                else
                {
                    pObj->SetHashKey(hashKey);
                }

                NFLogDebug(NF_LOG_SYSTEMLOG, hashKey, "CreateObjByHashKey Success! hashKey:{} type:{} className:{} GlobalID:{} objId:{} UsedCount:{} AllCount:{}", hashKey, iType, m_nObjSegSwapCounter[iType].m_szClassName, iGlobalID, iObjId, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
            }
            else
            {
                NFLogDebug(NF_LOG_SYSTEMLOG, hashKey, "CreateObjByHashKey Fail! hashKey:{} type:{} className:{} GlobalID:{} UsedCount:{} AllCount:{}", hashKey, iType, m_nObjSegSwapCounter[iType].m_szClassName, iGlobalID, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
            }
        }
        else
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, hashKey, "CreateObjByHashKey Fail! hashKey:{} type:{} className:{} GlobalID:{} UsedCount:{} AllCount:{}", hashKey, iType, m_nObjSegSwapCounter[iType].m_szClassName, iGlobalID, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
            m_nObjSegSwapCounter[iType].m_pDestroyFn(m_pObjPluginManager, pObj);
            pObj = NULL;
            NF_ASSERT(false);
        }
    }
    else {
        NFLogDebug(NF_LOG_SYSTEMLOG, hashKey, "CreateObjByHashKey Fail! hashKey:{} type:{} className:{} UsedCount:{} AllCount:{}", hashKey, iType, m_nObjSegSwapCounter[iType].m_szClassName, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
    }

    return pObj;
}

NFShmObj *NFCSharedMemModule::CreateObj(int iType)
{
    assert(IsTypeValid(iType));

    NFShmObj *pObj = NULL;
    if (m_nObjSegSwapCounter[iType].m_iUseHash)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "the obj use hash, create obj use CreateObjByHashKey(uint64_t hashKey, int iType)");
        return NULL;
    }

    NFShmMgr::Instance()->m_pTempPluginManager = m_pObjPluginManager;
    NFShmMgr::Instance()->m_iType = iType;
    pObj = m_nObjSegSwapCounter[iType].m_pCreatefn(m_pObjPluginManager);
    NFShmMgr::Instance()->m_pTempPluginManager = NULL;
    NFShmMgr::Instance()->m_iType = INVALID_ID;
    if (pObj)
    {
        int iID = pObj->GetGlobalId();

        if (iID >= 0)
        {
        }
        else
        {
            m_nObjSegSwapCounter[iType].m_pDestroyFn(m_pObjPluginManager, pObj);
            pObj = NULL;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "No global id available, CreateObj Failed! type:{} className:{}", iType, m_nObjSegSwapCounter[iType].m_szClassName);
            NF_ASSERT(false);
        }

        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "CreateObj Success! type:{} className:{} GlobalID:{} UsedCount:{} AllCount:{}", iType, m_nObjSegSwapCounter[iType].m_szClassName, iID, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateObj Failed! type:{} className:{}", iType, m_nObjSegSwapCounter[iType].m_szClassName);
    }

    return pObj;
}

NFShmObj *NFCSharedMemModule::GetObjByHashKey(int iType, ShmObjHashKey hashKey)
{
    NF_ASSERT(IsTypeValid(iType));
    if (!m_nObjSegSwapCounter[iType].m_iUseHash)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "the obj not use hash, get obj use GetObjByGlobalId");
        return NULL;
    }

    return m_nObjSegSwapCounter[iType].m_pObjSeg->HashFind(hashKey);
}

NFShmObj *NFCSharedMemModule::GetObjByGlobalIdWithNoCheck(int iGlobalID)
{
    NFShmObj *pObj = m_pGlobalID->GetObj(iGlobalID);
    return pObj;
}

const std::unordered_set<int>& NFCSharedMemModule::GetChildrenType(int iType)
{
    NF_ASSERT(IsTypeValid(iType));

    return m_nObjSegSwapCounter[iType].m_pidRuntimeClass.m_childrenObjType;
}

NFShmObj *NFCSharedMemModule::GetObjByGlobalId(int iType, int iGlobalID, bool withChildrenType)
{
    NFShmObj *pObj = m_pGlobalID->GetObj(iGlobalID);
    if (!pObj)
    {
        return NULL;
    }

    int iRealType;
    NFIDRuntimeClass *pRuntimeClass;

#if defined(_DEBUG) | defined(_DEBUG_)
    pObj->CheckMemMagicNum();
#endif

    if (iType < 0)
    {
        return pObj;
    }

    iRealType = pObj->GetClassType();

    if ((iRealType != iType))
    {
        if (!withChildrenType)
        {
            return NULL;
        }
    }

    pRuntimeClass = ((iRealType >= 0 && iRealType < (int) m_nObjSegSwapCounter.size()) ? &m_nObjSegSwapCounter[iRealType].m_pidRuntimeClass : NULL);

    if (!pRuntimeClass)
    {
        return NULL;
    }

    if (pRuntimeClass->m_iObjType == iType)
    {
        return pObj;
    }

    if (pRuntimeClass->m_parentObjType.find(iType) != pRuntimeClass->m_parentObjType.end())
    {
        return pObj;
    }

    return NULL;
}

/*static */
NFShmObj *NFCSharedMemModule::GetObjByMiscId(int iMiscID, int iType)
{
    int iTypeInID = -1;

    if (iMiscID == -1)
    {
        return NULL;
    }

    NFShmObj *pObj;

    //MiscID is globalid
    if (iMiscID >= 0)
    {
        //带GloableID的对象尽量不要通过GetObjFromMiscID来获取对象
#if defined( _DEBUG_) | defined(_DEBUG)
        NFLogError(NF_LOG_SYSTEMLOG, 0, "advice:dont use GetObjByMiscId get object with gloablid. {} ,type {}", iMiscID, iType);
#endif
        return GetObjByGlobalId(iType, iMiscID);
    }
    else
    {
        int iIndexInID = -1;
        iTypeInID = (iMiscID & 0x7f800000) >> 23;
        iIndexInID = (iMiscID & 0x007fffff);
        pObj = GetObjByObjId(iTypeInID, iIndexInID);
    }

    if (!pObj)
    {
        return NULL;
    }

#if defined(_DEBUG) | defined(_DEBUG_)
    pObj->CheckMemMagicNum();
#endif

    int iRealType = pObj->GetClassType();

    //不需要GloableID的扩展类请不要通过CIDRuntimeClass创建对象
    assert(iRealType == iTypeInID);

    if (iRealType == iType)
    {
        return pObj;
    }

    if (iType >= 0)
    {

        NFIDRuntimeClass *pRuntimeClass = ((iRealType >= 0 && iRealType < (int) m_nObjSegSwapCounter.size())
                                           ? &m_nObjSegSwapCounter[iType].m_pidRuntimeClass : NULL);

        if (!pRuntimeClass)
        {
            assert(0);
            return NULL;
        }

        if (pRuntimeClass->m_iObjType == iType)
        {
            return pObj;
        }

        while (pRuntimeClass->m_pParent)
        {
            if (pRuntimeClass->m_pParent->m_iObjType == iType)
            {
                return pObj;
            }

            pRuntimeClass = pRuntimeClass->m_pParent;
        }

#if defined( _DEBUG_) | defined(_DEBUG)
        assert(0);
#endif
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Want Type:{} Real Type:{}", iType, iRealType)

        return NULL;
    }

    return pObj;
}

NFShmObj *NFCSharedMemModule::GetHeadObj(int iType)
{
    if (!IsTypeValid(iType))
    {
        return NULL;
    }

    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        return m_nObjSegSwapCounter[iType].m_pObjSeg->GetHeadObj();
    }

    return NULL;
}

NFShmObj *NFCSharedMemModule::GetNextObj(int iType, NFShmObj *pObj)
{
    if (!IsTypeValid(iType) || !pObj)
    {
        return NULL;
    }

    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        return m_nObjSegSwapCounter[iType].m_pObjSeg->GetNextObj(pObj);
    }

    return NULL;
}

int NFCSharedMemModule::GetGlobalId(int iType, int iIndex, NFShmObj *pObj)
{
    if (m_pGlobalID)
    {
        return m_pGlobalID->GetGlobalID(iType, iIndex, pObj);
    }
    return INVALID_ID;
}

int NFCSharedMemModule::GetObjId(int iType, NFShmObj *pObj)
{
    NFShmObjSeg *pObjSeg = GetObjSeg(iType);
    if (pObjSeg)
    {
        return pObjSeg->GetObjId(pObj);
    }
    NFLogError(NF_LOG_SYSTEMLOG, 0, "now GetObjId iType:{} null objseg", iType);
    return -1;
}

int NFCSharedMemModule::DestroyObjAutoErase(int iType, int maxNum, const DESTROY_SHM_AUTO_ERASE_FUNCTION &func)
{
    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        if (m_nObjSegSwapCounter[iType].m_iUseHash)
        {
            std::vector<NFShmObj *> vecObj;
            auto& getList = m_nObjSegSwapCounter[iType].m_pObjSeg->m_hashMgr.get_list();
            for(auto get_iter = getList.begin(); get_iter != getList.end(); get_iter++)
            {
                auto obj_iter = m_nObjSegSwapCounter[iType].m_pObjSeg->m_hashMgr.get_iterator(*get_iter);
                NFShmObj* pObj = m_nObjSegSwapCounter[iType].m_pObjSeg->GetObj(obj_iter->second);
                if (func)
                {
                    if (func(pObj))
                    {
                        vecObj.push_back(pObj);
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "DestroyObjAutoErase Data, key:{} objId:{} type:{}", obj_iter->first, obj_iter->second, iType);
                    }
                }
                else
                {
                    vecObj.push_back(pObj);
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "DestroyObjAutoErase Data, key:{} objId:{} type:{}", obj_iter->first, obj_iter->second, iType);
                }

                if (maxNum > 0 && (int)vecObj.size() >= maxNum)
                {
                    break;
                }
            }

            for (int i = 0; i < (int) vecObj.size(); i++)
            {
                DestroyObj(vecObj[i]);
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    return 0;
}

void NFCSharedMemModule::ClearAllObj(int iType)
{
    if (!IsTypeValid(iType)) return;

    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        std::vector<NFShmObj*> vec;
        for (auto iter = m_nObjSegSwapCounter[iType].m_pObjSeg->begin(); iter != m_nObjSegSwapCounter[iType].m_pObjSeg->end(); iter++)
        {
            vec.push_back(&(*iter));
        }

        for(auto iter = vec.begin(); iter != vec.end(); iter++)
        {
            DestroyObj(*iter);
        }
    }
}

void NFCSharedMemModule::DestroyObj(NFShmObj *pObj)
{
    int iType = -1;
    int iIndex = -1;
    int iGlobalID = -1;
    int64_t iHashID = -1;

    iType = pObj->GetClassType();
    iIndex = pObj->GetObjId();
    iGlobalID = pObj->GetGlobalId();
    iHashID = pObj->GetHashKey();
    std::string className = pObj->GetClassName();

    if (iType < 0 || iType >= (int) m_nObjSegSwapCounter.size())
    {
        return;
    }

    if (iIndex < 0)
    {
        return;
    }

    if (m_nObjSegSwapCounter[iType].m_pObjSeg)
    {
        if (m_nObjSegSwapCounter[iType].m_iUseHash)
        {
            NFShmObj* pTempObj = m_nObjSegSwapCounter[iType].m_pObjSeg->HashFind(iHashID);
            if (pTempObj != pObj)
            {
                NFLogError(NF_LOG_SYSTEMLOG, iHashID, "DestroyObj {} Error, key:{} globalId:{} type:{} index:{}", className, iHashID,
                           iGlobalID, iType, iIndex, iHashID);
            }
            int ret = m_nObjSegSwapCounter[iType].m_pObjSeg->HashErase(iHashID);
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "HashErase:{} Failed!", iHashID);
            }
        }

        m_pGlobalID->ReleaseID(iGlobalID);

        m_nObjSegSwapCounter[iType].m_pDestroyFn(m_pObjPluginManager, pObj);

        if (m_nObjSegSwapCounter[iType].m_iUseHash)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, iHashID, "DestroyObj {}, key:{} globalId:{} type:{} index:{} iHashID:{} UsedNum:{} AllNum:{}", className, iHashID, iGlobalID, iType, iIndex,
                       iHashID, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
        }
        else {
            NFLogDebug(NF_LOG_SYSTEMLOG, 0, "DestroyObj {}, globalId:{} type:{} index:{} UsedNum:{} AllNum:{}", className, iGlobalID, iType, iIndex, m_nObjSegSwapCounter[iType].m_pObjSeg->GetUsedCount(), m_nObjSegSwapCounter[iType].m_iItemCount);
        }
    }

    return;
}

int NFCSharedMemModule::DeleteAllTimer(NFShmObj *pObj)
{
    return NFShmTimerManager::Instance(m_pObjPluginManager)->ClearAllTimer(pObj);
}

int NFCSharedMemModule::DeleteAllTimer(NFShmObj *pObj, NFRawShmObj* pRawShmObj)
{
    return NFShmTimerManager::Instance(m_pObjPluginManager)->ClearAllTimer(pObj, pRawShmObj);
}

int NFCSharedMemModule::DeleteTimer(NFShmObj *pObj, int timeObjId)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        NFShmTimer *pShmTimer = pManager->GetTimer(timeObjId);
        if (pShmTimer)
        {
            if (pShmTimer->GetTimerShmObj() == pObj)
            {
                return pManager->Delete(timeObjId);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "timeObjId:{} pShmTimer->GetTimerShmObj:{} != pObj:{} is not the obj timer..............", timeObjId,
                           (void *) pShmTimer->GetTimerShmObj(), (void *) pObj);
                NFSLEEP(1)
                NF_ASSERT(false);
            }
        }
    }
    return -1;
}

//注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
int NFCSharedMemModule::SetTimer(NFShmObj *pObj, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetTimer(pObj, hour, minutes, second, microSec, pRawShmObj);
    }
    return -1;
}

//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
int NFCSharedMemModule::SetCalender(NFShmObj *pObj, int hour, int minutes, int second, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetCalender(pObj, hour, minutes, second, pRawShmObj);
    }
    return -1;
}

//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
int NFCSharedMemModule::SetCalender(NFShmObj *pObj, uint64_t timestamp, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetCalender(pObj, timestamp, pRawShmObj);
    }
    return -1;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
int NFCSharedMemModule::SetTimer(NFShmObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetTimer(pObj, interval, callcount, hour, minutes, second, microSec, pRawShmObj);
    }
    return -1;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFCSharedMemModule::SetDayTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetDayTime(pObj, callcount, hour, minutes, second, microSec, pRawShmObj);
    }
    return -1;
}

//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
int NFCSharedMemModule::SetDayCalender(NFShmObj *pObj, int callcount, int hour, int minutes, int second, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetDayCalender(pObj, callcount, hour, minutes, second, pRawShmObj);
    }
    return -1;
}

//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFCSharedMemModule::SetWeekTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetWeekTime(pObj, callcount, hour, minutes, second, microSec, pRawShmObj);
    }
    return -1;
}

//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
int NFCSharedMemModule::SetWeekCalender(NFShmObj *pObj, int callcount, int weekDay, int hour, int minutes, int second, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetWeekCalender(pObj, callcount, weekDay, hour, minutes, second, pRawShmObj);
    }
    return -1;
}

//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
int NFCSharedMemModule::SetMonthTime(NFShmObj *pObj, int callcount, int hour, int minutes, int second, int microSec, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetMonthTime(pObj, callcount, hour, minutes, second, microSec, pRawShmObj);
    }
    return -1;
}

//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
int NFCSharedMemModule::SetMonthCalender(NFShmObj *pObj, int callcount, int day, int hour, int minutes, int second, NFRawShmObj* pRawShmObj/* = NULL*/)
{
    NFShmTimerManager *pManager = (NFShmTimerManager *) GetHeadObj(EOT_TYPE_TIMER_MNG);
    if (pManager)
    {
        return pManager->SetMonthCalender(pObj, callcount, day, hour, minutes, second, pRawShmObj);
    }
    return -1;
}

int NFCSharedMemModule::Get32UUID()
{
    return m_pGlobalID->Get32UUID();
}

int NFCSharedMemModule::FireExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message)
{
    return NFShmEventMgr::Instance(m_pObjPluginManager)->Fire(serverType, nEventID, bySrcType, nSrcID, message);
}

int NFCSharedMemModule::Subscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const string &desc)
{
    return NFShmEventMgr::Instance(m_pObjPluginManager)->Subscribe(pObj, serverType, nEventID, bySrcType, nSrcID, desc);
}

int NFCSharedMemModule::UnSubscribe(NFShmObj *pObj, uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID)
{
    return NFShmEventMgr::Instance(m_pObjPluginManager)->UnSubscribe(pObj, serverType, nEventID, bySrcType, nSrcID);
}

int NFCSharedMemModule::UnSubscribeAll(NFShmObj *pObj)
{
    return NFShmEventMgr::Instance(m_pObjPluginManager)->UnSubscribeAll(pObj);
}
