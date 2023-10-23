// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerInfo
//
// -------------------------------------------------------------------------

#include "NFLogicServerInfo.h"

NFLogicServerInfo::NFLogicServerInfo()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFLogicServerInfo::~NFLogicServerInfo()
{
}

int NFLogicServerInfo::CreateInit()
{
    m_busId = 0;
    m_roleNum = 0;
    return 0;
}

int NFLogicServerInfo::ResumeInit()
{
    return 0;
}
