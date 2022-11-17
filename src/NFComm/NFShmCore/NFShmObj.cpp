// -------------------------------------------------------------------------
//    @FileName         :    NFShmObj.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFDynamicHead.h"
#include "NFShmObj.h"
#include "NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFShmTempMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE_NOPARENT(NFShmObj, 0)

NFShmObj::NFShmObj() : NFObject(NFShmTempMgr::Instance()->m_pTempPluginManager)
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}


NFShmObj::~NFShmObj()
{
    UnSubscribeAll();
    DeleteAllTimer();

#if defined(MAKE_FOR_DB_CHECK_CGI)
    return;
#endif

#if defined(_DEBUG) | defined(_DEBUG_)
    CheckMemMagicNum();

    //m_iMagicCheckNum = 0;
    if (m_iGlobalID != INVALID_ID)
    {
        //有globalid的对象删除没有使用CIDRuntimeClass::DestroyObj会发生这种问题，这是不允许的
        NFShmObj *pObj = FindModule<NFISharedMemModule>()->GetObjFromGlobalIDWithNoCheck(m_iGlobalID);
        assert(pObj == NULL);
    }

#endif
    m_iGlobalID = INVALID_ID;
    m_iObjSeq = INVALID_ID;
    m_iObjectID = INVALID_ID;
    m_iHashID = INVALID_ID;
}

int NFShmObj::CreateInit()
{
#if defined(_DEBUG) | defined(_DEBUG_)
    m_iMagicCheckNum = OBJECT_MAGIC_CHECK_NUMBER;
#endif

    m_iObjectID = INVALID_ID;
    m_iGlobalID = INVALID_ID;
    if (m_iObjectID == INVALID_ID)
    {
        m_iObjectID = FindModule<NFISharedMemModule>()->GetObjectID(NFShmTempMgr::Instance()->m_iType, this);
        NF_ASSERT(m_iObjectID != INVALID_ID);
    }

    int iID = FindModule<NFISharedMemModule>()->GetGlobalID(NFShmTempMgr::Instance()->m_iType, m_iObjectID, this);
    if (iID >= 0)
    {
        m_iGlobalID = iID;
    }

    m_iHashID = INVALID_ID;
    m_iObjSeq = FindModule<NFISharedMemModule>()->IncreaseObjSeqNum();

    m_bIsInRecycle = false;

    return 0;
}

int NFShmObj::OnTimer(int timeId, int callcount)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "shm obj type:{} no handle timer:{}", GetClassType(), timeId);
    return 0;
}

int NFShmObj::GetHashKey(void *pvKey, int &iKeyLength)
{
    return -1;
}

int NFShmObj::SetHashKey(const void *pvKey, int iKeyLength)
{

    return -1;
}

int NFShmObj::Show(FILE *fpOut)
{
    return -1;
}


//发送执行事件
int NFShmObj::FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message)
{
    int retCode = m_pObjPluginManager->FindModule<NFISharedMemModule>()->FireExecute(nEventID, nSrcID, bySrcType, message);
    if (retCode != 0)
    {
        return retCode;
    }

    m_pObjPluginManager->FindModule<NFIEventModule>()->FireExecute(nEventID, nSrcID, bySrcType, message);
    return retCode;
}

//订阅执行事件
int NFShmObj::Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string &desc)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->Subscribe(this, nEventID, nSrcID, bySrcType, desc);
}

//取消订阅执行事件
int NFShmObj::UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribe(this, nEventID, nSrcID, bySrcType);
}

//取消所有执行事件的订阅
int NFShmObj::UnSubscribeAll()
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->UnSubscribeAll(this);
}

int NFShmObj::DeleteAllTimer()
{
    return m_pObjPluginManager->FindModule<NFISharedMemModule>()->DeleteAllTimer(this);
}

int NFShmObj::DeleteTimer(int timeObjId)
{
    return FindModule<NFISharedMemModule>()->DeleteTimer(this, timeObjId);
}

//注册距离现在多少时间执行一次的定时器(hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒, 只执行一次)
int NFShmObj::SetTimer(int hour, int minutes, int second, int microSec)
{
    return FindModule<NFISharedMemModule>()->SetTimer(this, hour, minutes, second, microSec);
}

//注册某一个时间点执行一次的定时器(hour  minutes  second为第一次执行的时间点时分秒, 只执行一次)
int NFShmObj::SetCalender(int hour, int minutes, int second)
{
    return FindModule<NFISharedMemModule>()->SetCalender(this, hour, minutes, second);
}

//注册某一个时间点执行一次的定时器(timestamp为第一次执行的时间点的时间戳,单位是秒, 只执行一次)
int NFShmObj::SetCalender(uint64_t timestamp)
{
    return FindModule<NFISharedMemModule>()->SetCalender(this, timestamp);
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,  interval 为循环间隔时间，为毫秒）
int NFShmObj::SetTimer(int interval, int callcount, int hour, int minutes, int second, int microSec)
{
    return FindModule<NFISharedMemModule>()->SetTimer(this, interval, callcount, hour, minutes, second, microSec);
}

//注册循环执行定时器（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmObj::SetDayTime(int callcount, int hour, int minutes, int second, int microSec)
{
    return FindModule<NFISharedMemModule>()->SetDayTime(this, callcount, hour, minutes, second, microSec);
}

//注册某一个时间点日循环执行定时器（hour  minutes  second为一天中开始执行的时间点，    23：23：23     每天23点23分23秒执行）
int NFShmObj::SetDayCalender(int callcount, int hour, int minutes, int second)
{
    return FindModule<NFISharedMemModule>()->SetDayCalender(this, callcount, hour, minutes, second);
}

//周循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒）
int NFShmObj::SetWeekTime(int callcount, int hour, int minutes, int second, int microSec)
{
    return FindModule<NFISharedMemModule>()->SetWeekTime(this, callcount, hour, minutes, second, microSec);
}

//注册某一个时间点周循环执行定时器（ weekDay  hour  minutes  second 为一周中某一天开始执行的时间点）
int NFShmObj::SetWeekCalender(int callcount, int weekDay, int hour, int minutes, int second)
{
    return FindModule<NFISharedMemModule>()->SetWeekCalender(this, callcount, weekDay, hour, minutes, second);
}

//月循环（hour  minutes  second  microSec为第一次执行距离现在的时分秒毫秒,最好是同一天）
int NFShmObj::SetMonthTime(int callcount, int hour, int minutes, int second, int microSec)
{
    return FindModule<NFISharedMemModule>()->SetMonthTime(this, callcount, hour, minutes, second, microSec);
}

//注册某一个时间点月循环执行定时器（ day  hour  minutes  second 为一月中某一天开始执行的时间点）
int NFShmObj::SetMonthCalender(int callcount, int day, int hour, int minutes, int second)
{
    return FindModule<NFISharedMemModule>()->SetMonthCalender(this, callcount, day, hour, minutes, second);
}