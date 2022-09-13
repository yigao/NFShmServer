// -------------------------------------------------------------------------
//    @FileName         :    NFUserEventLog.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserEventLog.cpp
//
// -------------------------------------------------------------------------

#include "NFUserEventLog.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFTransGetEventLog.h"
#include "NFTransHandleEventLog.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFUserDetail.h"

NFUserEventLog::NFUserEventLog() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFUserEventLog::~NFUserEventLog() {

}

int NFUserEventLog::CreateInit() {
    m_bIsGetFinish = true;
    m_stLastHandleTime = 0;
    m_bIsInHandleTrans = false;
    return 0;
}

int NFUserEventLog::ResumeInit() {
    return 0;
}

int NFUserEventLog::AddEventLog(const proto_ff::tbEventLog &eventLog) {
    CHECK_EXPR(!IsEventLogFull(), -1, "event log full");
    if (GetEventLog(eventLog.event_id()))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "eventid:{} has exist, event:{}", eventLog.event_id(), eventLog.DebugString());
        return -1;
    }

    proto_ff_s::tbEventLog_s* pLog = m_astEventLog.Add();
    CHECK_NULL(pLog);
    proto_ff_s::tbEventLog_s::read_from_pbmsg(eventLog, *pLog);

    return 0;
}

int NFUserEventLog::DelEventLog(uint64_t eventId) {
    for(int i = 0; i < (int)m_astEventLog.GetSize(); i++)
    {
        if (m_astEventLog[i].event_id == eventId)
        {
            m_astEventLog.MemShiftDel(i);
            return 0;
        }
    }
    return -1;
}

proto_ff_s::tbEventLog_s *NFUserEventLog::GetEventLog(uint64_t eventId) {
    for(int i = 0; i < (int)m_astEventLog.GetSize(); i++)
    {
        if (m_astEventLog[i].event_id == eventId)
        {
            return &m_astEventLog[i];
        }
    }
    return nullptr;
}

proto_ff_s::tbEventLog_s *NFUserEventLog::GetLastEventLog() {
    if(!IsEventLogEmpty())
    {
        return &m_astEventLog[0];
    }

    return NULL;
}

bool NFUserEventLog::IsNeedHandle() {
    if(m_bIsInHandleTrans)
        return false;

    if(IsEventLogEmpty())
    {
        return false;
    }

    if(NFTime::Now().UnixMSec() - m_stLastHandleTime > 100 )
    {
        return true;
    }

    return false;
}

int NFUserEventLog::OnHandleEventLog(uint64_t eventId, bool bSuccess) {
    if( bSuccess )
    {
        DelEventLog(eventId);
    }

    m_stLastHandleTime = NFTime::Now().UnixMSec();
    m_bIsInHandleTrans = false;

    return 0;
}

int NFUserEventLog::Tick(NFUserDetail* pUserDetail)
{
    CHECK_NULL(pUserDetail && pUserDetail->GetEventLog());

    if(IsNeedHandle())
    {
        NFTransHandleEventLog* pTrans = (NFTransHandleEventLog*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_HANDLE_EVENT_LOG_ID);
        CHECK_EXPR(pTrans, -1, "Create Msg Trans Failed! UsedItem:{}", NFTransHandleEventLog::GetUsedCount());

        pTrans->Init(pUserDetail, 0, 0);

        auto pstEventLog = pUserDetail->GetEventLog()->GetLastEventLog();
        CHECK_NULL( pstEventLog );

        pTrans->HandleEventLog(pstEventLog);
    }
    else if(!IsGetFinish())
    {
        NFTransGetEventLog* pTrans = (NFTransGetEventLog*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_EVENT_LOG_ID);
        CHECK_EXPR(pTrans, -1, "Create Msg Trans Failed! UsedItem:{}", NFTransGetEventLog::GetUsedCount());

        pTrans->Init(pUserDetail, 0, 0);

        pTrans->GetAllEventLog(pUserDetail->GetUserId());
    }

    return 0;
}


int NFUserEventLog::HandleEventLog(NFUserDetail *pPlayer, uint64_t eventId)
{
    CHECK_NULL(pPlayer && pPlayer->GetEventLog());
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, pPlayer->GetUserId(), "--begin handle event id:{}", eventId);

    proto_ff_s::tbEventLog_s *pstEventLog = pPlayer->GetEventLog()->GetEventLog(eventId);
    CHECK_NULL( pstEventLog );

    proto_ff_s::tbEventLog_s stEventLog = *pstEventLog;

    pPlayer->GetEventLog()->OnHandleEventLog(eventId, true);

    return HandleEventLog(pPlayer, stEventLog);
}

int NFUserEventLog::HandleEventLog(NFUserDetail *pPlayer, const proto_ff_s::tbEventLog_s& stEventLog)
{
    CHECK_NULL(pPlayer && pPlayer->GetEventLog());

    int iRetCode = 0;
    switch (stEventLog.data.event_type) {
        case proto_ff::EN_EVENTLOG_GIVE_BANK_JETTON:
        {
            break;
        }
        default:
        {
            iRetCode = -1;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "eventid:{} userid:{} eventtype:{} not handle", stEventLog.event_id, stEventLog.user_id, stEventLog.data.event_type);
            break;
        }
    }
    return iRetCode;
}