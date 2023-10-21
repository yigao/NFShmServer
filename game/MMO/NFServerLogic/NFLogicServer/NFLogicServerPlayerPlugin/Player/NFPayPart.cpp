// -------------------------------------------------------------------------
//    @FileName         :    NFPayPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPayPart
//
// -------------------------------------------------------------------------

#include "NFPayPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPayPart, EOT_LOGIC_PART_ID+PART_PAY, NFPart)

NFPayPart::NFPayPart()
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

NFPayPart::~NFPayPart()
{
}

int NFPayPart::CreateInit()
{
    return 0;
}

int NFPayPart::ResumeInit()
{
    return 0;
}
