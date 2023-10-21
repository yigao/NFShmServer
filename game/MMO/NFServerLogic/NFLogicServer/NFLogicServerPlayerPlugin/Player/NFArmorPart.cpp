// -------------------------------------------------------------------------
//    @FileName         :    NFArmorPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFArmorPart
//
// -------------------------------------------------------------------------

#include "NFArmorPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFArmorPart, EOT_LOGIC_PART_ID+PART_ARMOR, NFPart)

NFArmorPart::NFArmorPart()
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

NFArmorPart::~NFArmorPart()
{
}

int NFArmorPart::CreateInit()
{
    return 0;
}

int NFArmorPart::ResumeInit()
{
    return 0;
}
