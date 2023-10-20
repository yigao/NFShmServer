// -------------------------------------------------------------------------
//    @FileName         :    NFGodevilPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGodevilPart
//
// -------------------------------------------------------------------------

#include "NFGodevilPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGodevilPart, EOT_NFGodevilPart_ID, NFPart
)

NFGodevilPart::NFGodevilPart()
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

NFGodevilPart::~NFGodevilPart()
{
}

int NFGodevilPart::CreateInit()
{
    return 0;
}

int NFGodevilPart::ResumeInit()
{
    return 0;
}
