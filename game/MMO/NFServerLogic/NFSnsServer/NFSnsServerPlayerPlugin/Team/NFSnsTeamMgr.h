// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTeamMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTeamMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <ObService/NFObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFSnsTeamMgr : public NFShmObjTemplate<NFSnsTeamMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_TEAM, NFObService>
{
public:
    NFSnsTeamMgr();
    
    virtual ~NFSnsTeamMgr();
    
    int CreateInit();
    int ResumeInit();
public:
    //获取角色队伍ID
    uint32_t GetCharTeamID(uint64_t cid) { return 0; }
};