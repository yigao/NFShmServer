#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/witch_s.h"

#define MAX_WITCH_SUMMON_NUM 20

class WitchSummonDesc : public NFIDescStore
{
public:
	WitchSummonDesc(NFIPluginManager* pPluginManager);
	virtual ~WitchSummonDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::witchsummon_s* GetDesc(int id) const;
	proto_ff_s::witchsummon_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::witchsummon_s, MAX_WITCH_SUMMON_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::witchsummon_s, MAX_WITCH_SUMMON_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::witchsummon_s, witchsummon, MAX_WITCH_SUMMON_NUM);
DECLARE_IDCREATE(WitchSummonDesc);
};
