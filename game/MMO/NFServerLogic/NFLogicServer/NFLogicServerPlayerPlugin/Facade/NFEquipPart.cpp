// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#include "NFEquipPart.h"

NFEquipPart::NFEquipPart()
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

NFEquipPart::~NFEquipPart()
{
}

int NFEquipPart::CreateInit()
{
    return 0;
}

int NFEquipPart::ResumeInit()
{
    return 0;
}
