// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransGamePlayerBase.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"

#include "NFGameSession.h"
#include "NFGameSessionMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGamePlayerBase, EOT_TRANS_GAME_PLAYER_BASE, NFTransBase)

NFTransGamePlayerBase::NFTransGamePlayerBase() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransGamePlayerBase::~NFTransGamePlayerBase() {

}

int NFTransGamePlayerBase::CreateInit() {
	m_playerId = 0;
	m_cmd = 0;
	m_fromBusId = 0;
	m_bHasIncreasedCount = false;
	return 0;
}

int NFTransGamePlayerBase::ResumeInit() {
	return 0;
}

int NFTransGamePlayerBase::Init(uint64_t playerId, uint32_t cmd, uint32_t fromBusId) {
	m_playerId = playerId;
	m_cmd = cmd;
	m_fromBusId = fromBusId;
	return 0;
}

int NFTransGamePlayerBase::Init(NFGameSession* pPlayer, uint32_t cmd, uint32_t fromBusId)
{
	CHECK_NULL(pPlayer);

	m_playerId = pPlayer->GetPlayerId();
	m_cmd = cmd;
	m_fromBusId = fromBusId;

	return 0;
}

NFGameSession *NFTransGamePlayerBase::GamePlayer()
{
	NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(m_playerId);

	return pPlayer;
}

int NFTransGamePlayerBase::OnTimeOut()
{
	SetFinished(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

	return 0;
}

int NFTransGamePlayerBase::HandleTransFinished(int iRunLogicRetCode)
{
	return 0;
}

int NFTransGamePlayerBase::OnTransFinished(int iRunLogicRetCode)
{
	NFGameSession * pPlayer = GamePlayer();
	if (!pPlayer)
	{
		NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get Game Player Failed, this user may off line!");
		return 0;
	}

	if (0 == iRunLogicRetCode)
	{
		return 0;
	}

	NFLogDebug(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(), "user:{} failed errcode={}, msgid={} globalid={} classtype:{}", pPlayer->GetPlayerId(), iRunLogicRetCode, m_cmd, GetGlobalID(), GetClassType());

	if (0 == m_cmd)
	{
		NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(),
			"Server should not call this function because request head uninitialized, userId:{}!", pPlayer->GetPlayerId());

		return -1;
	}

	if (iRunLogicRetCode > 0)
	{
		int iRet = pPlayer->SendErrToClient(m_cmd, (proto_ff::Proto_CS_ErrorCode)iRunLogicRetCode);
		CHECK_PLAYER_RET(pPlayer->GetPlayerId(), iRet, "Send Message to userId:{} failed.", pPlayer->GetPlayerId());
	}

	return 0;
}