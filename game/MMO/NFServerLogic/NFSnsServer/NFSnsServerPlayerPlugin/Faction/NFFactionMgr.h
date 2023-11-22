// -------------------------------------------------------------------------
//    @FileName         :    NFFactionMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFFactionMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <NFGameCommon/NFComTypeDefine.h>
#include <ObService/NFSnsObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFFaction
{
public:
    int64_t Fight() { return 0; }				//帮派战力
    uint64_t LeaderCid() { return 0; }			//帮主cid
    std::string Name() { return std::string(); }				//帮派名字
    int32_t Level() { return 0; }					//帮派等级
};

class NFSnsFactionMgr : public NFShmObjTemplate<NFSnsFactionMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_FACTION, NFSnsObService>
{
public:
    NFSnsFactionMgr();
    
    virtual ~NFSnsFactionMgr();
    
    int CreateInit();
    int ResumeInit();

    uint32_t RoleFactionId(uint64_t cid) { return 0; }				  //获取角色的帮派ID
    void FactionAllMem(uint32_t factionid, SET_UINT64& setmem) { return; }//帮派所有成员
    NFFaction* GetFaction(uint32_t factionid) { return NULL; }				//获取帮派
    std::string GetFactionNameByCid(uint64_t cid) { return std::string(); }
};