// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#include "NFBagPage.h"

NFBagPage::NFBagPage()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFBagPage::~NFBagPage()
{
}

int NFBagPage::CreateInit()
{
    return 0;
}

int NFBagPage::ResumeInit()
{
    return 0;
}
