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

NFTransGetPlayerDetail::NFTransGetPlayerDetail()
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
    m_cid = 0;
    return 0;
}

int NFTransGetPlayerDetail::ResumeInit()
{
    return 0;
}

int NFTransGetPlayerDetail::QueryRole(uint64_t playerId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    m_cid = playerId;

    auto pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(m_cid);
    if (pRoleDetail)
    {
        SetFinished(0);
        return 0;
    }

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_EXPR_ASSERT(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER) Failed");

    proto_ff::RoleDBSnsDetail xData;
    xData.set_cid(m_cid);
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, m_cid, xData, [this](int rpcRetCode, proto_ff::RoleDBSnsDetail &respone) {
        if (rpcRetCode == 0)
        {
            auto pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(m_cid);
            if (pRoleDetail)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_cid, "the player:{} detail exist after selectobj, some wrong error", m_cid);
                SetFinished(0);
                return;
            }

            pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerDetail(m_cid);
            if (pRoleDetail == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_cid, "NFCacheMgr CreatePlayerDetail Failed");
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTransGetPlayerDetail::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleDetailTransFinished(iRunLogicRetCode, m_cid);
    return 0;
}