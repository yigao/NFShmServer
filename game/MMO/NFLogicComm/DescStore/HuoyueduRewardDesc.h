#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/huoyuedu_s.h"

#define MAX_HUOYUEDU_REWARD_NUM 20

class HuoyueduRewardDesc : public NFIDescStore
{
public:
	HuoyueduRewardDesc(NFIPluginManager* pPluginManager);
	virtual ~HuoyueduRewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::huoyuedureward_s* GetDesc(int id) const;
	proto_ff_s::huoyuedureward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::huoyuedureward_s, MAX_HUOYUEDU_REWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::huoyuedureward_s, MAX_HUOYUEDU_REWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::huoyuedureward_s, huoyuedureward, MAX_HUOYUEDU_REWARD_NUM);
DECLARE_IDCREATE(HuoyueduRewardDesc);
};
