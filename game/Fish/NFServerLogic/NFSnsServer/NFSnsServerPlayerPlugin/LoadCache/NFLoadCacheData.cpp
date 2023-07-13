// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheData.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheData
//
// -------------------------------------------------------------------------

#include "NFLoadCacheData.h"

NFLoadCacheData::NFLoadCacheData()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFLoadCacheData::~NFLoadCacheData()
{
}

int NFLoadCacheData::CreateInit()
{
    m_playerId = 0;
    m_transInfo.CreateInit();
    m_bFinished = false;
    return 0;
}

int NFLoadCacheData::ResumeInit()
{
    return 0;
}

int NFLoadCacheData::AddTrans(int transId, uint64_t time)
{
    if (transId > 0) {
        auto iter = m_transInfo.find(transId);
        if (iter != m_transInfo.end())
        {
            return 0;
        }
    }

    if (!m_transInfo.full()) {
        m_transInfo.emplace(transId, time);
    } else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get role info trans cache full:{} {}", m_playerId, m_transInfo.size());
        return -1;
    }

    return 0;
}

int NFLoadCacheData::AddRpc(int64_t rpcId, uint64_t time)
{
    if (rpcId > 0) {
        auto iter = m_rpcInfo.find(rpcId);
        if (iter != m_rpcInfo.end())
        {
            return 0;
        }
    }

    if (!m_rpcInfo.full()) {
        m_rpcInfo.emplace(rpcId, time);
    } else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get role info rpc cache full:{} {}", m_playerId, m_transInfo.size());
        return -1;
    }

    return 0;
}
