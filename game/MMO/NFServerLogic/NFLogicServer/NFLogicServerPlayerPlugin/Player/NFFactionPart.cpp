// -------------------------------------------------------------------------
//    @FileName         :    NFFactionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFactionPart
//
// -------------------------------------------------------------------------

#include "NFFactionPart.h"

NFFactionPart::NFFactionPart()
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

NFFactionPart::~NFFactionPart()
{
}

int NFFactionPart::CreateInit()
{
    return 0;
}

int NFFactionPart::ResumeInit()
{
    return 0;
}
