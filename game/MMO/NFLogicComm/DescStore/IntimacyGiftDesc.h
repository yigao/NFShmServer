#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/intimacy_s.h"

#define MAX_INTIMACY_GIFT_NUM 20

class IntimacyGiftDesc : public NFIDescStore
{
public:
	IntimacyGiftDesc(NFIPluginManager* pPluginManager);
	virtual ~IntimacyGiftDesc();
	const proto_ff_s::intimacygift_s* GetDesc(int id) const;
	proto_ff_s::intimacygift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::intimacygift_s, MAX_INTIMACY_GIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::intimacygift_s, MAX_INTIMACY_GIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::intimacygift_s, intimacygift, MAX_INTIMACY_GIFT_NUM);
DECLARE_IDCREATE(IntimacyGiftDesc);
};
