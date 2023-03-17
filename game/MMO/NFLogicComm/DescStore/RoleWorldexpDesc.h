#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_WORLDEXP_NUM 600

class RoleWorldexpDesc : public NFIDescStore
{
public:
	RoleWorldexpDesc();
	virtual ~RoleWorldexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleWorldexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleWorldexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleWorldexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleWorldexp_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleWorldexpDesc, proto_ff_s::E_RoleWorldexp_s, E_RoleWorldexp, MAX_ROLE_WORLDEXP_NUM);
DECLARE_IDCREATE(RoleWorldexpDesc);
};
