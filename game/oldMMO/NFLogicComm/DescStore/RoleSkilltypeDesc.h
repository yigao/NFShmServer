#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
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
	const proto_ff_s::E_RoleSkilltype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSkilltype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSkilltype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSkilltype_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleSkilltypeDesc, proto_ff_s::E_RoleSkilltype_s, E_RoleSkilltype, MAX_ROLE_SKILLTYPE_NUM);
DECLARE_IDCREATE(RoleSkilltypeDesc);
};
