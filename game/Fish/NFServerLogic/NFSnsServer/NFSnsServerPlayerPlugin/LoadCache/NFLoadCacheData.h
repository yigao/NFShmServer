// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheData.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheData
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmList.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

#define SNS_GET_PLAYER_SIMPLE_INFO_QUEUE 20000
#define SNS_GETTING_PLAYER_SIZE 300
#define SNS_CALLBACK_TRANS_RUN_TIMES 20

class NFLoadCacheData
{
public:
    NFLoadCacheData();

    virtual ~NFLoadCacheData();

    int CreateInit();

    int ResumeInit();

    NFLoadCacheData& operator=(const NFLoadCacheData& data)
    {
        if (this == &data)
            return *this;

        m_playerId = data.m_playerId;
        for(auto iter = data.m_transInfo.begin(); iter != data.m_transInfo.end(); iter++)
        {
            m_transInfo.emplace(iter->first, iter->second);
        }
        for(auto iter = data.m_rpcInfo.begin(); iter != data.m_rpcInfo.end(); iter++)
        {
            m_rpcInfo.emplace(iter->first, iter->second);
        }
        return *this;
    }
public:
    /**
     * @brief
     * @param rid
     * @param rtrans
     * @param rtime
     * @return
     */
    int AddTrans(int32_t transId, uint64_t time);

    /**
     * @brief 添加rpc
     * @param rpcId
     * @param time
     * @return
     */
    int AddRpc(int64_t rpcId, uint64_t time);
public:
    uint64_t m_playerId;
    NFShmHashMap<int32_t, uint64_t, SNS_CALLBACK_TRANS_RUN_TIMES> m_transInfo;
    NFShmHashMap<int64_t, uint64_t, SNS_CALLBACK_TRANS_RUN_TIMES> m_rpcInfo;
    bool m_bFinished;
};