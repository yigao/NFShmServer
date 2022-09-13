// -------------------------------------------------------------------------
//    @FileName         :    NFCDynLibMgr.cpp.c
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCDynLibMgr.cpp.c
//
// -------------------------------------------------------------------------

#include "NFCDynLibMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFShmCore/NFCSharedMem.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFHash.hpp"
#include "NFComm/NFCore/NFStringUtility.h"

NFCDynLibMgr::NFCDynLibMgr()
{
    m_filePath = "shmnframe_lib.bin";
    Load();
}

NFCDynLibMgr::~NFCDynLibMgr()
{

}

int NFCDynLibMgr::Load()
{
    if (NFFileUtility::IsFileExist(m_filePath))
    {
        std::string content;
        NFFileUtility::ReadFileContent(m_filePath, content);
        m_fileInfoArray.ParseFromString(content);
    }
    return 0;
}

int NFCDynLibMgr::Save()
{
    std::string content = m_fileInfoArray.SerializeAsString();
    NFFileUtility::WriteFile(m_filePath, content);
    return 0;
}

int NFCDynLibMgr::GetLibSize(const string &md5)
{
    for(int i = 0; i < (int)m_fileInfoArray.file_list_size(); i++)
    {
        if (m_fileInfoArray.file_list(i).file_md5() == md5)
        {
            return m_fileInfoArray.file_list(i).file_size();
        }
    }
    return -1;
}

int NFCDynLibMgr::GetLib(const string &fileMd5, int fileSize, string &content)
{
    int iKey = NFHash::murmur_hash2(fileMd5.data(), fileMd5.size(), fileSize);
    iKey &= 0x7FFFFFFF;
    bool ret = ShmExist(iKey);
    if (ret)
    {
        NFCSharedMem* psharedMem = CreateShareMem(iKey, fileSize, EN_OBJ_MODE_RECOVER);
        CHECK_EXPR(psharedMem, -1, "CreateShareMem Failed!");

        char *pMem = (char*)psharedMem->CreateSegment(fileSize);
        content.assign(pMem, fileSize);

        return 0;
    }
    return -1;
}

bool NFCDynLibMgr::ShmExist(int iKey)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    return false;
#else
    int hShmID = shmget(iKey, 0, 0666);
    if (((int64_t)hShmID) < 0)
    {
        return false;
    }
    return true;
#endif
}

bool NFCDynLibMgr::ShmDestroy(int iKey)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    return false;
#else
    int hShmID = shmget(iKey, 0, 0666);
    if (((int64_t)hShmID) < 0)
    {
        return false;
    }

    if (shmctl(hShmID, IPC_RMID, NULL))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Remove share memory failed : {}", strerror(errno));
        return false;
    }

#endif
    return true;
}

int NFCDynLibMgr::DelLib(const std::string& fileMd5)
{
    int fileSize = GetLibSize(fileMd5);
    if (fileSize > 0)
    {
        int iKey = NFHash::murmur_hash2(fileMd5.data(), fileMd5.size(), fileSize);
        iKey &= 0x7FFFFFFF;

        if (ShmExist(iKey))
        {
            ShmDestroy(iKey);
        }
    }
    return 0;
}

int NFCDynLibMgr::AddLib(const std::string& fileMd5, int fileSize, const char* data, int length)
{
    DelLib(fileMd5);

    int iKey = NFHash::murmur_hash2(fileMd5.data(), fileMd5.size(), fileSize);
    iKey &= 0x7FFFFFFF;
    NFCSharedMem* pMem = CreateShareMem(iKey, fileSize, EN_OBJ_MODE_INIT);
    CHECK_EXPR(pMem, -1, "CreateShareMem Failed!");

    pMem->ClearShmInitSuccessFlag();

    void *pFileMem = pMem->CreateSegment(fileSize);
    CHECK_EXPR(pFileMem, -1, "CreateSegment Failed!");

    memcpy(pFileMem, data, length);

    bool find = false;
    for(int i = 0; i < (int)m_fileInfoArray.file_list_size(); i++)
    {
        ::proto_ff::DynLibFileInfo* fileInfo = m_fileInfoArray.mutable_file_list(i);
        if (fileInfo->file_md5() == fileMd5)
        {
            fileInfo->set_file_size(fileSize);
            find = true;
            break;
        }
    }
    if (!find)
    {
        ::proto_ff::DynLibFileInfo* pInfo = m_fileInfoArray.add_file_list();
        if (pInfo)
        {
            pInfo->set_file_md5(fileMd5);
            pInfo->set_file_size(fileSize);
        }
    }

    m_sharedMemMap.emplace(iKey, pMem);
    Save();

    pMem->SetShmInitSuccessFlag();
    return 0;
}

int NFCDynLibMgr::AddLib(const string &fileMd5, int fileSize, const string &content)
{
    DelLib(fileMd5);

    int iKey = NFHash::murmur_hash2(fileMd5.data(), fileMd5.size(), fileSize);
    iKey &= 0x7FFFFFFF;
    NFCSharedMem* pMem = CreateShareMem(iKey, fileSize, EN_OBJ_MODE_INIT);
    CHECK_EXPR(pMem, -1, "CreateShareMem Failed!");

    pMem->ClearShmInitSuccessFlag();

    void *pFileMem = pMem->CreateSegment(fileSize);
    CHECK_EXPR(pFileMem, -1, "CreateSegment Failed!");

    memcpy(pFileMem, content.data(), content.length());

    bool find = false;
    for(int i = 0; i < (int)m_fileInfoArray.file_list_size(); i++)
    {
        ::proto_ff::DynLibFileInfo* fileInfo = m_fileInfoArray.mutable_file_list(i);
        if (fileInfo->file_md5() == fileMd5)
        {
            fileInfo->set_file_size(fileSize);
            find = true;
            break;
        }
    }
    if (!find)
    {
        ::proto_ff::DynLibFileInfo* pInfo = m_fileInfoArray.add_file_list();
        if (pInfo)
        {
            pInfo->set_file_md5(fileMd5);
            pInfo->set_file_size(fileSize);
        }
    }

    m_sharedMemMap.emplace(iKey, pMem);
    Save();

    pMem->SetShmInitSuccessFlag();
    return 0;
}

NFCSharedMem* NFCDynLibMgr::CreateShareMem(int iKey, size_t siSize, int enInitFlag)
{
    NFCSharedMem* pShm = NULL;
    size_t siTempShmSize = 0;
    void* pAddr = NULL;
#if NF_PLATFORM == NF_PLATFORM_WIN
    HANDLE			hShmID = nullptr;
	long			sPageSize = 4096;
#else
    int				hShmID = 0;
    long			sPageSize = getpagesize();;
#endif

    siTempShmSize = siSize;
    siTempShmSize += sizeof(NFCSharedMem);


    if (siTempShmSize % sPageSize)
    {
        siTempShmSize = (siTempShmSize / sPageSize + 1) * sPageSize;
    }

    //NFLogDebug(NF_LOG_SYSTEMLOG, 0, "--begin create lib shm-- key:{},  size:{}M, pagesize:{}, mode:{} ", iKey, siTempShmSize/1024.0/1024.0, sPageSize, enInitFlag);

#if NF_PLATFORM == NF_PLATFORM_WIN
    std::string shmFileName = NF_FORMAT("{}_shm_key_{}.bus", NFIPluginManager::Instance()->GetAppName(), iKey);
	//std::wstring wShmFileName = NFStringUtility::s2ws(shmFileName);
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
		pShm = new NFCSharedMem(iKey, siTempShmSize, (EN_OBJ_MODE)enInitFlag, hShmID);
	}

#else

    //注意_bCreate的赋值位置:保证多线程用一个对象的时候也不会有问题
    //试图创建
    if ((hShmID = shmget(iKey, siTempShmSize, IPC_CREAT | IPC_EXCL | 0666)) < 0)
    {
        //有可能是已经存在同样的key_shm,则试图连接
        if ((hShmID = shmget(iKey, siTempShmSize, 0666)) < 0)
        {
            if ((hShmID = shmget(iKey, 0, 0666)) < 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem touch failed for error:{}, {}", errno, strerror(errno));
                NFSLEEP(1000);
                exit(-1);
            }
            else
            {
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
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem shm already exist, but size not match, alloc failed for  {}, {}", errno, strerror(errno));
                    NFSLEEP(1000);
                    exit(-1);
                }
            }
        }
    }
    else
    {
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
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CSharedMem Invalid ReqShmSize With Shm, ReqShmSize:{}  ActShmSize:{} ShmID:{} ShmKey:{}", siTempShmSize, stDs.shm_segsz, hShmID, iKey);
        return NULL;
    }

    //try to access shm
    if ((pAddr = shmat(hShmID, NULL, 0)) == (char *)-1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateShareMem shmat failed for  {}, {}", errno, strerror(errno));
        NFSLEEP(1000);
        exit(-1);
    }

    if (pAddr != (void *)-1)
    {
        NFCSharedMem::pbCurrentShm = (char*)pAddr;
        NFCSharedMem::s_bCheckInitSuccessFlag = enInitFlag;
        pShm = new NFCSharedMem(iKey, siTempShmSize, (EN_OBJ_MODE)enInitFlag, hShmID);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "shmat failed for  {}, {}", errno, strerror(errno));
        NFSLEEP(1000);
        exit(-1);
    }
#endif

    //NFLogDebug(NF_LOG_SYSTEMLOG, 0, " --end-- pShm:{}", (void*)pShm);

    return pShm;
}

