// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeZuanTou.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeZuanTou
//
// -------------------------------------------------------------------------

#include "NFFishTypeZuanTou.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeZuanTou, EOT_GAME_FISH_TYPE_HANDLE_ZUANTOU_ID, NFFishTypeHandler)

NFFishTypeZuanTou::NFFishTypeZuanTou()
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

NFFishTypeZuanTou::~NFFishTypeZuanTou()
{
}

int NFFishTypeZuanTou::CreateInit()
{
    return 0;
}

int NFFishTypeZuanTou::ResumeInit()
{
    return 0;
}
