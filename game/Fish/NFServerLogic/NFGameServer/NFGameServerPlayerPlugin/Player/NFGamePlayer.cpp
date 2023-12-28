// -------------------------------------------------------------------------
//    @FileName         :    NFGamePlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGamePlayer
//
// -------------------------------------------------------------------------

#include "NFGamePlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

NFGamePlayer::NFGamePlayer()
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

NFGamePlayer::~NFGamePlayer()
{
}

int NFGamePlayer::CreateInit()
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

int NFGamePlayer::ResumeInit()
{
    m_online = false;
    m_offlineTime = NFTime::Now().UnixSec();
    return 0;
}

int NFGamePlayer::SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_CSErrorRsp rspMsg;
    rspMsg.set_user_id(m_playerId);
    rspMsg.set_req_msg_id(nMsgId);
    rspMsg.set_error(errCode);

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, proto_ff::E_CS_ERROR, rspMsg, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGamePlayer::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData) {
    CHECK_EXPR(m_proxyId > 0, -1, "m_proxyId:{} error", m_proxyId);

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, m_playerId);
    return 0;
}

int NFGamePlayer::SendMsgToClient(uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData)
{
    CHECK_EXPR(m_proxyId > 0, -1, "m_proxyId:{} error", m_proxyId);

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, m_proxyId, nMainMsgId, nSubMsgId, xData, m_playerId);
    return 0;
}

int NFGamePlayer::SendMsgToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                   nMsgId, xData, playerId);
    return 0;
}

int NFGamePlayer::SendMsgToLogic(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_GAME_SERVER, m_logicId,
                                                   nMsgId, xData, m_playerId);
    return 0;
}

int NFGamePlayer::SendMsgToSns(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_GAME_SERVER, nMsgId, xData, m_playerId);
    return 0;
}

int NFGamePlayer::SendTransToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_GAME_SERVER,
                                                     nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFGamePlayer::SendTransToLogic(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_GAME_SERVER, m_logicId,
                                                     nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFGamePlayer::SendTransToSns(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    FindModule<NFIServerMessageModule>()->SendTransToSnsServer(NF_ST_GAME_SERVER,
                                                   nMsgId, xData, req_trans_id, rsp_trans_id);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

void NFGamePlayer::ClearGameData() {
    m_gameId = 0;
    m_roomId = 0;
    m_deskId = INVALID_ID;
    m_chairId = INVALID_ID;
}