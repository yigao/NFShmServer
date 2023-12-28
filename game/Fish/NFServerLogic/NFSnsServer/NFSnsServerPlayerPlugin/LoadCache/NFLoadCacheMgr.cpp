// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheMgr
//
// -------------------------------------------------------------------------

#include "NFLoadCacheMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "Cache/NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Trans/NFQueryRole.h"
#include "Trans/NFTransGetPlayerSimple.h"
#include "Trans/NFTransGetPlayerDetail.h"
#include "Trans/NFTransCacheBase.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

NFLoadCacheMgr::NFLoadCacheMgr()
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

NFLoadCacheMgr::~NFLoadCacheMgr()
{
}

int NFLoadCacheMgr::CreateInit()
{
    flag = true;

    m_refreshTimer = SetTimer(100, 0, 0, 0, 1, 0);
    m_refreshRpcTimer = SetTimer(30, 0, 0, 0, 1, 0);
    return 0;
}

int NFLoadCacheMgr::ResumeInit()
{
    return 0;
}

int NFLoadCacheMgr::OnTimer(int timeId, int callcount)
{
    if (timeId == m_refreshTimer)
    {
        RefreshSimpleQueue();
        RefreshDetailQueue();
    }
    else if (timeId == m_refreshRpcTimer)
    {
        RefreshRpcQueue();
    }
    return 0;
}

int NFLoadCacheMgr::RefreshRpcQueue()
{
    for(auto iter = m_waitResumeRpcMap.begin(); iter != m_waitResumeRpcMap.end(); )
    {
        FindModule<NFICoroutineModule>()->Resume(iter->first, iter->second);
        iter = m_waitResumeRpcMap.erase(iter);
    }

    return 0;
}

int NFLoadCacheMgr::RefreshSimpleQueue()
{
    uint64_t timeNow = NFTime::Now().UnixSec();

    for (auto loadIter = m_playerSimpleLoadingMap.begin(); loadIter != m_playerSimpleLoadingMap.end();)
    {
        auto pInfo = &loadIter->second;

        for (auto roleIter = pInfo->m_transInfo.begin(); roleIter != pInfo->m_transInfo.end();)
        {
            if ((timeNow - roleIter->second) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        for (auto roleIter = pInfo->m_rpcInfo.begin(); roleIter != pInfo->m_rpcInfo.end();)
        {
            if ((timeNow - roleIter->second) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_rpcInfo.erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.empty() && pInfo->m_rpcInfo.empty())
        {
            loadIter = m_playerSimpleLoadingMap.erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_playerSimpleLoadingMap.full() && !m_playerSimpleWaitLoadMap.empty() && NFTransGetPlayerSimple::GetStaticFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_playerSimpleWaitLoadMap.begin();
        auto pWaitLoadData = &waitIter->second;
        CHECK_EXPR_ASSERT(pWaitLoadData, -1, "m_roleWaitLoadMap Begin Failed");

        NFLoadCacheData* pNewLoading = NULL;
        auto pNewLoading_iter = m_playerSimpleLoadingMap.find(pWaitLoadData->m_playerId);
        if (pNewLoading_iter == m_playerSimpleLoadingMap.end())
        {
            pNewLoading = &m_playerSimpleLoadingMap[pWaitLoadData->m_playerId];
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_playerId);
        }
        else {
            pNewLoading = &pNewLoading_iter->second;
        }

        *pNewLoading = *pWaitLoadData;
        m_playerSimpleWaitLoadMap.erase(waitIter);

        int retCode = TransGetPlayerSimpleInfo(pNewLoading->m_playerId);
        if (retCode != 0)
        {
            return retCode;
        }
    }

    return 0;
}

int NFLoadCacheMgr::RefreshDetailQueue()
{
    uint64_t timeNow = NFTime::Now().UnixSec();

    for (auto loadIter = m_playerDetailLoadingMap.begin(); loadIter != m_playerDetailLoadingMap.end();)
    {
        auto pInfo = &loadIter->second;
        for (auto roleIter = pInfo->m_transInfo.begin(); roleIter != pInfo->m_transInfo.end();)
        {
            if ((timeNow - roleIter->second) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.empty())
        {
            loadIter = m_playerDetailLoadingMap.erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_playerDetailLoadingMap.full() && !m_playerDetailWaitLoadMap.empty() && NFTransGetPlayerDetail::GetStaticFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_playerDetailWaitLoadMap.begin();
        auto pWaitLoadData = &waitIter->second;

        NFLoadCacheData* pNewLoading = NULL;
        auto pNewLoading_iter = m_playerDetailLoadingMap.find(pWaitLoadData->m_playerId);
        if (pNewLoading_iter == m_playerDetailLoadingMap.end())
        {
            pNewLoading = &m_playerDetailLoadingMap[pWaitLoadData->m_playerId];
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_playerId);
        }
        else {
            pNewLoading = &pNewLoading_iter->second;
        }

        *pNewLoading = *pWaitLoadData;
        m_playerDetailWaitLoadMap.erase(waitIter);

        int retCode = TransGetRoleDetailInfo(pNewLoading->m_playerId);
        if (retCode != 0)
        {
            return retCode;
        }
    }

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleSimpleRpcFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_playerSimpleLoadingMap.find(roleId);
    if (pLoadingData_iter != m_playerSimpleLoadingMap.end())
    {
        auto pLoadingData = &pLoadingData_iter->second;
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData->m_transInfo.begin(); iter != pLoadingData->m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleSimpleRes(iRunLogicRetCode, roleId);
                }
            }
        }

        for (auto iter = pLoadingData->m_rpcInfo.begin(); iter != pLoadingData->m_rpcInfo.end(); iter++)
        {
            if (iter->first > 0)
            {
                if (m_waitResumeRpcMap.find(iter->first) != m_waitResumeRpcMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the rpc is in the m_waitResumeRpcMap, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                }
                else {
                    if (m_waitResumeRpcMap.full())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the m_waitResumeRpcMap full, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                    }
                    else {
                        m_waitResumeRpcMap.emplace(iter->first, iRunLogicRetCode);
                    }
                }
            }
        }

        m_playerSimpleLoadingMap.erase(roleId);
    }

    RefreshSimpleQueue();

    return 0;
}


int NFLoadCacheMgr::HandleGetRoleSimpleTransFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_playerSimpleLoadingMap.find(roleId);
    if (pLoadingData_iter != m_playerSimpleLoadingMap.end())
    {
        auto pLoadingData = &pLoadingData_iter->second;
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData->m_transInfo.begin(); iter != pLoadingData->m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleSimpleRes(iRunLogicRetCode, roleId);
                }
            }
        }

        for (auto iter = pLoadingData->m_rpcInfo.begin(); iter != pLoadingData->m_rpcInfo.end(); iter++)
        {
            if (iter->first > 0)
            {
                if (m_waitResumeRpcMap.find(iter->first) != m_waitResumeRpcMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the rpc is in the m_waitResumeRpcMap, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                }
                else {
                    if (m_waitResumeRpcMap.full())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the m_waitResumeRpcMap full, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                    }
                    else {
                        m_waitResumeRpcMap.emplace(iter->first, iRunLogicRetCode);
                    }
                }
            }
        }

        m_playerSimpleLoadingMap.erase(roleId);
    }

    RefreshSimpleQueue();

    return 0;
}

NFPlayerSimple* NFLoadCacheMgr::GetPlayerSimpleInfoByRpc(uint64_t playerId, uint64_t time)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call GetPlayerSimpleInfoByRpc Must Int the Coroutine");
    CHECK_EXPR(playerId > 0, NULL, "playerId:{} error", playerId);

    int64_t rpcId = FindModule<NFICoroutineModule>()->CurrentTaskId();

    auto pLoadingData = m_playerSimpleLoadingMap.find(playerId);
    if (pLoadingData != m_playerSimpleLoadingMap.end())
    {
        int iRet = pLoadingData->second.AddRpc(rpcId, time);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "AddRpc error, iRet:{}", GetErrorStr(iRet));
            return NULL;
        }

        iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "NFICoroutineModule yield error, iRet:{}", GetErrorStr(iRet));
        }

        return NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(playerId);
    }

    if (!m_playerSimpleLoadingMap.full() && m_playerSimpleWaitLoadMap.empty())
    {
        auto pRoleInfo = &m_playerSimpleLoadingMap[playerId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = playerId;
        //这里不需要存储当前rpc
        pRoleInfo->AddRpc(-1, time);
        return RpcGetPlayerSimpleInfo(playerId);
    }

    return NULL;
}

NFPlayerDetail* NFLoadCacheMgr::GetPlayerDetailInfoByRpc(uint64_t playerId, uint64_t time)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call GetPlayerDetailInfoByRpc Must Int the Coroutine");
    CHECK_EXPR(playerId > 0, NULL, "playerId:{} error", playerId);

    int64_t rpcId = FindModule<NFICoroutineModule>()->CurrentTaskId();

    auto pLoadingData = m_playerDetailLoadingMap.find(playerId);
    if (pLoadingData != m_playerDetailLoadingMap.end())
    {
        int iRet = pLoadingData->second.AddRpc(rpcId, time);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "AddRpc error, iRet:{}", GetErrorStr(iRet));
            return NULL;
        }

        iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "NFICoroutineModule yield error, iRet:{}", GetErrorStr(iRet));
        }

        return NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    }

    if (!m_playerDetailLoadingMap.full() && m_playerDetailWaitLoadMap.empty())
    {
        auto pRoleInfo = &m_playerDetailLoadingMap[playerId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = playerId;
        //这里不需要存储当前rpc
        pRoleInfo->AddRpc(-1, time);
        return RpcGetPlayerDetailInfo(playerId);
    }

    return NULL;
}

int NFLoadCacheMgr::GetPlayerSimpleInfo(uint64_t playerId, int transId, uint64_t time)
{
    if (playerId <= 0)
        return 0;

    if (transId <= 0)
    {
        transId = -1;
    }

    auto pLoadingData = m_playerSimpleLoadingMap.find(playerId);
    if (pLoadingData != m_playerSimpleLoadingMap.end())
    {
        return pLoadingData->second.AddTrans(transId, time);
    }

    if (!m_playerSimpleLoadingMap.full() && m_playerSimpleWaitLoadMap.empty()
        && NFTransGetPlayerSimple::GetStaticFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_playerSimpleLoadingMap[playerId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = playerId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetPlayerSimpleInfo(playerId);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        auto pstFind_iter = m_playerSimpleWaitLoadMap.find(playerId);
        if (pstFind_iter != m_playerSimpleWaitLoadMap.end())
        {
            if (pstFind_iter->second.AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_playerSimpleWaitLoadMap.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = &m_playerSimpleWaitLoadMap[playerId];
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_sRoleStatic Insert Failed, roleId:{}", playerId);
                return -1;
            }

            pTmpData->m_playerId = playerId;
            if (pTmpData->AddTrans(transId, time))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFLoadCacheData AddTrans Failed, roleId:{}", playerId);
                return -1;
            }
        }
    }

    return 0;
}

int NFLoadCacheMgr::GetCheckedRoleSimpleInfo(uint64_t playerId)
{
    NFPlayerSimple *pSimple = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(playerId);
    if(pSimple)
    {
        NFPlayerDetail* pDetail = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
        if(pDetail)
        {
            return 0;
        }
        else
        {
            return GetPlayerDetailInfo(playerId, 0, NFTime::Now().UnixSec());
        }
    }

    return GetPlayerSimpleInfo(playerId, 0, NFTime::Now().UnixSec());
}

int NFLoadCacheMgr::TransGetPlayerSimpleInfo(uint64_t playerId)
{
    NFTransGetPlayerSimple *pTrans = (NFTransGetPlayerSimple *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleSimple Failed! UsedItem:{}",
                   NFTransGetPlayerSimple::GetStaticUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

NFPlayerSimple* NFLoadCacheMgr::RpcGetPlayerSimpleInfo(uint64_t playerId, bool bCreatePlayer)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call RpcGetPlayerSimpleInfo Must Int the Coroutine");

    proto_ff::tbFishSnsPlayerSimpleData xData;
    xData.set_player_id(playerId);
    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, playerId, xData);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "GetRpcSelectObjService Failed, iRet:{}", GetErrorStr(iRet));
        return NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(playerId);
    }

    NFPlayerSimple* pPlayerSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(playerId);
    if (pPlayerSimple)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "the player:{} simple exist after selectobj, some wrong error", playerId);
    }
    else {
        pPlayerSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerSimple(playerId);
        if (pPlayerSimple == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFCacheMgr CreatePlayerSimple Failed");
            return NULL;
        }
        else {
            if (!pPlayerSimple->IsInited())
            {
                pPlayerSimple->Init(xData, bCreatePlayer);
            }
        }
    }

    HandleGetRoleSimpleRpcFinished(0, playerId);
    return pPlayerSimple;
}

NFPlayerSimple* NFLoadCacheMgr::CreatePlayerSimpleDBDataByRpc(const proto_ff::tbFishSnsPlayerSimpleData& dbData)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call RpcGetPlayerSimpleInfo Must Int the Coroutine");

    int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_SNS_SERVER, dbData.player_id(), dbData);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, dbData.player_id(), "GetRpcInsertObjService Failed, iRet:{}", GetErrorStr(iRet));
        return NULL;
    }

    return RpcGetPlayerSimpleInfo(dbData.player_id(), true);
}

NFPlayerDetail* NFLoadCacheMgr::CreatePlayerDetailDBDataByRpc(const proto_ff::tbFishSnsPlayerDetailData& dbData)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call RpcGetPlayerSimpleInfo Must Int the Coroutine");

    int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_SNS_SERVER, dbData.player_id(), dbData);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, dbData.player_id(), "GetRpcInsertObjService Failed, iRet:{}", GetErrorStr(iRet));
        return NULL;
    }

    return RpcGetPlayerDetailInfo(dbData.player_id(), true);
}

int NFLoadCacheMgr::GetPlayerDetailInfo(uint64_t roleId, int transId, uint32_t time)
{
    if (roleId <= 0)
        return 0;

    if (transId <= 0)
    {
        transId = -1;
    }

    auto pLoadingData_iter = m_playerDetailLoadingMap.find(roleId);
    if (pLoadingData_iter != m_playerDetailLoadingMap.end())
    {
        return pLoadingData_iter->second.AddTrans(transId, time);
    }

    if (!m_playerDetailLoadingMap.full() && m_playerDetailWaitLoadMap.empty()
        && NFTransGetPlayerDetail::GetStaticFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_playerDetailLoadingMap[roleId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = roleId;
        if (pRoleInfo->AddTrans(transId, time) != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "pRoleInfo->AddTrans(transId, time) Failed");
            return -1;
        }

        int retCode = TransGetRoleDetailInfo(pRoleInfo->m_playerId);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        auto pstFind_iter = m_playerDetailWaitLoadMap.find(roleId);
        if (pstFind_iter != m_playerDetailWaitLoadMap.end())
        {
            if (pstFind_iter->second.AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_playerDetailWaitLoadMap.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = &m_playerDetailWaitLoadMap[roleId];
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap Insert Failed, roleId:{}", roleId);
                return -1;
            }

            pTmpData->m_playerId = roleId;
            if (pTmpData->AddTrans(transId, time))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFLoadCacheData AddTrans Failed, roleId:{}", roleId);
                return -1;
            }
        }
    }

    return 0;
}

int NFLoadCacheMgr::TransGetRoleDetailInfo(uint64_t playerId)
{
    NFTransGetPlayerDetail *pTrans = (NFTransGetPlayerDetail *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_DETAIL_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleDetail Failed! UsedItem:{}",
                   NFTransGetPlayerDetail::GetStaticUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

NFPlayerDetail* NFLoadCacheMgr::RpcGetPlayerDetailInfo(uint64_t playerId, bool bCreatePlayer)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call RpcGetPlayerDetailInfo Must Int the Coroutine");

    proto_ff::tbFishSnsPlayerDetailData xData;
    xData.set_player_id(playerId);
    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, playerId, xData);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "GetRpcSelectObjService Failed, iRet:{}", GetErrorStr(iRet));
        return NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    }

    NFPlayerDetail* pPlayerDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    if (pPlayerDetail)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "the player:{} detail exist after selectobj, some wrong error", playerId);
    }
    else {
        pPlayerDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerDetail(playerId);
        if (pPlayerDetail == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFCacheMgr GetPlayerDetail Failed");
            return NULL;
        }
        else {
            if (!pPlayerDetail->IsInited())
            {
                pPlayerDetail->Init(xData, bCreatePlayer);
            }
        }
    }

    HandleGetRoleDetailRpcFinished(0, playerId);
    return pPlayerDetail;
}

int NFLoadCacheMgr::HandleGetRoleDetailTransFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_playerDetailLoadingMap.find(roleId);
    if (pLoadingData_iter != m_playerDetailLoadingMap.end())
    {
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData_iter->second.m_transInfo.begin(); iter != pLoadingData_iter->second.m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleDetailRes(iRunLogicRetCode, roleId);
                }
            }
        }

        for (auto iter = pLoadingData_iter->second.m_rpcInfo.begin(); iter != pLoadingData_iter->second.m_rpcInfo.end(); iter++)
        {
            if (iter->first > 0)
            {
                if (m_waitResumeRpcMap.find(iter->first) != m_waitResumeRpcMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the rpc is in the m_waitResumeRpcMap, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                }
                else {
                    if (m_waitResumeRpcMap.full())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the m_waitResumeRpcMap full, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                    }
                    else {
                        m_waitResumeRpcMap.emplace(iter->first, iRunLogicRetCode);
                    }
                }
            }
        }

        m_playerDetailLoadingMap.erase(roleId);
    }

    RefreshDetailQueue();

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleDetailRpcFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_playerDetailLoadingMap.find(roleId);
    if (pLoadingData_iter != m_playerDetailLoadingMap.end())
    {
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData_iter->second.m_transInfo.begin(); iter != pLoadingData_iter->second.m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleDetailRes(iRunLogicRetCode, roleId);
                }
            }
        }

        for (auto iter = pLoadingData_iter->second.m_rpcInfo.begin(); iter != pLoadingData_iter->second.m_rpcInfo.end(); iter++)
        {
            if (iter->first > 0)
            {
                if (m_waitResumeRpcMap.find(iter->first) != m_waitResumeRpcMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the rpc is in the m_waitResumeRpcMap, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                }
                else {
                    if (m_waitResumeRpcMap.full())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the m_waitResumeRpcMap full, playerId:{} rpc:{} ", pLoadingData_iter->first, iter->first)
                    }
                    else {
                        m_waitResumeRpcMap.emplace(iter->first, iRunLogicRetCode);
                    }
                }
            }
        }

        m_playerDetailLoadingMap.erase(roleId);
    }

    RefreshDetailQueue();

    return 0;
}

