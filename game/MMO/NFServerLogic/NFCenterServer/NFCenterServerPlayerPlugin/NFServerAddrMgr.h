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

#define MAX_MAP_ADDR_NUM 1000
#define MAX_GAME_SERVER_NUM 100
#define MAX_LOGIC_SERVER_NUM 100

class NFServerAddrMgr : public NFShmObj {
public:
    NFServerAddrMgr();

    virtual ~NFServerAddrMgr();

    int CreateInit();

    int ResumeInit();
public:
    int AddMapAddr(uint32_t mapId, uint32_t busId);
    NFMapAddr* GetMapAddr(uint32_t mapId);
    NFMapAddr* InsertMapAddr(uint32_t mapId);
private:
    NFShmHashMap<uint32_t, NFMapAddr, MAX_MAP_ADDR_NUM> m_mapAddrMap;
    NFShmHashMap<uint32_t, NFGameServerInfo, MAX_GAME_SERVER_NUM>  m_gameServerMap;
    NFShmHashMap<uint32_t, NFLogicServerInfo, MAX_LOGIC_SERVER_NUM>  m_logicServerMap;
private:
DECLARE_IDCREATE(NFServerAddrMgr)
};