#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_PATBEASTUP_NUM 20

class ManorPatbeastupDesc : public NFIDescStore
{
public:
	ManorPatbeastupDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorPatbeastupDesc();
	const proto_ff_s::manorpatBeastUP_s* GetDesc(int id) const;
	proto_ff_s::manorpatBeastUP_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorpatBeastUP_s, MAX_MANOR_PATBEASTUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorpatBeastUP_s, MAX_MANOR_PATBEASTUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorpatBeastUP_s, manorpatBeastUP, MAX_MANOR_PATBEASTUP_NUM);
DECLARE_IDCREATE(ManorPatbeastupDesc);
};
