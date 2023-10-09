// -------------------------------------------------------------------------
//    @FileName         :    NFLoginQueue.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/13
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginQueue
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"

class NFLoginQueue
{
public:
    NFLoginQueue();

    virtual ~NFLoginQueue();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetUid() const;

    void SetUid(uint64_t playerId);

    uint64_t GetLastReqTime() const;

    void SetLastReqTime(uint64_t lastReqTime);

private:

    /**
     * @brief 上一次请求排队名次的时间
     */
    uint64_t m_lastReqTime;

    /**
     * @brief 排队玩家UID
     */
    uint64_t m_uid;
};