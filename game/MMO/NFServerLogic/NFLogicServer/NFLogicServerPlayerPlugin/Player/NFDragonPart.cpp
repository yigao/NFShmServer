// -------------------------------------------------------------------------
//    @FileName         :    NFDragonPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDragonPart
//
// -------------------------------------------------------------------------

#include "NFDragonPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDragonPart, EOT_LOGIC_PART_ID+PART_DRAGON, NFPart)

NFDragonPart::NFDragonPart()
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

NFDragonPart::~NFDragonPart()
{
}

int NFDragonPart::CreateInit()
{
    return 0;
}

int NFDragonPart::ResumeInit()
{
    return 0;
}
