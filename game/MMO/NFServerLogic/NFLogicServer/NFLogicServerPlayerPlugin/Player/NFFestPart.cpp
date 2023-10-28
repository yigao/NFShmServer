// -------------------------------------------------------------------------
//    @FileName         :    NFFestPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestPart
//
// -------------------------------------------------------------------------

#include "NFFestPart.h"

NFFestPart::NFFestPart()
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

NFFestPart::~NFFestPart()
{
}

int NFFestPart::CreateInit()
{
    return 0;
}

int NFFestPart::ResumeInit()
{
    return 0;
}
