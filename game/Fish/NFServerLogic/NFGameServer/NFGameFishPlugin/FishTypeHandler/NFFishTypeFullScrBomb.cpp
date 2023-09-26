// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFullScrBomb.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFullScrBomb
//
// -------------------------------------------------------------------------

#include "NFFishTypeFullScrBomb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeFullScrBomb, EOT_GAME_FISH_TYPE_HANDLE_FULLSCRBOMB_ID, NFFishTypeHandler)

NFFishTypeFullScrBomb::NFFishTypeFullScrBomb()
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

NFFishTypeFullScrBomb::~NFFishTypeFullScrBomb()
{
}

int NFFishTypeFullScrBomb::CreateInit()
{
    return 0;
}

int NFFishTypeFullScrBomb::ResumeInit()
{
    return 0;
}
