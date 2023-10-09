#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/team_s.h"

#define MAX_TEAM_TEAM_NUM 20

class TeamTeamDesc : public NFIDescStore
{
public:
	TeamTeamDesc();
	virtual ~TeamTeamDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TeamTeam_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TeamTeam_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TeamTeam_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TeamTeam_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(TeamTeamDesc, proto_ff_s::E_TeamTeam_s, E_TeamTeam, MAX_TEAM_TEAM_NUM);
DECLARE_IDCREATE(TeamTeamDesc);
};
