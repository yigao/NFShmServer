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
#include <ObService/NFObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFSnsFactionMgr : public NFShmObjTemplate<NFSnsFactionMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_FACTION, NFObService>
{
public:
    NFSnsFactionMgr();
    
    virtual ~NFSnsFactionMgr();
    
    int CreateInit();
    int ResumeInit();

    uint32_t RoleFactionId(uint64_t cid) { return 0; }				  //获取角色的帮派ID
    void FactionAllMem(uint32_t factionid, SET_UINT64& setmem) { return; }//帮派所有成员
};