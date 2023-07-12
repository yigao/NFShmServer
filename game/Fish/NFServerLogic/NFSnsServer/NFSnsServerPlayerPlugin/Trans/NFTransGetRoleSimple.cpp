// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleRimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleRimple
//
// -------------------------------------------------------------------------

#include "NFTransGetRoleSimple.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "Cache/NFCacheMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetRoleSimple, EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID, NFTransBase)

NFTransGetRoleSimple::NFTransGetRoleSimple() : NFTransBase()
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

NFTransGetRoleSimple::~NFTransGetRoleSimple()
{
}

int NFTransGetRoleSimple::CreateInit()
{
    m_playerId = 0;
    return 0;
}

int NFTransGetRoleSimple::ResumeInit()
{
    return 0;
}

int NFTransGetRoleSimple::QueryRole(uint64_t playerId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    m_playerId = playerId;

    if (NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(m_playerId))
    {
        SetFinished(0);
        return 0;
    }

    proto_ff::tbFishPlayerData xData;
    xData.set_player_id(m_playerId);
    std::vector<std::string> vecFields = {"player_id", "nickname", "gender", "faceid", "phonenum", "age", "last_login_time"};
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_SNS_SERVER, m_playerId, xData, [this](int rpcRetCode, proto_ff::tbFishPlayerData &respone) {
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
                proto_ff::pbFishPlayerSimpleData data;
                data.set_player_id(respone.player_id());
                data.set_nickname(respone.nickname());
                data.set_gender(respone.gender());
                data.set_faceid(respone.faceid());
                data.set_phonenum(respone.phonenum());
                data.set_age(respone.age());
                data.set_last_login_time(respone.last_login_time());
                pPlayerSimple->Init(data);
            }

            SetFinished(0);
            return;
        }

        SetFinished(rpcRetCode);
    }, vecFields);

    if (m_rpcId == INVALID_ID)
    {
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransGetRoleSimple::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleSimpleTransFinished(iRunLogicRetCode, m_playerId);
    return 0;
}
