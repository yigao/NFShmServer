#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_PRODUCT_NUM 40

class ManorProductDesc : public NFIDescStore
{
public:
	ManorProductDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorProductDesc();
	const proto_ff_s::manorproduct_s* GetDesc(int id) const;
	proto_ff_s::manorproduct_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorproduct_s, MAX_MANOR_PRODUCT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorproduct_s, MAX_MANOR_PRODUCT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorproduct_s, manorproduct, MAX_MANOR_PRODUCT_NUM);
DECLARE_IDCREATE(ManorProductDesc);
};
