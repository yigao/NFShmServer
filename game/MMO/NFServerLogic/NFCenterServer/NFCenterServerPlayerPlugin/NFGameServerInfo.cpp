// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerInfo
//
// -------------------------------------------------------------------------

#include "NFGameServerInfo.h"

NFGameServerInfo::NFGameServerInfo()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFGameServerInfo::~NFGameServerInfo()
{
}

int NFGameServerInfo::CreateInit()
{
    m_busId = 0;
    m_roleNum = 0;
    return 0;
}

int NFGameServerInfo::ResumeInit()
{
    return 0;
}
