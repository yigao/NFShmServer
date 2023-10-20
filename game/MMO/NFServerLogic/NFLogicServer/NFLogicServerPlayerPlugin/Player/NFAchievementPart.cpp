// -------------------------------------------------------------------------
//    @FileName         :    NFAchievementPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAchievementPart
//
// -------------------------------------------------------------------------

#include "NFAchievementPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFAchievementPart, EOT_NFAchievementPart_ID, NFPart)

NFAchievementPart::NFAchievementPart()
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

NFAchievementPart::~NFAchievementPart()
{
}

int NFAchievementPart::CreateInit()
{
    return 0;
}

int NFAchievementPart::ResumeInit()
{
    return 0;
}
