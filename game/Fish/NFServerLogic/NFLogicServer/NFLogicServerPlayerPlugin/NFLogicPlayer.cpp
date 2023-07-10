// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include "NFLogicPlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFLogicPlayer, EOT_LOGIC_PLAYER_ID, NFShmObj)

NFLogicPlayer::NFLogicPlayer()
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

NFLogicPlayer::~NFLogicPlayer()
{
    if (m_gameLockTimeId != INVALID_ID)
    {
        DeleteTimer(m_gameLockTimeId);
        m_gameLockTimeId = INVALID_ID;
        m_gameLock = false;
    }

    if (m_roomLockTimeId != INVALID_ID)
    {
        DeleteTimer(m_roomLockTimeId);
        m_roomLockTimeId = INVALID_ID;
        m_roomLock = false;
    }
}

int NFLogicPlayer::CreateInit()
{
    m_playerId = 0;
    m_proxyId = 0;
    m_gameId = 0;
    m_roomId = 0;
    m_roomLock = false;
    m_roomLockTimeId = 0;
    m_logicId = 0;
    m_iStatus = proto_ff::PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;

    m_gameLock = false;
    m_gameLockTimeId = INVALID_ID;
    return 0;
}

int NFLogicPlayer::ResumeInit()
{
    return 0;
}

int NFLogicPlayer::OnTimer(int timeId, int callcount)
{
    if (timeId == m_roomLockTimeId)
    {
        ClearLockRoom();
    }

    if (timeId == m_gameLockTimeId)
    {
        ClearLockGame();
    }

    return 0;
}

void NFLogicPlayer::LockRoom()
{
    m_roomLockTimeId = SetTimer(0, 0, 1, 0);
    m_roomLock = true;
}

void NFLogicPlayer::ClearLockRoom()
{
    if (m_roomLockTimeId != INVALID_ID) {
        DeleteTimer(m_roomLockTimeId);
    }
    m_roomLock = false;
    m_roomLockTimeId = INVALID_ID;
}

void NFLogicPlayer::LockGame()
{
    m_gameLockTimeId = SetTimer(0, 0, 1, 0);
    m_gameLock = true;
}

void NFLogicPlayer::ClearLockGame()
{
    if (m_gameLockTimeId != INVALID_ID) {
        DeleteTimer(m_gameLockTimeId);
    }
    m_gameLock = false;
    m_gameLockTimeId = INVALID_ID;
}

void  NFLogicPlayer::Tick()
{
    switch (m_iStatus)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (IsInGaming())
            {
                if ((uint64_t)NFTime::Now().UnixSec() - m_createTime <  WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
        }
            break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (IsInGaming())
            {
                if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetLastLogoutTime() + WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME > (uint64_t)NFTime::Now().UnixSec())
                break;

            SetStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetPlayerId());
        }
        break;
    }
}




