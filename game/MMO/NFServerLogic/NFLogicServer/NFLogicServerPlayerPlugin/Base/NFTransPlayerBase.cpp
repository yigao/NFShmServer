// -------------------------------------------------------------------------
//    @FileName         :    NFTransPlayerBase.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransPlayerBase
//
// -------------------------------------------------------------------------

#include <proto_svr_logic_error.pb.h>
#include "NFTransPlayerBase.h"

#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFICommLogicModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransPlayerBase, EOT_TRANS_LOGIC_PLAYER_BASE, NFTransBase)

NFTransPlayerBase::NFTransPlayerBase() : NFTransBase()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransPlayerBase::~NFTransPlayerBase()
{

}

int NFTransPlayerBase::CreateInit()
{
    m_uid = 0;
    m_roleId = 0;
    m_cmd = 0;
    m_fromBusId = 0;
    m_bHasIncreasedCount = false;
    m_reqTransId = 0;
    return 0;
}

int NFTransPlayerBase::ResumeInit()
{
    return 0;
}

int NFTransPlayerBase::Init(uint64_t roleId, uint64_t uid, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
    m_uid = uid;
    return Init(roleId, cmd, fromBusId, reqTransId);
}

int NFTransPlayerBase::Init(uint64_t roleId, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
    m_roleId = roleId;
    m_cmd = cmd;
    m_fromBusId = fromBusId;
    m_reqTransId = reqTransId;

    if (!m_bHasIncreasedCount)
    {
        NFPlayer *pPlayer = GetPlayer();
        if (pPlayer)
        {
            pPlayer->IncreaseTransNum();
            m_bHasIncreasedCount = true;
        }
    }
    return 0;
}

int NFTransPlayerBase::Init(NFPlayer *pPlayer, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
    CHECK_NULL(pPlayer);

    m_uid = pPlayer->GetUid();
    m_roleId = pPlayer->GetCid();
    m_cmd = cmd;
    m_fromBusId = fromBusId;
    m_reqTransId = reqTransId;

    if (!m_bHasIncreasedCount)
    {
        pPlayer->IncreaseTransNum();
        m_bHasIncreasedCount = true;
    }
    return 0;
}

NFPlayer *NFTransPlayerBase::GetPlayer()
{
    return NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(m_roleId);
}

int NFTransPlayerBase::OnTimeOut()
{
    NFPlayer *pPlayer = GetPlayer();
    if (pPlayer && m_bHasIncreasedCount)
    {
        pPlayer->DecreaseTransNum();
        m_bHasIncreasedCount = false;
    }

    SetFinished(proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT);

    NFLogError(NF_LOG_SYSTEMLOG, m_uid, "NFTransPlayerBase timeout, playerId:{}, roleId:{} cmd:{}, transid:{}",
               m_uid, m_roleId, m_cmd, m_reqTransId);
    return 0;
}

int NFTransPlayerBase::OnTransFinished(int iRunLogicRetCode)
{
    NFPlayer *pPlayer = GetPlayer();
    if (!pPlayer)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, m_uid, "GetPlayerByUid, this player may off line! cmd:{}", m_cmd);
        return 0;
    }

    if (m_bHasIncreasedCount)
    {
        pPlayer->DecreaseTransNum();
        m_bHasIncreasedCount = false;
    }

    if (0 == iRunLogicRetCode)
    {
        return 0;
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, m_uid, "playerId:{} roleId:{} failed errcode={}, msgid={} globalid={} classtype:{}", m_uid, m_roleId,
               iRunLogicRetCode, m_cmd, GetGlobalID(), GetClassType());

    if (0 == m_cmd)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid,
                   "Server should not call this function because request head uninitialized, playerId:{} roleId:{}", m_uid, m_roleId);

        return -1;
    }

    if (iRunLogicRetCode && iRunLogicRetCode != -1)
    {
        //pPlayer->SendErrToClient(m_cmd, (proto_ff::Proto_CS_ErrorCode)iRunLogicRetCode);
    }

    return 0;
}

std::string NFTransPlayerBase::DebugString() const
{
    return NF_FORMAT("uid:{} roleId:{} cmd:{} NFTransBase:{}", m_uid, m_roleId, m_cmd, NFTransBase::DebugString());
}
