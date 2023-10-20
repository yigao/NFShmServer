// -------------------------------------------------------------------------
//    @FileName         :    NFGiftPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGiftPart
//
// -------------------------------------------------------------------------

#include "NFGiftPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGiftPart, EOT_NFGiftPart_ID, NFPart
)

NFGiftPart::NFGiftPart()
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

NFGiftPart::~NFGiftPart()
{
}

int NFGiftPart::CreateInit()
{
    return 0;
}

int NFGiftPart::ResumeInit()
{
    return 0;
}
