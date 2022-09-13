// -------------------------------------------------------------------------
//    @FileName         :    NFShmMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFShmMgr.h"
#include "NFISharedMemModule.h"


NFShmMgr::NFShmMgr()
{
	m_pShmModule = nullptr;
    m_inited = false;
}

NFShmMgr::~NFShmMgr()
{
}

bool NFShmMgr::Init(NFISharedMemModule* pShmModule)
{
    m_inited = true;
	m_pShmModule = pShmModule;
	return true;
}

void NFShmMgr::UnInit()
{
	m_pShmModule = nullptr;
}

/**
* 从共享内存里获得一块内存
*/
void*	NFShmMgr::CreateSegment(size_t siSize)
{
	if (m_pShmModule)
	{
		return m_pShmModule->CreateSegment(siSize);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

NFISharedMemModule* NFShmMgr::GetShmModule()
{
	return m_pShmModule;
}
/**
* 共享内存模式
*/
EN_OBJ_MODE	NFShmMgr::GetInitMode()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetInitMode();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return EN_OBJ_MODE_INIT;
}

void NFShmMgr::SetInitMode(EN_OBJ_MODE mode)
{
	if (m_pShmModule)
	{
		return m_pShmModule->SetInitMode(mode);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

/**
* @brief  对象seq自增
*/
int	NFShmMgr::IncreaseObjSeqNum()
{
	if (m_pShmModule)
	{
		return m_pShmModule->IncreaseObjSeqNum();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

/**
* @brief  获得偏移地址
*/
size_t NFShmMgr::GetAddrOffset()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetAddrOffset();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

/**
* @brief  获得类名
*/
std::string NFShmMgr::GetClassName(int bType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetClassName(bType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return std::string();
}

int NFShmMgr::GetClassType(int bType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetClassType(bType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

void* NFShmMgr::AllocMemForObject(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->AllocMemForObject(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return NULL;
}

void NFShmMgr::FreeMemForObject(int iType, void * pMem)
{
    if (m_pShmModule)
    {
        return m_pShmModule->FreeMemForObject(iType, pMem);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return;
}

int NFShmMgr::GetExternalDataSize(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetExternalDataSize(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::GetExternalItemCount(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetExternalItemCount(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

char* NFShmMgr::GetExternalBuffer(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetExternalBuffer(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return NULL;
}

void NFShmMgr::SetObjSegParam(int bType, size_t nObjSize, int iItemCount, NFShmObj* (*pfResumeObj)(void *)
		, NFShmObj *(*pCreatefn)(), void(*pDestroy)(NFShmObj *), int parentType, const std::string& pszClassName,
		bool useHash, int exterDataSize, int exterItemCount, bool singleton)
{
	if (m_pShmModule)
	{
		return m_pShmModule->SetObjSegParam(bType, nObjSize, iItemCount, pfResumeObj, pCreatefn, pDestroy, parentType, pszClassName, useHash, exterDataSize, exterItemCount, singleton);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

size_t NFShmMgr::GetAllObjSize()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetAllObjSize();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

int NFShmMgr::InitializeAllObj()
{
	if (m_pShmModule)
	{
		return m_pShmModule->InitializeAllObj();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

/**
* 分配共享内存
*/
int NFShmMgr::AllocShm()
{
	if (m_pShmModule)
	{
		return m_pShmModule->AllocShm();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

int NFShmMgr::InitShmObjectGlobal()
{
	if (m_pShmModule)
	{
		return m_pShmModule->InitShmObjectGlobal();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

/**
* @brief  设置功能内存初始化成功
*/
void NFShmMgr::SetShmInitSuccessFlag()
{
	if (m_pShmModule)
	{
		return m_pShmModule->SetShmInitSuccessFlag();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

int NFShmMgr::GetItemCount(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetItemCount(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::GetUsedCount(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetUsedCount(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::GetFreeCount(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetFreeCount(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::GetUsedHead(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetUsedHead(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::GetFreeHead(int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetFreeHead(iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

NFShmObj *NFShmMgr::CreateObj(uint64_t hashKey, int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->CreateObj(hashKey, iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return NULL;
}

NFShmObj *NFShmMgr::GetObjFromHashKey(uint64_t hashKey, int iType)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetObjFromHashKey(hashKey, iType);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return NULL;
}

NFShmObj *NFShmMgr::GetObj(int iType, int iIndex)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetObj(iType, iIndex);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

NFShmObj *NFShmMgr::CreateObj(int iType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->CreateObj(iType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

NFShmObj *NFShmMgr::GetHeadObj(int iType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetHeadObj(iType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

NFShmObj *NFShmMgr::GetNextObj(int iType, NFShmObj *pObj)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetNextObj(iType, pObj);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

int NFShmMgr::GetObjectID(int iType, NFShmObj *pObj)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetObjectID(iType, pObj);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

int NFShmMgr::GetNextObjectID(int iType, int iObjID)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetNextObjectID(iType, iObjID);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

void NFShmMgr::DestroyObj(NFShmObj *pObj)
{
	if (m_pShmModule)
	{
		m_pShmModule->DestroyObj(pObj);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

int NFShmMgr::DestroyObjAutoErase(int iType, int maxNum, const DESTROY_SHM_AUTO_ERASE_FUNCTION& func)
{
    if (m_pShmModule)
    {
        return m_pShmModule->DestroyObjAutoErase(iType, maxNum, func);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

NFShmObj *NFShmMgr::GetObjFromGlobalID(int iGlobalID, int iType, int iStrongType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetObjFromGlobalID(iGlobalID, iType, iStrongType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

NFShmObj *NFShmMgr::GetObjFromGlobalIDWithNoCheck(int iGlobalID)
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetObjFromGlobalIDWithNoCheck(iGlobalID);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return NULL;
}

NFTransBase* NFShmMgr::CreateTrans(int iType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->CreateTrans(iType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

NFTransBase* NFShmMgr::GetTrans(uint64_t ullTransId)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetTrans(ullTransId);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

// 根据混合ID获得对象
// iType不为-1表示校验对象类型
NFShmObj *NFShmMgr::GetObjFromMiscID(int iMiscID, int iType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetObjFromMiscID(iMiscID, iType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return NULL;
}

bool NFShmMgr::IsEnd(int iType, int iIndex)
{
	if (m_pShmModule)
	{
		return m_pShmModule->IsEnd(iType, iIndex);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return false;
}

bool NFShmMgr::IsTypeValid(int iType)
{
	if (m_pShmModule)
	{
		return m_pShmModule->IsTypeValid(iType);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return false;
}

/**
* 共享内存创建对象模式
*/
EN_OBJ_MODE	NFShmMgr::GetCreateMode()
{
	if (m_pShmModule)
	{
		return m_pShmModule->GetCreateMode();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return EN_OBJ_MODE_RECOVER;
}

/**
* 共享内存创建对象模式
*/
void NFShmMgr::SetCreateMode(EN_OBJ_MODE mode)
{
	if (m_pShmModule)
	{
		m_pShmModule->SetCreateMode(mode);
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
}

int NFShmMgr::Get32UUID()
{
	if (m_pShmModule)
	{
		return m_pShmModule->Get32UUID();
	}
	NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
	return 0;
}

/**
* @brief  运行时文件ID
*/
uint32_t NFShmMgr::GetRunTimeFileId()
{
    if (m_pShmModule)
    {
        return m_pShmModule->GetRunTimeFileId();
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return 0;
}

int NFShmMgr::DeleteTimer(NFShmTimerObj *pObj, int timeObjId)
{
    if (m_pShmModule)
    {
        return m_pShmModule->DeleteTimer(pObj, timeObjId);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
int NFShmMgr::SetTimer(NFShmTimerObj *pObj, int hour, int minutes, int second, int microSec)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetTimer(pObj, hour, minutes, second, microSec);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
int NFShmMgr::SetCalender(NFShmTimerObj *pObj, int hour, int minutes, int second)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetCalender(pObj, hour, minutes, second);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
int NFShmMgr::SetCalender(NFShmTimerObj *pObj, uint64_t timestamp)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetCalender(pObj, timestamp);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
int NFShmMgr::SetTimer(NFShmTimerObj *pObj, int interval, int callcount, int hour, int minutes, int second, int microSec)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetTimer(pObj, interval, callcount, hour, minutes, second, microSec);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmMgr::SetDayTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetDayTime(pObj, callcount, hour, minutes, second, microSec);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
int NFShmMgr::SetDayCalender(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetDayCalender(pObj, callcount, hour, minutes, second);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmMgr::SetWeekTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetWeekTime(pObj, callcount, hour, minutes, second, microSec);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
int NFShmMgr::SetWeekCalender(NFShmTimerObj *pObj, int callcount, int weekDay, int hour, int minutes, int second)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetWeekCalender(pObj, callcount, weekDay, hour, minutes, second);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
int NFShmMgr::SetMonthTime(NFShmTimerObj *pObj, int callcount, int hour, int minutes, int second, int microSec)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetMonthTime(pObj, callcount, hour, minutes, second, microSec);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
int NFShmMgr::SetMonthCalender(NFShmTimerObj *pObj, int callcount, int day, int hour, int minutes, int second)
{
    if (m_pShmModule)
    {
        return m_pShmModule->SetMonthCalender(pObj, callcount, day, hour, minutes, second);
    }
    NF_ASSERT_MSG(m_pShmModule, "m_pShmModule == NULL, Not Init Shm Mgr");
    return -1;
}

