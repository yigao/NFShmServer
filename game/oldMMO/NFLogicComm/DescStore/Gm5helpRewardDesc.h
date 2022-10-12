#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/gm5Help_s.h"

#define MAX_GM5HELP_REWARD_NUM 20

class Gm5helpRewardDesc : public NFIDescStore
{
public:
	Gm5helpRewardDesc(NFIPluginManager* pPluginManager);
	virtual ~Gm5helpRewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::gm5Helpreward_s* GetDesc(int id) const;
	proto_ff_s::gm5Helpreward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::gm5Helpreward_s, MAX_GM5HELP_REWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::gm5Helpreward_s, MAX_GM5HELP_REWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::gm5Helpreward_s, gm5Helpreward, MAX_GM5HELP_REWARD_NUM);
DECLARE_IDCREATE(Gm5helpRewardDesc);
};
