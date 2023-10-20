// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#include "NFMovePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMovePart, EOT_NFMovePart_ID, NFPart
)

NFMovePart::NFMovePart()
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

NFMovePart::~NFMovePart()
{
}

int NFMovePart::CreateInit()
{
    return 0;
}

int NFMovePart::ResumeInit()
{
    return 0;
}
