#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_EGG_NUM 20

class ManorEggDesc : public NFIDescStore
{
public:
	ManorEggDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorEggDesc();
	const proto_ff_s::manoregg_s* GetDesc(int id) const;
	proto_ff_s::manoregg_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manoregg_s, MAX_MANOR_EGG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manoregg_s, MAX_MANOR_EGG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manoregg_s, manoregg, MAX_MANOR_EGG_NUM);
DECLARE_IDCREATE(ManorEggDesc);
};
