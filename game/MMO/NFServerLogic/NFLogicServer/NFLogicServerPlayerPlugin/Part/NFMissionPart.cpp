// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#include "NFMissionPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMissionPart, EOT_LOGIC_MISSION_PART_ID, NFShmObj)

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
