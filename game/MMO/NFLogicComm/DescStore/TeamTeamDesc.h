#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/team_s.h"

#define MAX_TEAM_TEAM_NUM 40

class TeamTeamDesc : public NFIDescStore
{
public:
	TeamTeamDesc();
	virtual ~TeamTeamDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TeamTeam_s* GetDesc(int id) const;
	proto_ff_s::E_TeamTeam_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TeamTeam_s, teamteam, MAX_TEAM_TEAM_NUM);
DECLARE_IDCREATE(TeamTeamDesc);
};
