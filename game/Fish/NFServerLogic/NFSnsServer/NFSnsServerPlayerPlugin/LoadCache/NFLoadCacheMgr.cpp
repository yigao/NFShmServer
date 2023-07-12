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
#include "Trans/NFTransGetRoleSimple.h"
#include "Trans/NFTransGetRoleDetail.h"
#include "Trans/NFTransCacheBase.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFLoadCacheMgr, EOT_SNS_LOAD_CACHE_MGR_ID, NFShmObj)

NFLoadCacheMgr::NFLoadCacheMgr() : NFShmObj()
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
    return 0;
}

int NFLoadCacheMgr::RefreshSimpleQueue()
{
    uint64_t timeNow = NFTime::Now().UnixSec();

    for (auto loadIter = m_playerSimpleLoadingMap.begin(); loadIter != m_playerSimpleLoadingMap.end();)
    {
        auto pInfo = &loadIter->second;
        if (pInfo->m_bFinished)
        {
            auto pLoadingData = &loadIter->second;
            // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
            for (auto iter = pLoadingData->m_transInfo.begin(); iter != pLoadingData->m_transInfo.end(); iter++)
            {
                if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
                {
                    NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                    if (pTransBase)
                    {
                        NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                        pTransRoleBase->HandleGetRoleSimpleRes(0, loadIter->first);
                    }
                }
            }

            for (auto iter = pLoadingData->m_rpcInfo.begin(); iter != pLoadingData->m_rpcInfo.end(); iter++)
            {
                if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
                {
                    FindModule<NFICoroutineModule>()->Resume(iter->first, 0);
                }
            }

            loadIter = m_playerSimpleLoadingMap.erase(loadIter);
            continue;
        }

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

    while (!m_playerSimpleLoadingMap.full() && !m_playerSimpleWaitLoadMap.empty() && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
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

        int retCode = TransGetRoleSimpleInfo(pNewLoading->m_playerId);
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

    while (!m_playerDetailLoadingMap.full() && !m_playerDetailWaitLoadMap.empty() && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
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

        int retCode = TransGetRoleDetailInfo(pNewLoading);
        if (retCode != 0)
        {
            return retCode;
        }
    }

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleSimpleRpcFinished(int iRunLogicRetCode, uint64_t roleId)
{
    if (iRunLogicRetCode == 0)
    {
        auto pLoadingData_iter = m_playerSimpleLoadingMap.find(roleId);
        if (pLoadingData_iter != m_playerSimpleLoadingMap.end())
        {
            pLoadingData_iter->second.m_bFinished = true;
        }
    }

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
            if (iter->first > 0 && (timeNow - iter->second) < DEFINE_RPC_SERVICE_TIME_OUT_MS)
            {
                FindModule<NFICoroutineModule>()->Resume(iter->first, iRunLogicRetCode);
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
        return RpcGetRoleSimpleInfo(playerId);
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
        && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_playerSimpleLoadingMap[playerId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = playerId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleSimpleInfo(playerId);
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

int NFLoadCacheMgr::TransGetRoleSimpleInfo(uint64_t playerId)
{
    NFTransGetRoleSimple *pTrans = (NFTransGetRoleSimple *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleSimple Failed! UsedItem:{}",
                   NFTransGetRoleSimple::GetUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

NFPlayerSimple* NFLoadCacheMgr::RpcGetRoleSimpleInfo(uint64_t playerId)
{
    CHECK_EXPR(FindModule<NFICoroutineModule>()->IsInCoroutine(), NULL, "Call RpcGetRoleSimpleInfo Must Int the Coroutine");

    proto_ff::tbFishPlayerData xData;
    xData.set_player_id(playerId);
    std::vector<std::string> vecFields = {"player_id", "nickname", "gender", "faceid", "phonenum", "age", "last_login_time"};
    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, playerId, xData, vecFields);
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
                proto_ff::pbFishPlayerSimpleData data;
                data.set_player_id(xData.player_id());
                data.set_nickname(xData.nickname());
                data.set_gender(xData.gender());
                data.set_faceid(xData.faceid());
                data.set_phonenum(xData.phonenum());
                data.set_age(xData.age());
                data.set_last_login_time(xData.last_login_time());
                pPlayerSimple->Init(data);
            }
        }
    }

    HandleGetRoleSimpleRpcFinished(0, playerId);
    return pPlayerSimple;
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
        pLoadingData_iter->second.AddTrans(transId, time);
        return 0;
    }

    if (!m_playerDetailLoadingMap.full() && m_playerDetailWaitLoadMap.empty()
        && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_playerDetailLoadingMap[roleId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = roleId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleDetailInfo(pRoleInfo);
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

int NFLoadCacheMgr::TransGetRoleDetailInfo(NFLoadCacheData *data)
{
    NFTransGetRoleDetail *pTrans = (NFTransGetRoleDetail *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_DETAIL_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleDetail Failed! UsedItem:{}",
                   NFTransGetRoleDetail::GetUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(data->m_playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->m_playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
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

        m_playerDetailLoadingMap.erase(roleId);
    }

    RefreshDetailQueue();

    return 0;
}

