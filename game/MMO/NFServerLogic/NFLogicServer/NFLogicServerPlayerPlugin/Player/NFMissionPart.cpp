// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#include "NFMissionPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMissionPart, EOT_NFMissionPart_ID, NFPart
)

NFMissionPart::NFMissionPart()
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

NFMissionPart::~NFMissionPart()
{
}

int NFMissionPart::CreateInit()
{
    return 0;
}

int NFMissionPart::ResumeInit()
{
    return 0;
}
