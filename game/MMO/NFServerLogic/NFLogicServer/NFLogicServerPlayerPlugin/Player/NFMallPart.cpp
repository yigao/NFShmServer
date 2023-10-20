// -------------------------------------------------------------------------
//    @FileName         :    NFMallPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMallPart
//
// -------------------------------------------------------------------------

#include "NFMallPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMallPart, EOT_NFMallPart_ID, NFPart
)

NFMallPart::NFMallPart()
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

NFMallPart::~NFMallPart()
{
}

int NFMallPart::CreateInit()
{
    return 0;
}

int NFMallPart::ResumeInit()
{
    return 0;
}
