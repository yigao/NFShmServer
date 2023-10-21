// -------------------------------------------------------------------------
//    @FileName         :    NFDupPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDupPart
//
// -------------------------------------------------------------------------

#include "NFDupPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDupPart, EOT_LOGIC_PART_ID+PART_DUP, NFPart
)

NFDupPart::NFDupPart()
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

NFDupPart::~NFDupPart()
{
}

int NFDupPart::CreateInit()
{
    return 0;
}

int NFDupPart::ResumeInit()
{
    return 0;
}
