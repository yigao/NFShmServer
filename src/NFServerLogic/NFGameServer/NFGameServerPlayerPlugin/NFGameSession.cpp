// -------------------------------------------------------------------------
//    @FileName         :    NFGameSession.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameSession.cpp
//
// -------------------------------------------------------------------------

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFGameSession.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameSession, EOT_GAME_PLAYER_ID, NFShmObj)

NFGameSession::NFGameSession()
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

NFGameSession::~NFGameSession()
{

}

int NFGameSession::CreateInit()
{
    m_playerId = 0;
    m_proxyId = 0;
    m_logicId = 0;
    m_gameId = 0;
    m_roomId = 0;
    m_deskId = INVALID_ID;
	m_chairId = INVALID_ID;
	m_isRobot = false;
    m_online = false;
	m_clearFlag = false;
	m_offlineTime = 0;
	m_lastMsgTime = 0;
    m_reservedTime = 0;
    m_reservedDeskId = INVALID_ID;
    m_reservedChairId = INVALID_ID;
    return 0;
}

int NFGameSession::ResumeInit()
{
    m_online = false;
    m_offlineTime = NFTime::Now().UnixSec();
    return 0;
}

int NFGameSession::SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::Proto_CSErrorRsp rspMsg;
	rspMsg.set_user_id(m_playerId);
	rspMsg.set_req_msg_id(nMsgId);
	rspMsg.set_error(errCode);

	NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, proto_ff::E_CS_ERROR, rspMsg, m_playerId);
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFGameSession::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData) {
	CHECK_EXPR(m_proxyId > 0, -1, "m_proxyId:{} error", m_proxyId);

	NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, nMsgId, xData, m_playerId);
	return 0;
}

int NFGameSession::SendMsgToClient(uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData)
{
	CHECK_EXPR(m_proxyId > 0, -1, "m_proxyId:{} error", m_proxyId);

	NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, nMainMsgId, nSubMsgId, xData, m_playerId);
	return 0;
}

int NFGameSession::SendMsgToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
	NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
		nMsgId, xData, playerId);
	return 0;
}

int NFGameSession::SendMsgToLogic(uint32_t nMsgId, const google::protobuf::Message &xData)
{
	NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_GAME_SERVER, m_logicId,
		nMsgId, xData);
	return 0;
}

int NFGameSession::SendMsgToSns(uint32_t nMsgId, const google::protobuf::Message &xData)
{
	NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, nMsgId, xData);
	return 0;
}

int NFGameSession::SendTransToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
	NFMessageMgr::Instance()->SendTransToWorldServer(NF_ST_GAME_SERVER,
		nMsgId, xData, req_trans_id, rsp_trans_id);
	return 0;
}

int NFGameSession::SendTransToLogic(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
	NFMessageMgr::Instance()->SendTransToLogicServer(NF_ST_GAME_SERVER, m_logicId,
		nMsgId, xData, req_trans_id, rsp_trans_id);
	return 0;
}

int NFGameSession::SendTransToSns(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

	NFMessageMgr::Instance()->SendTransToSnsServer(NF_ST_GAME_SERVER,
		nMsgId, xData, req_trans_id, rsp_trans_id);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

void NFGameSession::ClearGameData() {
    m_gameId = 0;
    m_roomId = 0;
    m_deskId = INVALID_ID;
    m_chairId = INVALID_ID;
}

