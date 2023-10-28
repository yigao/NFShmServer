// -------------------------------------------------------------------------
//    @FileName         :    NFDailyWelfarePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDailyWelfarePart
//
// -------------------------------------------------------------------------

#include "NFDailyWelfarePart.h"

NFDailyWelfarePart::NFDailyWelfarePart()
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

NFDailyWelfarePart::~NFDailyWelfarePart()
{
}

int NFDailyWelfarePart::CreateInit()
{
    return 0;
}

int NFDailyWelfarePart::ResumeInit()
{
    return 0;
}
