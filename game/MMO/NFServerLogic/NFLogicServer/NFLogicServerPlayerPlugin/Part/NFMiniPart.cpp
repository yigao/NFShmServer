// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#include "NFMiniPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMiniPart, EOT_LOGIC_MINI_PART_ID, NFPart)

NFMiniPart::NFMiniPart() : NFPart()
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

NFMiniPart::~NFMiniPart()
{
}

int NFMiniPart::CreateInit()
{
    return 0;
}

int NFMiniPart::ResumeInit()
{
    return 0;
}
