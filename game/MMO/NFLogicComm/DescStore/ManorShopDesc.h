#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_SHOP_NUM 20

class ManorShopDesc : public NFIDescStore
{
public:
	ManorShopDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorShopDesc();
	const proto_ff_s::manorshop_s* GetDesc(int id) const;
	proto_ff_s::manorshop_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorshop_s, MAX_MANOR_SHOP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorshop_s, MAX_MANOR_SHOP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorshop_s, manorshop, MAX_MANOR_SHOP_NUM);
DECLARE_IDCREATE(ManorShopDesc);
};
