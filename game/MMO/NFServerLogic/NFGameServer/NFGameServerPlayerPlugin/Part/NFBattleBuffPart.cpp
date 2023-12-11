// -------------------------------------------------------------------------
//    @FileName         :    NFBattleBuffPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-12-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattleBuffPart
//
// -------------------------------------------------------------------------

#include "NFBattleBuffPart.h"

NFBattleBuffPart::NFBattleBuffPart()
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

NFBattleBuffPart::~NFBattleBuffPart()
{
}

int NFBattleBuffPart::CreateInit()
{
    return 0;
}

int NFBattleBuffPart::ResumeInit()
{
    return 0;
}
