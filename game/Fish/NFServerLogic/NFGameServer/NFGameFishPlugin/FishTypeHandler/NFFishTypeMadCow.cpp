// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMadCow.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMadCow
//
// -------------------------------------------------------------------------

#include "NFFishTypeMadCow.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeMadCow, EOT_GAME_FISH_TYPE_HANDLE_MADCOW_ID, NFFishTypeHandler)

NFFishTypeMadCow::NFFishTypeMadCow()
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

NFFishTypeMadCow::~NFFishTypeMadCow()
{
}

int NFFishTypeMadCow::CreateInit()
{
    return 0;
}

int NFFishTypeMadCow::ResumeInit()
{
    return 0;
}
