// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePlayer
//
// -------------------------------------------------------------------------

#include "NFBattlePlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBattlePlayer, EOT_GAME_NFBattlePlayer_ID, NFCreature)

NFBattlePlayer::NFBattlePlayer()
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

NFBattlePlayer::~NFBattlePlayer()
{
}

int NFBattlePlayer::CreateInit()
{
    m_kind = CREATURE_PLAYER;
    return 0;
}

int NFBattlePlayer::ResumeInit()
{
    return 0;
}
