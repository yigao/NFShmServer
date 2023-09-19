#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_ADDSKILL_NUM 20

class RoleAddskillDesc : public NFIDescStore
{
public:
	RoleAddskillDesc();
	virtual ~RoleAddskillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleAddskill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleAddskill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleAddskill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleAddskill_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleAddskillDesc, proto_ff_s::E_RoleAddskill_s, E_RoleAddskill, MAX_ROLE_ADDSKILL_NUM);
DECLARE_IDCREATE(RoleAddskillDesc);
};
