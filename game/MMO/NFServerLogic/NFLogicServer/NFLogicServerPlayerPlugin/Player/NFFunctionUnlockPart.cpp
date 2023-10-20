// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#include "NFFunctionUnlockPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFunctionUnlockPart, EOT_NFFunctionUnlockPart_ID, NFPart
)

NFFunctionUnlockPart::NFFunctionUnlockPart()
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

NFFunctionUnlockPart::~NFFunctionUnlockPart()
{
}

int NFFunctionUnlockPart::CreateInit()
{
    return 0;
}

int NFFunctionUnlockPart::ResumeInit()
{
    return 0;
}
