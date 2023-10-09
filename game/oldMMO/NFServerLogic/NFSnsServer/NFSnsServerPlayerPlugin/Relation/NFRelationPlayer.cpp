// -------------------------------------------------------------------------
//    @FileName         :    NFRelationPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-4-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFRelationPlayer
//
// -------------------------------------------------------------------------

#include "NFRelationPlayer.h"

NFRelationCommonPlayer::NFRelationCommonPlayer()
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

NFRelationCommonPlayer::~NFRelationCommonPlayer()
{
}

int NFRelationCommonPlayer::CreateInit()
{
    m_cid = 0;
    return 0;
}

int NFRelationCommonPlayer::ResumeInit()
{
    return 0;
}

NFRelationRecentPlayer::NFRelationRecentPlayer()
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

NFRelationRecentPlayer::~NFRelationRecentPlayer()
{

}

int NFRelationRecentPlayer::CreateInit()
{
    m_recentType = 0; //交互类型
    m_recentTime = 0; //最后一次交互的时间
    return 0;
}

int NFRelationRecentPlayer::ResumeInit()
{
    return 0;
}

NFRelationFriendPlayer::NFRelationFriendPlayer()
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

NFRelationFriendPlayer::~NFRelationFriendPlayer()
{

}

int NFRelationFriendPlayer::CreateInit()
{
    closeness = 0;            //亲密度
    closenessLevel = 0;    //亲密度等级 （不存库，每次登陆时重新计算）
    todayCloseness = 0;    //今天获得的亲密度值 （每天刷新，玩家身上保存刷新时间，每天定时重置亲密度值）
    updateTime = 0;        //亲密度刷新时间
    return 0;
}

int NFRelationFriendPlayer::ResumeInit()
{
    return 0;
}


NFRelationHatePlayer::NFRelationHatePlayer()
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

NFRelationHatePlayer::~NFRelationHatePlayer()
{

}

int NFRelationHatePlayer::CreateInit()
{
    m_killMeTimes = 0;
    return 0;
}

int NFRelationHatePlayer::ResumeInit()
{
    return 0;
}

NFRelationApplyPlayer::NFRelationApplyPlayer()
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

NFRelationApplyPlayer::~NFRelationApplyPlayer()
{

}

int NFRelationApplyPlayer::CreateInit()
{
    return 0;
}

int NFRelationApplyPlayer::ResumeInit()
{
    return 0;
}
