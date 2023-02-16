#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_RoleAddskill_s* GetDesc(int id) const;
	proto_ff_s::E_RoleAddskill_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleAddskill_s, E_RoleAddskill, MAX_ROLE_ADDSKILL_NUM);
DECLARE_IDCREATE(RoleAddskillDesc);
};
