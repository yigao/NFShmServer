#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Team_s.h"

#define MAX_TEAM_TEAM_NUM 32

class TeamTeamDesc : public NFIDescTemplate<TeamTeamDesc, proto_ff_s::E_TeamTeam_s, EOT_CONST_TEAM_TEAM_DESC_ID, MAX_TEAM_TEAM_NUM>
{
public:
	TeamTeamDesc();
	virtual ~TeamTeamDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
