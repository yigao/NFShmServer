#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_EXP_NUM 2000

class RoleExpDesc : public NFIDescStore
{
public:
	RoleExpDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleExpDesc();
	const proto_ff_s::roleexp_s* GetDesc(int id) const;
	proto_ff_s::roleexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleexp_s, MAX_ROLE_EXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleexp_s, MAX_ROLE_EXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleexp_s, roleexp, MAX_ROLE_EXP_NUM);
DECLARE_IDCREATE(RoleExpDesc);
};
