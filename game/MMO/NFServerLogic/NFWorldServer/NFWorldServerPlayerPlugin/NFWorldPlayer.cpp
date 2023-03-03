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

NFWorldPlayer::NFWorldPlayer():NFShmObj()
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
    m_uid = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_logicId = 0;
    m_status = PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;
    m_isDisconnect = false;
    m_tokenTimeStamp = 0;
    m_roleId = 0;
    m_channelId = 0;
    m_zid = 0;
    m_isWhite = false;
    m_charNum = 0;
    m_gameId = 0;
    return 0;
}

int NFWorldPlayer::ResumeInit()
{
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        m_isDisconnect = true;
        m_lastDiconnectTime = NFTime::Now().UnixSec();
        m_clientId = 0;
        m_proxyId = 0;
    }
    return 0;
}

int NFWorldPlayer::OnTimer(int timeId, int callcount)
{
    return 0;
}

void  NFWorldPlayer::Tick()
{
    switch (m_status)
    {
        case PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetUid());
        }
            break;
        case PLAYER_STATUS_ONLINE:
        {
        }
            break;
        case PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDiconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "uid:{}, cid:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetUid(), GetRoleId());
        }
            break;
        case PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetLastLogoutTime() + WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME > (uint64_t)NFTime::Now().UnixSec())
                break;

            SetStatus(PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "player:{}, cid:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetUid(),
                      GetRoleId());
        }
        break;
    }
}

uint64_t NFWorldPlayer::GetUid() const
{
    return m_uid;
}

void NFWorldPlayer::SetUid(uint64_t uid)
{
    m_uid = uid;
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

PLAYER_STATUS NFWorldPlayer::GetStatus() const
{
    return m_status;
}

void NFWorldPlayer::SetStatus(PLAYER_STATUS status)
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

bool NFWorldPlayer::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFWorldPlayer::SetIsDisconnect(bool isDisConnect)
{
    m_isDisconnect = isDisConnect;
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

uint64_t NFWorldPlayer::GetRoleId() const
{
    return m_roleId;
}

void NFWorldPlayer::SetRoleId(uint64_t playCid)
{
    m_roleId = playCid;
}

uint32_t NFWorldPlayer::GetChannelId() const
{
    return m_channelId;
}

void NFWorldPlayer::SetChannelId(uint32_t channelId)
{
    m_channelId = channelId;
}

uint32_t NFWorldPlayer::GetZid() const
{
    return m_zid;
}

void NFWorldPlayer::SetZid(uint32_t zid)
{
    m_zid = zid;
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
void NFWorldPlayer::SendMsgToProxyServer(uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, m_proxyId, msgId, xData, m_uid, m_roleId);
}

void NFWorldPlayer::SendMsgToLogicServer(uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, m_logicId, msgId, xData, m_uid, m_roleId);
}

void NFWorldPlayer::SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_WORLD_SERVER, m_logicId, msgId, xData, req_trans_id, rsp_trans_id);
}

void NFWorldPlayer::SendMsgToGameServer(uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_WORLD_SERVER, m_gameId, msgId, xData, m_uid, m_roleId);
}

void NFWorldPlayer::SendTransToGameServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_WORLD_SERVER, m_gameId, msgId, xData, req_trans_id, rsp_trans_id);
}

void NFWorldPlayer::SendMsgToSnsServer(uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, msgId, xData, m_uid, m_roleId);
}

void NFWorldPlayer::SendTransToSnsServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToSnsServer(NF_ST_WORLD_SERVER, msgId, xData, req_trans_id, rsp_trans_id);
}

void NFWorldPlayer::SendMsgToClient(uint32_t msgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, m_proxyId, NF_MODULE_CLIENT, msgId, xData, m_uid, m_roleId);
}

uint32_t NFWorldPlayer::GetCharNum() const
{
    return m_charNum;
}

void NFWorldPlayer::SetCharNum(uint32_t charNum)
{
    m_charNum = charNum;
}

NFWorldRoleInfo *NFWorldPlayer::GetRoleInfo(uint64_t roleId)
{
    auto iter = m_roleInfo.find(roleId);
    if (iter != m_roleInfo.end())
    {
        return &iter->second;
    }
    return nullptr;
}

NFWorldRoleInfo *NFWorldPlayer::CreateRoleInfo(uint64_t roleId)
{
    auto pRoleInfo = GetRoleInfo(roleId);
    if (pRoleInfo)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "CreateRoleInfo Failed!, RoleId:{} Has Exist", roleId);
        return NULL;
    }

    auto iter = m_roleInfo.emplace_hint(roleId, NFWorldRoleInfo());
    if (iter != m_roleInfo.end())
    {
        return &iter->second;
    }

    return nullptr;
}

int NFWorldPlayer::DeleteRoleInfo(uint64_t roleId)
{
    return m_roleInfo.erase(roleId);
}

void NFWorldPlayer::ClearRoleInfo()
{
    m_roleInfo.CreateInit();
}

uint32_t NFWorldPlayer::GetGameId() const
{
    return m_gameId;
}

void NFWorldPlayer::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

