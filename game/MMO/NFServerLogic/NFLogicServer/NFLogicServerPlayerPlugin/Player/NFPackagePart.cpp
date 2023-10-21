// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#include "NFPackagePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPackagePart, EOT_LOGIC_PART_ID+PART_PACKAGE, NFPart)

NFPackagePart::NFPackagePart()
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

NFPackagePart::~NFPackagePart()
{
}

int NFPackagePart::CreateInit()
{
    return 0;
}

int NFPackagePart::ResumeInit()
{
    return 0;
}