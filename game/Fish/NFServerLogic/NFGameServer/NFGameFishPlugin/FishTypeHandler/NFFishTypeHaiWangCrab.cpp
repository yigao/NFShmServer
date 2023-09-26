// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHaiWangCrab.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHaiWangCrab
//
// -------------------------------------------------------------------------

#include "NFFishTypeHaiWangCrab.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeHaiWangCrab, EOT_GAME_FISH_TYPE_HANDLE_HAIWANGCRAB_ID, NFFishTypeHandler)

NFFishTypeHaiWangCrab::NFFishTypeHaiWangCrab()
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

NFFishTypeHaiWangCrab::~NFFishTypeHaiWangCrab()
{
}

int NFFishTypeHaiWangCrab::CreateInit()
{
    return 0;
}

int NFFishTypeHaiWangCrab::ResumeInit()
{
    return 0;
}
