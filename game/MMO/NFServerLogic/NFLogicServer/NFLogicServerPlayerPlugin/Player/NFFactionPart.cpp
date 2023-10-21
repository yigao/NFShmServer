// -------------------------------------------------------------------------
//    @FileName         :    NFFactionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFactionPart
//
// -------------------------------------------------------------------------

#include "NFFactionPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFactionPart, EOT_LOGIC_PART_ID+PART_FACTION, NFPart)

NFFactionPart::NFFactionPart()
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

NFFactionPart::~NFFactionPart()
{
}

int NFFactionPart::CreateInit()
{
    return 0;
}

int NFFactionPart::ResumeInit()
{
    return 0;
}
