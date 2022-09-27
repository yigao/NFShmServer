#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_REWARDEXP_NUM 2000

class EscortRewardexpDesc : public NFIDescStore
{
public:
	EscortRewardexpDesc(NFIPluginManager* pPluginManager);
	virtual ~EscortRewardexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::escortrewardExp_s* GetDesc(int id) const;
	proto_ff_s::escortrewardExp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::escortrewardExp_s, MAX_ESCORT_REWARDEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::escortrewardExp_s, MAX_ESCORT_REWARDEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::escortrewardExp_s, escortrewardExp, MAX_ESCORT_REWARDEXP_NUM);
DECLARE_IDCREATE(EscortRewardexpDesc);
};
