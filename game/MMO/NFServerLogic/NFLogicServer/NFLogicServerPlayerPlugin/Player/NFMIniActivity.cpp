// -------------------------------------------------------------------------
//    @FileName         :    NFMIniActivity.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMIniActivity
//
// -------------------------------------------------------------------------

#include "NFMIniActivity.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMIniActivity, EOT_LOGIC_PART_ID+PART_MINI_ACTIVITY, NFPart)

NFMIniActivity::NFMIniActivity()
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

NFMIniActivity::~NFMIniActivity()
{
}

int NFMIniActivity::CreateInit()
{
    return 0;
}

int NFMIniActivity::ResumeInit()
{
    return 0;
}
