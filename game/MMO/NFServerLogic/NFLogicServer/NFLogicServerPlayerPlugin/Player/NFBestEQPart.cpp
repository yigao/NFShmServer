// -------------------------------------------------------------------------
//    @FileName         :    NFBestEQPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBestEQPart
//
// -------------------------------------------------------------------------

#include "NFBestEQPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBestEQPart, EOT_NFBestEQPart_ID, NFPart)

NFBestEQPart::NFBestEQPart()
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

NFBestEQPart::~NFBestEQPart()
{
}

int NFBestEQPart::CreateInit()
{
    return 0;
}

int NFBestEQPart::ResumeInit()
{
    return 0;
}
