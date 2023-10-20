// -------------------------------------------------------------------------
//    @FileName         :    NFRankPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankPart
//
// -------------------------------------------------------------------------

#include "NFRankPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRankPart, EOT_NFRankPart_ID, NFPart
)

NFRankPart::NFRankPart()
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

NFRankPart::~NFRankPart()
{
}

int NFRankPart::CreateInit()
{
    return 0;
}

int NFRankPart::ResumeInit()
{
    return 0;
}
