// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTeamMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTeamMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <DBProxy2_s.h>
#include <NFServerComm/NFServerCommon/NFBaseDBObj.h>

#include <ObService/NFObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFServerLogicMessage/DBProxy2.pb.h"

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
public:
    virtual int LoadFromDB(const std::string& dbData);

    virtual int SaveToDB(std::string& dbData);

    virtual int CheckWhenAllDataLoaded();

    virtual int InitConfig();
public:
    proto_ff_s::tbSnsTeam_s m_teamData;
};