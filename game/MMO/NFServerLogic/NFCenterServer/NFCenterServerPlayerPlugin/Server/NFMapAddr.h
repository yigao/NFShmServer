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
#include "NFComm/NFShmStl/NFShmHashMap.h"

#define MAX_SERVER_NUM_OF_ONE_MAP 100

class NFMapZid
{
public:
    NFMapZid()
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
    
    virtual ~NFMapZid()
    {
    
    }
    
    int CreateInit()
    {
        m_zid = 0;
        m_isCrossServer = false;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }

public:
    uint32_t m_busId;
    uint32_t m_zid;
    bool m_isCrossServer;
};

class NFMapAddr
{
public:
    NFMapAddr();
    
    virtual ~NFMapAddr();
    
    int CreateInit();
    
    int ResumeInit();

public:
    int AddBusId(uint32_t busId, uint32_t zid, bool isCrossServer);
    
    uint32_t GetMapId() const { return m_mapId; }
    
    void SetMapId(uint32_t mapId) { m_mapId = mapId; }
    
    bool IsExist(uint32_t busId) { return m_serverData.find(busId) != m_serverData.end(); }

public:
    uint32_t GetSuitGameIdByZid(uint32_t zid) const;
    uint32_t GetSuitGameIdByCross(bool isCrossServer) const;
public:
    uint32_t m_mapId;
    NFShmHashMap<uint32_t, NFMapZid, MAX_SERVER_NUM_OF_ONE_MAP> m_serverData;
};