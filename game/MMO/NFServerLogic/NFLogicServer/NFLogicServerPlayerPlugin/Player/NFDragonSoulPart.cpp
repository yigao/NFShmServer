// -------------------------------------------------------------------------
//    @FileName         :    NFDragonSoulPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDragonSoulPart
//
// -------------------------------------------------------------------------

#include "NFDragonSoulPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDragonSoulPart, EOT_LOGIC_PART_ID+PART_DRAGONSOUL, NFPart)

NFDragonSoulPart::NFDragonSoulPart()
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

NFDragonSoulPart::~NFDragonSoulPart()
{
}

int NFDragonSoulPart::CreateInit()
{
    return 0;
}

int NFDragonSoulPart::ResumeInit()
{
    return 0;
}
