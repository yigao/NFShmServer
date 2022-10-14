// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include "NFWorldPlayer.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldPlayer, EOT_WORLD_PLAYER_ID, NFShmObj)

NFWorldPlayer::NFWorldPlayer(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
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

NFWorldPlayer::~NFWorldPlayer()
{

}

int NFWorldPlayer::CreateInit()
{
    m_playerId = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_logicId = 0;
    m_status = PLAYER_STATE_NULL;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;
    m_isNotifyCloseProxy = false;
    m_tokenTimeStamp = 0;
    m_playCid = 0;
    m_statusTimeStamp = 0;
    m_channelId = 0;
    m_bornZid = 0;
    m_isWhite = false;
    return 0;
}

int NFWorldPlayer::ResumeInit()
{
    m_isNotifyCloseProxy = false;
    m_clientId = 0;
    return 0;
}

void NFWorldPlayer::OnTimer(int timeId, int callcount)
{

}

void  NFWorldPlayer::Tick()
{
/*    switch (m_status)
    {
        case PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case PLAYER_STATUS_ONLINE:
        {
        }
            break;
        case PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetLastLogoutTime() + WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME > (uint64_t)NFTime::Now().UnixSec())
                break;

            SetStatus(PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetPlayerId());
        }
        break;
    }*/
}

uint64_t NFWorldPlayer::GetPlayerId() const
{
    return m_playerId;
}

void NFWorldPlayer::SetPlayerId(uint64_t playerId)
{
    m_playerId = playerId;
}

uint32_t NFWorldPlayer::GetProxyId() const
{
    return m_proxyId;
}

void NFWorldPlayer::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint64_t NFWorldPlayer::GetClientId() const
{
    return m_clientId;
}

void NFWorldPlayer::SetClientId(uint64_t clientId)
{
    m_clientId = clientId;
}

uint32_t NFWorldPlayer::GetLogicId() const
{
    return m_logicId;
}

void NFWorldPlayer::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

WorldPlayerState NFWorldPlayer::GetStatus() const
{
    return m_status;
}

void NFWorldPlayer::SetStatus(WorldPlayerState status)
{
    m_status = status;
}

uint64_t NFWorldPlayer::GetCreateTime() const
{
    return m_createTime;
}

void NFWorldPlayer::SetCreateTime(uint64_t createTime)
{
    m_createTime = createTime;
}

uint64_t NFWorldPlayer::GetLastDiconnectTime() const
{
    return m_lastDiconnectTime;
}

void NFWorldPlayer::SetLastDiconnectTime(uint64_t lastDiconnectTime)
{
    m_lastDiconnectTime = lastDiconnectTime;
}

uint64_t NFWorldPlayer::GetLastLogoutTime() const
{
    return m_lastLogoutTime;
}

void NFWorldPlayer::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_lastLogoutTime = lastLogoutTime;
}

bool NFWorldPlayer::IsNotifyCloseProxy() const
{
    return m_isNotifyCloseProxy;
}

void NFWorldPlayer::SetIsNotifyCloseProxy(bool isNotifyCloseProxy)
{
    m_isNotifyCloseProxy = isNotifyCloseProxy;
}

const string &NFWorldPlayer::GetToken() const
{
    return m_token;
}

void NFWorldPlayer::SetToken(const string &token)
{
    m_token = token;
}

uint64_t NFWorldPlayer::GetTokenTimeStamp() const
{
    return m_tokenTimeStamp;
}

void NFWorldPlayer::SetTokenTimeStamp(uint64_t tokenTimeStamp)
{
    m_tokenTimeStamp = tokenTimeStamp;
}

uint64_t NFWorldPlayer::GetPlayCid() const
{
    return m_playCid;
}

void NFWorldPlayer::SetPlayCid(uint64_t playCid)
{
    m_playCid = playCid;
}

uint64_t NFWorldPlayer::GetStatusTimeStamp() const
{
    return m_statusTimeStamp;
}

void NFWorldPlayer::SetStatusTimeStamp(uint64_t statusTimeStamp)
{
    m_statusTimeStamp = statusTimeStamp;
}

uint32_t NFWorldPlayer::GetChannelId() const
{
    return m_channelId;
}

void NFWorldPlayer::SetChannelId(uint32_t channelId)
{
    m_channelId = channelId;
}

uint32_t NFWorldPlayer::GetBornZid() const
{
    return m_bornZid;
}

void NFWorldPlayer::SetBornZid(uint32_t bornZid)
{
    m_bornZid = bornZid;
}

bool NFWorldPlayer::IsWhite() const
{
    return m_isWhite;
}

void NFWorldPlayer::SetIsWhite(bool isWhite)
{
    m_isWhite = isWhite;
}

/**
 * @brief 玩家发信息到网关
 * @param moduleId
 * @param msgId
 * @param xData
 */
void NFWorldPlayer::SendMsgToProxyServer(uint32_t moduleId, uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, m_proxyId, moduleId, msgId, xData, m_playerId);
}

void NFWorldPlayer::SendMsgToLogicServer(uint32_t moduleId, uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, m_logicId, moduleId, msgId, xData, m_playerId);
}


