// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoom.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoom
//
// -------------------------------------------------------------------------

#include "NFWorldRoom.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFWorldRoom::NFWorldRoom()
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

NFWorldRoom::~NFWorldRoom()
{
}

int NFWorldRoom::CreateInit()
{
    m_id = 0;
    m_gameId = 0;
    m_roomId = 0;
    m_busId = 0;
    return 0;
}

int NFWorldRoom::ResumeInit()
{
    return 0;
}
