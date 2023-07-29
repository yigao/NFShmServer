// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomPlayer
//
// -------------------------------------------------------------------------

#include "NFWorldRoomPlayer.h"

NFWorldRoomPlayer::NFWorldRoomPlayer()
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

NFWorldRoomPlayer::~NFWorldRoomPlayer()
{
}

int NFWorldRoomPlayer::CreateInit()
{
    m_playerId = 0;
    m_deskId = 0;
    return 0;
}

int NFWorldRoomPlayer::ResumeInit()
{
    return 0;
}
