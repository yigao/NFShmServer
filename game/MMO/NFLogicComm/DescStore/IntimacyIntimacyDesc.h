#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/intimacy_s.h"

#define MAX_INTIMACY_INTIMACY_NUM 20

class IntimacyIntimacyDesc : public NFIDescStore
{
public:
	IntimacyIntimacyDesc(NFIPluginManager* pPluginManager);
	virtual ~IntimacyIntimacyDesc();
	const proto_ff_s::intimacyintimacy_s* GetDesc(int id) const;
	proto_ff_s::intimacyintimacy_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::intimacyintimacy_s, MAX_INTIMACY_INTIMACY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::intimacyintimacy_s, MAX_INTIMACY_INTIMACY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::intimacyintimacy_s, intimacyintimacy, MAX_INTIMACY_INTIMACY_NUM);
DECLARE_IDCREATE(IntimacyIntimacyDesc);
};
