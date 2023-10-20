// -------------------------------------------------------------------------
//    @FileName         :    NFTurnPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFTurnPart
//
// -------------------------------------------------------------------------

#include "NFTurnPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTurnPart, EOT_NFTurnPart_ID, NFPart
)

NFTurnPart::NFTurnPart()
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

NFTurnPart::~NFTurnPart()
{
}

int NFTurnPart::CreateInit()
{
    return 0;
}

int NFTurnPart::ResumeInit()
{
    return 0;
}
