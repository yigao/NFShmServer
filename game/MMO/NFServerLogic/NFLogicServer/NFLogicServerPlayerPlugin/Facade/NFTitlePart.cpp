// -------------------------------------------------------------------------
//    @FileName         :    NFTitlePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFTitlePart
//
// -------------------------------------------------------------------------

#include "NFTitlePart.h"

NFTitlePart::NFTitlePart()
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

NFTitlePart::~NFTitlePart()
{
}

int NFTitlePart::CreateInit()
{
    return 0;
}

int NFTitlePart::ResumeInit()
{
    return 0;
}
