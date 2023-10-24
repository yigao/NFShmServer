// -------------------------------------------------------------------------
//    @FileName         :    NFGodevilPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGodevilPart
//
// -------------------------------------------------------------------------

#include "NFGodEvilPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGodEvilPart, EOT_LOGIC_PART_ID + PART_GODEVIL, NFPart)

NFGodEvilPart::NFGodEvilPart()
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

NFGodEvilPart::~NFGodEvilPart()
{
}

int NFGodEvilPart::CreateInit()
{
    return 0;
}

int NFGodEvilPart::ResumeInit()
{
    return 0;
}
