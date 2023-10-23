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

IMPLEMENT_IDCREATE_WITHTYPE(NFServerAddrMgr, EOT_NFMapAddrMgr_ID, NFShmObj)

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

int NFServerAddrMgr::AddMapAddr(uint32_t mapId, uint32_t busId)
{
    NFMapAddr* pMapAddr = GetMapAddr(mapId);
    if (pMapAddr == NULL)
    {
        pMapAddr = InsertMapAddr(mapId);
        CHECK_NULL(pMapAddr);
    }

    return pMapAddr->AddBusId(busId);
}

NFMapAddr* NFServerAddrMgr::GetMapAddr(uint32_t mapId)
{
    auto iter = m_mapAddrMap.find(mapId);
    if (iter != m_mapAddrMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

NFMapAddr* NFServerAddrMgr::InsertMapAddr(uint32_t mapId)
{
    if (m_mapAddrMap.size() >= m_mapAddrMap.max_size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "InsertMapAddr failed! mapId:{} space not enough", mapId);
        return NULL;
    }

    return &m_mapAddrMap[mapId];
}