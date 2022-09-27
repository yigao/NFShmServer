#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/witch_s.h"

#define MAX_WITCH_REWARDEXP_NUM 2000

class WitchRewardexpDesc : public NFIDescStore
{
public:
	WitchRewardexpDesc(NFIPluginManager* pPluginManager);
	virtual ~WitchRewardexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::witchrewardExp_s* GetDesc(int id) const;
	proto_ff_s::witchrewardExp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::witchrewardExp_s, MAX_WITCH_REWARDEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::witchrewardExp_s, MAX_WITCH_REWARDEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::witchrewardExp_s, witchrewardExp, MAX_WITCH_REWARDEXP_NUM);
DECLARE_IDCREATE(WitchRewardexpDesc);
};
