// -------------------------------------------------------------------------
//    @FileName         :    NFWelfarePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFWelfarePart
//
// -------------------------------------------------------------------------

#include "NFWelfarePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWelfarePart, EOT_LOGIC_PART_ID+PART_WELFARE, NFPart)

NFWelfarePart::NFWelfarePart()
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

NFWelfarePart::~NFWelfarePart()
{
}

int NFWelfarePart::CreateInit()
{
    return 0;
}

int NFWelfarePart::ResumeInit()
{
    return 0;
}
