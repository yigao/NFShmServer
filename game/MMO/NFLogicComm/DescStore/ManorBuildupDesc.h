#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_BUILDUP_NUM 20

class ManorBuildupDesc : public NFIDescStore
{
public:
	ManorBuildupDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorBuildupDesc();
	const proto_ff_s::manorbuildUp_s* GetDesc(int id) const;
	proto_ff_s::manorbuildUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorbuildUp_s, MAX_MANOR_BUILDUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorbuildUp_s, MAX_MANOR_BUILDUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorbuildUp_s, manorbuildUp, MAX_MANOR_BUILDUP_NUM);
DECLARE_IDCREATE(ManorBuildupDesc);
};
