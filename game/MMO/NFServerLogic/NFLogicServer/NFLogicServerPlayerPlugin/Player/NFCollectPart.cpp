// -------------------------------------------------------------------------
//    @FileName         :    NFCollectPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFCollectPart
//
// -------------------------------------------------------------------------

#include "NFCollectPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFCollectPart, EOT_LOGIC_PART_ID+PART_COLLECT, NFPart
)

NFCollectPart::NFCollectPart()
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

NFCollectPart::~NFCollectPart()
{
}

int NFCollectPart::CreateInit()
{
    return 0;
}

int NFCollectPart::ResumeInit()
{
    return 0;
}
