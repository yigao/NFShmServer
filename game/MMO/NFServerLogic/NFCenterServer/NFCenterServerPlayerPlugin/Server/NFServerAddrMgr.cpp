// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddrMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddrMgr
//
// -------------------------------------------------------------------------

#include "NFServerAddrMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFServerAddrMgr::NFServerAddrMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFServerAddrMgr::~NFServerAddrMgr() {
}

int NFServerAddrMgr::CreateInit() {
    return 0;
}

int NFServerAddrMgr::ResumeInit() {
    return 0;
}

int NFServerAddrMgr::AddMapAddr(uint64_t mapId, uint32_t busId, uint32_t zid, bool isCrossServer)
{
    NFMapAddr* pMapAddr = GetMapAddr(mapId);
    if (pMapAddr == NULL)
    {
        pMapAddr = InsertMapAddr(mapId);
        CHECK_NULL(pMapAddr);
    }

    return pMapAddr->AddBusId(busId, zid, isCrossServer);
}

NFMapAddr* NFServerAddrMgr::GetMapAddr(uint64_t mapId)
{
    auto iter = m_mapAddrMap.find(mapId);
    if (iter != m_mapAddrMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

NFMapAddr* NFServerAddrMgr::InsertMapAddr(uint64_t mapId)
{
    if (m_mapAddrMap.size() >= m_mapAddrMap.max_size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "InsertMapAddr failed! mapId:{} space not enough", mapId);
        return NULL;
    }

    return &m_mapAddrMap[mapId];
}

bool NFServerAddrMgr::IsStaticMapId(uint64_t mapId)
{
    NFMapAddr* pMapAddr = GetMapAddr(mapId);
    if (pMapAddr)
    {
        return true;
    }
    return false;
}

uint32_t NFServerAddrMgr::GetSuitGameIdByZid(uint64_t mapId, uint32_t zid)
{
    NFMapAddr* pMapAddr = GetMapAddr(mapId);
    if (pMapAddr)
    {
        return pMapAddr->GetSuitGameIdByZid(zid);
    }
    return 0;
}

uint32_t NFServerAddrMgr::GetSuitGameIdByCross(uint64_t mapId, bool crossServer)
{
    NFMapAddr* pMapAddr = GetMapAddr(mapId);
    if (pMapAddr)
    {
        return pMapAddr->GetSuitGameIdByCross(crossServer);
    }
    return 0;
}

int NFServerAddrMgr::GetAllMapInfo(proto_ff::RegisterCrossMapInfoReq& req, uint32_t zid)
{
    for(auto iter = m_mapAddrMap.begin(); iter != m_mapAddrMap.end(); iter++)
    {
        auto& mapData = iter->second;
        for(auto s_iter = mapData.m_serverData.begin(); s_iter!= mapData.m_serverData.end(); s_iter++)
        {
            auto& serverData = s_iter->second;
            if (serverData.m_zid == zid)
            {
                auto pMapInfo = req.add_map();
                pMapInfo->set_map_id(mapData.m_mapId);
                pMapInfo->set_bus_id(serverData.m_busId);
                pMapInfo->set_cross_server(serverData.m_isCrossServer);
            }
        }
    }
    return 0;
}