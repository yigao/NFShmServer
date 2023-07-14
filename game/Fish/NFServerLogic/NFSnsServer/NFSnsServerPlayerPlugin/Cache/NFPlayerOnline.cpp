// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerOnline.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerOnline
//
// -------------------------------------------------------------------------

#include "NFPlayerOnline.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerOnline, EOT_PLAYER_ONLINE_ID, NFShmObj)

NFPlayerOnline::NFPlayerOnline()
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

NFPlayerOnline::~NFPlayerOnline()
{
}

int NFPlayerOnline::CreateInit()
{
    return 0;
}

int NFPlayerOnline::ResumeInit()
{
    m_proxyId = 0;
    m_gameId = 0;
    m_logicId = 0;
    m_isOnline = false;
    return 0;
}

uint64_t NFPlayerOnline::GetPlayerId() const
{
    return m_playerId;
}

void NFPlayerOnline::SetPlayerId(uint64_t playerId)
{
    m_playerId = playerId;
}

uint32_t NFPlayerOnline::GetProxyId() const
{
    return m_proxyId;
}

void NFPlayerOnline::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint32_t NFPlayerOnline::GetLogicId() const
{
    return m_logicId;
}

void NFPlayerOnline::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFPlayerOnline::GetGameId() const
{
    return m_gameId;
}

void NFPlayerOnline::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

bool NFPlayerOnline::IsOnline() const
{
    return m_isOnline;
}

void NFPlayerOnline::SetIsOnline(bool isOnline)
{
    m_isOnline = isOnline;
}

int NFPlayerOnline::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, m_playerId, 0);
    return 0;
}

int NFPlayerOnline::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData);
    return 0;
}

int NFPlayerOnline::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerOnline::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData);
    return 0;
}

int NFPlayerOnline::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerOnline::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData);
    return 0;
}

int NFPlayerOnline::SendTransToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerOnline::Init()
{
    return 0;
}

int NFPlayerOnline::UnInit()
{
    return 0;
}

uint64_t NFPlayerOnline::GetClientId() const
{
    return 0;
}

void NFPlayerOnline::SetClientId(uint64_t clientId)
{

}

int NFPlayerOnline::OnLogin()
{
    return 0;
}

int NFPlayerOnline::OnLogout()
{
    return 0;
}

int NFPlayerOnline::OnDisconnect()
{
    return 0;
}

int NFPlayerOnline::OnReconnect()
{
    return 0;
}
