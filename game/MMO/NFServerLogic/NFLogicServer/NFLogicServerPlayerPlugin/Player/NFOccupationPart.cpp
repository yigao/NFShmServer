// -------------------------------------------------------------------------
//    @FileName         :    NFOccupationPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFOccupationPart
//
// -------------------------------------------------------------------------

#include "NFOccupationPart.h"

NFOccupationPart::NFOccupationPart()
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

NFOccupationPart::~NFOccupationPart()
{
}

int NFOccupationPart::CreateInit()
{
    return 0;
}

int NFOccupationPart::ResumeInit()
{
    return 0;
}
