// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightningJellyFish.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightningJellyFish
//
// -------------------------------------------------------------------------

#include "NFFishTypeLightningJellyFish.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeLightningJellyFish, EOT_GAME_FISH_TYPE_HANDLE_LIGHTNINGJELLYFISH_ID, NFFishTypeHandler)

NFFishTypeLightningJellyFish::NFFishTypeLightningJellyFish()
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

NFFishTypeLightningJellyFish::~NFFishTypeLightningJellyFish()
{
}

int NFFishTypeLightningJellyFish::CreateInit()
{
    return 0;
}

int NFFishTypeLightningJellyFish::ResumeInit()
{
    return 0;
}
