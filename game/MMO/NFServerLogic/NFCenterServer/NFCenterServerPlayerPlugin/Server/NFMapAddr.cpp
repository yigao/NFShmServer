// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddr
//
// -------------------------------------------------------------------------

#include "NFMapAddr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFMapAddr::NFMapAddr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFMapAddr::~NFMapAddr() {
}

int NFMapAddr::CreateInit()
{
    m_mapId = 0;
    return 0;
}

int NFMapAddr::ResumeInit() {
    return 0;
}

int NFMapAddr::AddBusId(uint32_t busId, uint32_t zid, bool isCrossServer)
{
    if (!IsExist(busId))
    {
        if (m_serverData.size() >= m_serverData.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "add busId:{} failed, space not entough", busId);
            return -1;
        }

        auto pServer = &m_serverData[busId];
        pServer->m_busId = busId;
        pServer->m_zid = zid;
        pServer->m_isCrossServer = isCrossServer;
    }
    return 0;
}

uint32_t NFMapAddr::GetSuitGameIdByZid(uint32_t zid) const
{
    std::vector<uint32_t> vec;
    for(auto iter = m_serverData.begin(); iter != m_serverData.end(); iter++)
    {
        if (iter->second.m_zid == zid)
        {
            vec.push_back(iter->first);
        }
    }
    
    std::random_shuffle(vec.begin(), vec.end());
    if (vec.size() > 0)
    {
        return *vec.begin();
    }
    return 0;
}

uint32_t NFMapAddr::GetSuitGameIdByCross(bool isCrossServer) const
{
    std::vector<uint32_t> vec;
    for(auto iter = m_serverData.begin(); iter != m_serverData.end(); iter++)
    {
        if (iter->second.m_isCrossServer == isCrossServer)
        {
            vec.push_back(iter->first);
        }
    }
    
    std::random_shuffle(vec.begin(), vec.end());
    if (vec.size() > 0)
    {
        return *vec.begin();
    }
    return 0;
}
