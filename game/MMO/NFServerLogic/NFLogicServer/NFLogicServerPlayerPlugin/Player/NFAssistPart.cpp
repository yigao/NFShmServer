// -------------------------------------------------------------------------
//    @FileName         :    NFAssistPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAssistPart
//
// -------------------------------------------------------------------------

#include "NFAssistPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFAssistPart, EOT_LOGIC_PART_ID+PART_ASSIST, NFPart)

NFAssistPart::NFAssistPart()
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

NFAssistPart::~NFAssistPart()
{
}

int NFAssistPart::CreateInit()
{
    return 0;
}

int NFAssistPart::ResumeInit()
{
    return 0;
}
