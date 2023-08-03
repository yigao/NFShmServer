// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleRimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleRimple
//
// -------------------------------------------------------------------------

#include "NFTransGetPlayerSimple.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "Cache/NFCacheMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetPlayerSimple, EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID, NFTransBase)

NFTransGetPlayerSimple::NFTransGetPlayerSimple() : NFTransBase()
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

NFTransGetPlayerSimple::~NFTransGetPlayerSimple()
{
}

int NFTransGetPlayerSimple::CreateInit()
{
    m_playerId = 0;
    return 0;
}

int NFTransGetPlayerSimple::ResumeInit()
{
    return 0;
}

int NFTransGetPlayerSimple::QueryRole(uint64_t playerId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    m_playerId = playerId;

    if (NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(m_playerId))
    {
        SetFinished(0);
        return 0;
    }

    proto_ff::tbFishSnsPlayerSimpleData xData;
    xData.set_player_id(m_playerId);
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, m_playerId, xData, [this](int rpcRetCode, proto_ff::tbFishSnsPlayerSimpleData &respone) {
        if (rpcRetCode == 0)
        {
            NFPlayerSimple* pPlayerSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(m_playerId);
            if (pPlayerSimple)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "the player:{} simple exist after selectobj, some wrong error", m_playerId);
                SetFinished(0);
                return;
            }

            pPlayerSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerSimple(m_playerId);
            if (pPlayerSimple == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "NFCacheMgr CreatePlayerSimple Failed");
                SetFinished(proto_ff::ERR_CODE_SVR_SYSTEM_ERROR);
                return;
            }

            if (!pPlayerSimple->IsInited())
            {
                pPlayerSimple->Init(respone);
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

int NFTransGetPlayerSimple::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleSimpleTransFinished(iRunLogicRetCode, m_playerId);
    return 0;
}
