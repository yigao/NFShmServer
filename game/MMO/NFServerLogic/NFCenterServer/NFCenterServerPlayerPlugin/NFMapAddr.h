// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddr.h
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"

#define MAX_SERVER_NUM_OF_ONE_MAP 100

class NFMapAddr
{
public:
    NFMapAddr();

    virtual ~NFMapAddr();

    int CreateInit();

    int ResumeInit();
public:
    int AddBusId(uint32_t busId);
    uint32_t GetMapId() const { return m_mapId; }
    void SetMapId(uint32_t mapId) { m_mapId = mapId; }
    bool IsExist(uint32_t mapId) { return m_serverData.find(mapId) != m_serverData.end(); }
public:
    uint32_t m_mapId;
    NFShmHashSet<uint32_t, MAX_SERVER_NUM_OF_ONE_MAP> m_serverData;
};