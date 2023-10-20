// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#include "NFSkillPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSkillPart, EOT_NFSkillPart_ID, NFPart
)

NFSkillPart::NFSkillPart()
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

NFSkillPart::~NFSkillPart()
{
}

int NFSkillPart::CreateInit()
{
    return 0;
}

int NFSkillPart::ResumeInit()
{
    return 0;
}
