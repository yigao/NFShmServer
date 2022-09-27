#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/team_s.h"

#define MAX_TEAM_TEAM_NUM 40

class TeamTeamDesc : public NFIDescStore
{
public:
	TeamTeamDesc(NFIPluginManager* pPluginManager);
	virtual ~TeamTeamDesc();
	const proto_ff_s::teamteam_s* GetDesc(int id) const;
	proto_ff_s::teamteam_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::teamteam_s, MAX_TEAM_TEAM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::teamteam_s, MAX_TEAM_TEAM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::teamteam_s, teamteam, MAX_TEAM_TEAM_NUM);
DECLARE_IDCREATE(TeamTeamDesc);
};
