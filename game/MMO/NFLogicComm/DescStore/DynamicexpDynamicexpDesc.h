#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dynamicexp_s.h"

#define MAX_DYNAMICEXP_DYNAMICEXP_NUM 2000

class DynamicexpDynamicexpDesc : public NFIDescStore
{
public:
	DynamicexpDynamicexpDesc(NFIPluginManager* pPluginManager);
	virtual ~DynamicexpDynamicexpDesc();
	const proto_ff_s::dynamicexpdynamicexp_s* GetDesc(int id) const;
	proto_ff_s::dynamicexpdynamicexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::dynamicexpdynamicexp_s, MAX_DYNAMICEXP_DYNAMICEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::dynamicexpdynamicexp_s, MAX_DYNAMICEXP_DYNAMICEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::dynamicexpdynamicexp_s, dynamicexpdynamicexp, MAX_DYNAMICEXP_DYNAMICEXP_NUM);
DECLARE_IDCREATE(DynamicexpDynamicexpDesc);
};
