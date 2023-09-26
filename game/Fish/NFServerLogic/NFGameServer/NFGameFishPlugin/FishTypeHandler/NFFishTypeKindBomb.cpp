// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeKindBomb.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeKindBomb
//
// -------------------------------------------------------------------------

#include "NFFishTypeKindBomb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeKindBomb, EOT_GAME_FISH_TYPE_HANDLE_KINDBOMB_ID, NFFishTypeHandler)

NFFishTypeKindBomb::NFFishTypeKindBomb()
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

NFFishTypeKindBomb::~NFFishTypeKindBomb()
{
}

int NFFishTypeKindBomb::CreateInit()
{
    return 0;
}

int NFFishTypeKindBomb::ResumeInit()
{
    return 0;
}
