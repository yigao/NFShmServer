#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SKILLTYPE_NUM 200

class RoleSkilltypeDesc : public NFIDescStore
{
public:
	RoleSkilltypeDesc();
	virtual ~RoleSkilltypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleSkilltype_s* GetDesc(int id) const;
	proto_ff_s::E_RoleSkilltype_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleSkilltype_s, E_RoleSkilltype, MAX_ROLE_SKILLTYPE_NUM);
DECLARE_IDCREATE(RoleSkilltypeDesc);
};
