// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerInfo
//
// -------------------------------------------------------------------------

#include "NFSnsServerInfo.h"

NFSnsServerInfo::NFSnsServerInfo()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFSnsServerInfo::~NFSnsServerInfo()
{
}

int NFSnsServerInfo::CreateInit()
{
    m_busId = 0;
    return 0;
}

int NFSnsServerInfo::ResumeInit()
{
    return 0;
}
