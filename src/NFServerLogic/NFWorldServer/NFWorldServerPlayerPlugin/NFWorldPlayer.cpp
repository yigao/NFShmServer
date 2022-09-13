// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include "NFWorldPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldPlayer, EOT_WORLD_PLAYER_ID, NFShmObj)

NFWorldPlayer::NFWorldPlayer()
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
    m_logicId = 0;
    m_iStatus = PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;

    return 0;
}

int NFWorldPlayer::ResumeInit()
{
    return 0;
}

void NFWorldPlayer::OnTimer(int timeId, int callcount)
{

}

void  NFWorldPlayer::Tick()
{
    switch (m_iStatus)
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
    }
}




