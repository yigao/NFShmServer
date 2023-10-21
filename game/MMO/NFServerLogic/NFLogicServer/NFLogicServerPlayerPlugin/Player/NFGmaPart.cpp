// -------------------------------------------------------------------------
//    @FileName         :    NFGmaPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGmaPart
//
// -------------------------------------------------------------------------

#include "NFGmaPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGmaPart, EOT_LOGIC_PART_ID+PART_GMA, NFPart)

NFGmaPart::NFGmaPart()
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

NFGmaPart::~NFGmaPart()
{
}

int NFGmaPart::CreateInit()
{
    return 0;
}

int NFGmaPart::ResumeInit()
{
    return 0;
}
