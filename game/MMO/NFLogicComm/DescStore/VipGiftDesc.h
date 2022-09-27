#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/vip_s.h"

#define MAX_VIP_GIFT_NUM 80

class VipGiftDesc : public NFIDescStore
{
public:
	VipGiftDesc(NFIPluginManager* pPluginManager);
	virtual ~VipGiftDesc();
	const proto_ff_s::vipgift_s* GetDesc(int id) const;
	proto_ff_s::vipgift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::vipgift_s, MAX_VIP_GIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::vipgift_s, MAX_VIP_GIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::vipgift_s, vipgift, MAX_VIP_GIFT_NUM);
DECLARE_IDCREATE(VipGiftDesc);
};
