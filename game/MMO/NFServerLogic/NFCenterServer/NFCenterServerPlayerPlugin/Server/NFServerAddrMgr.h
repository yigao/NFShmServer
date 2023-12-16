// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddrMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddrMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFMapAddr.h"
#include "NFGameServerInfo.h"
#include "NFLogicServerInfo.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "ServerInternal2.pb.h"

#define MAX_MAP_ADDR_NUM 1000
#define MAX_GAME_SERVER_NUM 100
#define MAX_LOGIC_SERVER_NUM 100

class NFServerAddrMgr : public NFShmObjTemplate<NFServerAddrMgr, EOT_NFMapAddrMgr_ID, NFShmObj>
{
public:
    NFServerAddrMgr();
    
    virtual ~NFServerAddrMgr();
    
    int CreateInit();
    
    int ResumeInit();
public:
    int AddMapAddr(uint64_t mapId, uint32_t busId, uint32_t zid, bool isCrossServer);
    NFMapAddr *GetMapAddr(uint64_t mapId);
    NFMapAddr *InsertMapAddr(uint64_t mapId);
    int GetAllMapInfo(proto_ff::RegisterCrossMapInfoReq& req, uint32_t zid);
public:
    bool IsStaticMapId(uint64_t mapId);
    uint32_t GetSuitGameIdByZid(uint64_t mapId, uint32_t zid);
    uint32_t GetSuitGameIdByCross(uint64_t mapId, bool crossServer);
private:
    NFShmHashMap<uint64_t, NFMapAddr, MAX_MAP_ADDR_NUM> m_mapAddrMap;
    NFShmHashMap<uint32_t, NFGameServerInfo, MAX_GAME_SERVER_NUM> m_gameServerMap;
    NFShmHashMap<uint32_t, NFLogicServerInfo, MAX_LOGIC_SERVER_NUM> m_logicServerMap;
};