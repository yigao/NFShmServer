// -------------------------------------------------------------------------
//    @FileName         :    NFProxySession.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxySession
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFPackageMng.h"

#define MAX_GATE_TIME_MSEC 120000

class NFProxySession
{
public:
    NFProxySession()
    {
        m_linkId = 0;
        m_playerId = 0;
        m_lastHeartBeatTime = 0;
        m_port = 0;
        m_timeOut = 0;
        m_lastActiveTime = 0;
    }

    virtual ~NFProxySession()
    {
    }

    uint64_t GetLinkId() const;

    void SetLinkId(uint64_t mLinkId);

    uint64_t GetPlayerId() const;

    void SetPlayerId(uint64_t playerId);

    const string &GetIpAddr() const;

    void SetIpAddr(const string &mIpAddr);

    uint32_t GetPort() const;

    void SetPort(uint32_t mPort);

    uint64_t GetLastHeartBeatTime() const;

    void SetLastHeartBeatTime(uint64_t mLastHeartBeatTime);

    uint64_t GetLastActiveTime() const;

    void SetLastActiveTime(uint64_t mLastActiveTime);

    uint32_t GetTimeOut() const;

    void SetTimeOut(uint32_t mTimeOut);

public:
    int CheckPkgRate(NFPackageConfig* pConfig, int iMsgID, int &count, int &interval);

    int AddPkgStatistic(int iMsgID, uint64_t roleID, uint64_t linkId);
private:
    uint64_t m_linkId;
    uint64_t m_playerId;
    std::string m_ipAddr;
    uint32_t m_port;
    uint64_t m_lastHeartBeatTime;
    uint64_t m_lastActiveTime;
    uint32_t m_timeOut;
    NFPackageMng m_packageMng;
};