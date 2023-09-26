// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightLink.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightLink
//
// -------------------------------------------------------------------------

#include "NFFishTypeLightLink.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeLightLink, EOT_GAME_FISH_TYPE_HANDLE_LIGHTLINK_ID, NFFishTypeHandler)

NFFishTypeLightLink::NFFishTypeLightLink()
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

NFFishTypeLightLink::~NFFishTypeLightLink()
{
}

int NFFishTypeLightLink::CreateInit()
{
    return 0;
}

int NFFishTypeLightLink::ResumeInit()
{
    return 0;
}
