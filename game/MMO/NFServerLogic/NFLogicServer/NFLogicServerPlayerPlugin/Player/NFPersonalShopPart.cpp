// -------------------------------------------------------------------------
//    @FileName         :    NFPersonalShopPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPersonalShopPart
//
// -------------------------------------------------------------------------

#include "NFPersonalShopPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPersonalShopPart, EOT_LOGIC_PART_ID+PART_PersonalShop, NFPart
)

NFPersonalShopPart::NFPersonalShopPart()
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

NFPersonalShopPart::~NFPersonalShopPart()
{
}

int NFPersonalShopPart::CreateInit()
{
    return 0;
}

int NFPersonalShopPart::ResumeInit()
{
    return 0;
}
