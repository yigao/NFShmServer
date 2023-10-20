// -------------------------------------------------------------------------
//    @FileName         :    NFMarryPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMarryPart
//
// -------------------------------------------------------------------------

#include "NFMarryPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMarryPart, EOT_NFMarryPart_ID, NFPart
)

NFMarryPart::NFMarryPart()
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

NFMarryPart::~NFMarryPart()
{
}

int NFMarryPart::CreateInit()
{
    return 0;
}

int NFMarryPart::ResumeInit()
{
    return 0;
}
