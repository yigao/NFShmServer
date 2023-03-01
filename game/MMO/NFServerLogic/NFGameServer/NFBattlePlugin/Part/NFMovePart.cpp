// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#include "NFMovePart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMovePart, EOT_NFMovePart_ID, NFBattlePart)

NFMovePart::NFMovePart()
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

NFMovePart::~NFMovePart()
{
}

int NFMovePart::CreateInit()
{
    m_lastclientMoveTick = 0;
    m_moveTimerFlag = false;
    m_moveTick = 0;
    m_waitLoadMapId = 0;
    return 0;
}

int NFMovePart::ResumeInit()
{
    return 0;
}
