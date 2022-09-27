#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/witch_s.h"

#define MAX_WITCH_AWARD_NUM 20

class WitchAwardDesc : public NFIDescStore
{
public:
	WitchAwardDesc(NFIPluginManager* pPluginManager);
	virtual ~WitchAwardDesc();
	const proto_ff_s::witchaward_s* GetDesc(int id) const;
	proto_ff_s::witchaward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::witchaward_s, MAX_WITCH_AWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::witchaward_s, MAX_WITCH_AWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::witchaward_s, witchaward, MAX_WITCH_AWARD_NUM);
DECLARE_IDCREATE(WitchAwardDesc);
};
