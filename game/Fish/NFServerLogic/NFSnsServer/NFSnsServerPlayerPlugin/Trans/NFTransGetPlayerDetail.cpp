// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleDetail
//
// -------------------------------------------------------------------------

#include "NFTransGetPlayerDetail.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Cache/NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetPlayerDetail, EOT_SNS_TRANS_GET_ROLE_DETAIL_ID, NFTransBase)

NFTransGetPlayerDetail::NFTransGetPlayerDetail() : NFTransBase()
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

NFTransGetPlayerDetail::~NFTransGetPlayerDetail()
{
}

int NFTransGetPlayerDetail::CreateInit()
{
    m_playerId = 0;
    return 0;
}

int NFTransGetPlayerDetail::ResumeInit()
{
    return 0;
}

int NFTransGetPlayerDetail::QueryRole(uint64_t playerId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    m_playerId = playerId;

    auto pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(m_playerId);
    if (pRoleDetail)
    {
        SetFinished(0);
        return 0;
    }

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_EXPR_ASSERT(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER) Failed");

    proto_ff::tbFishSnsPlayerDetailData xData;
    xData.set_player_id(m_playerId);
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, m_playerId, xData, [this](int rpcRetCode, proto_ff::tbFishSnsPlayerDetailData &respone) {
        if (rpcRetCode == 0)
        {
            auto pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(m_playerId);
            if (pRoleDetail)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "the player:{} detail exist after selectobj, some wrong error", m_playerId);
                SetFinished(0);
                return;
            }

            pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerDetail(m_playerId);
            if (pRoleDetail == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "NFCacheMgr CreatePlayerDetail Failed");
                SetFinished(proto_ff::ERR_CODE_SVR_SYSTEM_ERROR);
                return;
            }

            if (!pRoleDetail->IsInited())
            {
                pRoleDetail->Init(respone);
            }

            SetFinished(0);
            return;
        }

        SetFinished(rpcRetCode);
    });

    if (m_rpcId == INVALID_ID)
    {
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransGetPlayerDetail::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleDetailTransFinished(iRunLogicRetCode, m_playerId);
    return 0;
}