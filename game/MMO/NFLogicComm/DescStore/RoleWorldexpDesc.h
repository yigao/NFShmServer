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
	const proto_ff_s::E_RoleWorldexp_s* GetDesc(int id) const;
	proto_ff_s::E_RoleWorldexp_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleWorldexp_s, roleworldexp, MAX_ROLE_WORLDEXP_NUM);
DECLARE_IDCREATE(RoleWorldexpDesc);
};
