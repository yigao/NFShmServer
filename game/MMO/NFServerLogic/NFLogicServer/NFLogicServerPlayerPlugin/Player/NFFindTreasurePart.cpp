// -------------------------------------------------------------------------
//    @FileName         :    NFFindTreasurePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFindTreasurePart
//
// -------------------------------------------------------------------------

#include "NFFindTreasurePart.h"

NFFindTreasurePart::NFFindTreasurePart()
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

NFFindTreasurePart::~NFFindTreasurePart()
{
}

int NFFindTreasurePart::CreateInit()
{
    return 0;
}

int NFFindTreasurePart::ResumeInit()
{
    return 0;
}
