// -------------------------------------------------------------------------
//    @FileName         :    NFIGamePlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGamePlayer
//
// -------------------------------------------------------------------------

#include "NFIGamePlayer.h"

NFIGamePlayer::NFIGamePlayer()
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

NFIGamePlayer::~NFIGamePlayer()
{
}

int NFIGamePlayer::CreateInit()
{
    return 0;
}

int NFIGamePlayer::ResumeInit()
{
    return 0;
}
