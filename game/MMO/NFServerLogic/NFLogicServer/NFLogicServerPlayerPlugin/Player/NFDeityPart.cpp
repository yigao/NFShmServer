// -------------------------------------------------------------------------
//    @FileName         :    NFDeityPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDeityPart
//
// -------------------------------------------------------------------------

#include "NFDeityPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDeityPart, EOT_NFDeityPart_ID, NFPart
)

NFDeityPart::NFDeityPart()
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

NFDeityPart::~NFDeityPart()
{
}

int NFDeityPart::CreateInit()
{
    return 0;
}

int NFDeityPart::ResumeInit()
{
    return 0;
}
