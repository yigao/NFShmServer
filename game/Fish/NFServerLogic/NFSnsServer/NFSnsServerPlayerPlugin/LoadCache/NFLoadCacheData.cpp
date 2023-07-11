// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheData.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheData
//
// -------------------------------------------------------------------------

#include "NFLoadCacheData.h"

NFLoadCacheData::NFLoadCacheData()
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

NFLoadCacheData::~NFLoadCacheData()
{
}

int NFLoadCacheData::CreateInit()
{
    m_roleId = 0;
    m_roleInfo.CreateInit();
    return 0;
}

int NFLoadCacheData::ResumeInit()
{
    return 0;
}

int NFLoadCacheData::Add(uint32_t transId, uint64_t time)
{
    if (transId > 0) {
        for (auto iter = m_roleInfo.Begin(); iter != m_roleInfo.End(); iter++) {
            if (transId == iter->m_transId) {
                return 0;
            }
        }
    }

    if (!m_roleInfo.Full()) {
        auto pInfo = m_roleInfo.PushBack();
        pInfo->m_transId = transId;
        pInfo->m_loadTime = time;
    } else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get role info trans cache full:{} {}", m_roleId, m_roleInfo.GetSize());
        return -1;
    }

    return 0;
}
