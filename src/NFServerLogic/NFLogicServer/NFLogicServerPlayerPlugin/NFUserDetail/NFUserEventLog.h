// -------------------------------------------------------------------------
//    @FileName         :    NFUserEventLog.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserEventLog.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFArray.h"

const int MAX_EVENT_LOG_NUM = 20;

class NFUserDetail;
class NFUserEventLog
{
public:
    NFUserEventLog();
    virtual ~NFUserEventLog();
    int CreateInit();
    int ResumeInit();
public:
    int AddEventLog(const proto_ff::tbEventLog& eventLog);
    int DelEventLog(uint64_t eventId);
    proto_ff_s::tbEventLog_s *GetEventLog(uint64_t eventId);
    proto_ff_s::tbEventLog_s *GetLastEventLog();

    bool IsGetFinish() { return m_bIsGetFinish; }
    void SetGetFinish( bool bSet ) { m_bIsGetFinish = bSet; }
    bool IsNeedHandle();
    int OnHandleEventLog( uint64_t ullEvenLogUid, bool bSuccess );
    void SetInHandleTrans( bool bSet ) { m_bIsInHandleTrans = bSet; }
    bool IsEventLogFull() { return m_astEventLog.IsFull(); }
    bool IsEventLogEmpty() { return m_astEventLog.GetSize() <= 0;}

    int Tick(NFUserDetail* pUserDetail);
public:
    static int HandleEventLog(NFUserDetail *pPlayer, uint64_t eventId);
    static int HandleEventLog(NFUserDetail *pPlayer, const proto_ff_s::tbEventLog_s& stEventLog);
private:
    bool m_bIsGetFinish;
    bool m_bIsInHandleTrans;
    uint64_t m_stLastHandleTime;
    NFArray<proto_ff_s::tbEventLog_s, MAX_EVENT_LOG_NUM> m_astEventLog;
};
