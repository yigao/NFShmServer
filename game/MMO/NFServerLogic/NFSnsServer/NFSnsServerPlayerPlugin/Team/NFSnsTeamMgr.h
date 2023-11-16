// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTeamMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTeamMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFSnsTeamMgr : public NFShmObjTemplate<NFSnsTeamMgr, EOT_NFSnsTeamMgr_ID, NFShmObj>
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