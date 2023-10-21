// -------------------------------------------------------------------------
//    @FileName         :    NFFacadePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFacadePart
//
// -------------------------------------------------------------------------

#include "NFFacadePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFacadePart, EOT_LOGIC_PART_ID+PART_FACADE, NFPart)

NFFacadePart::NFFacadePart()
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

NFFacadePart::~NFFacadePart()
{
}

int NFFacadePart::CreateInit()
{
    return 0;
}

int NFFacadePart::ResumeInit()
{
    return 0;
}
