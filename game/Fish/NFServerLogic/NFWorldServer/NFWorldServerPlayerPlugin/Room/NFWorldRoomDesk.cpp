// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomDesk.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomDesk
//
// -------------------------------------------------------------------------

#include "NFWorldRoomDesk.h"

NFWorldRoomDesk::NFWorldRoomDesk()
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

NFWorldRoomDesk::~NFWorldRoomDesk()
{
}

int NFWorldRoomDesk::CreateInit()
{
    return 0;
}

int NFWorldRoomDesk::ResumeInit()
{
    return 0;
}
