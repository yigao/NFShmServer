// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheDataInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheDataInfo
//
// -------------------------------------------------------------------------

#include "NFLoadCacheDataInfo.h"

NFLoadCacheDataInfo::NFLoadCacheDataInfo()
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

NFLoadCacheDataInfo::~NFLoadCacheDataInfo()
{
}

int NFLoadCacheDataInfo::CreateInit()
{
    m_transId = 0;
    m_loadTime = 0;
    return 0;
}

int NFLoadCacheDataInfo::ResumeInit()
{
    return 0;
}
