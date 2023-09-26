// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSomeZuanTou.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSomeZuanTou
//
// -------------------------------------------------------------------------

#include "NFFishTypeSomeZuanTou.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeSomeZuanTou, EOT_GAME_FISH_TYPE_HANDLE_SOME_ZUANTOU_ID, NFFishTypeHandler)

NFFishTypeSomeZuanTou::NFFishTypeSomeZuanTou()
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

NFFishTypeSomeZuanTou::~NFFishTypeSomeZuanTou()
{
}

int NFFishTypeSomeZuanTou::CreateInit()
{
    return 0;
}

int NFFishTypeSomeZuanTou::ResumeInit()
{
    return 0;
}
