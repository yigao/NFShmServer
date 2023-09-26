// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSerialBombCrab.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSerialBombCrab
//
// -------------------------------------------------------------------------

#include "NFFishTypeSerialBombCrab.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeSerialBombCrab, EOT_GAME_FISH_TYPE_HANDLE_SERIALBOMBCRAB_ID, NFFishTypeHandler)

NFFishTypeSerialBombCrab::NFFishTypeSerialBombCrab()
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

NFFishTypeSerialBombCrab::~NFFishTypeSerialBombCrab()
{
}

int NFFishTypeSerialBombCrab::CreateInit()
{
    return 0;
}

int NFFishTypeSerialBombCrab::ResumeInit()
{
    return 0;
}
