// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePart
//
// -------------------------------------------------------------------------

#include "NFBattlePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBattlePart, EOT_NFBattlePart_ID, NFShmObj)

NFBattlePart::NFBattlePart()
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

NFBattlePart::~NFBattlePart()
{
}

int NFBattlePart::CreateInit()
{
    return 0;
}

int NFBattlePart::ResumeInit()
{
    return 0;
}
