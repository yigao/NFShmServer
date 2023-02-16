#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SWORDMALE_NUM 2000

class RoleSwordmaleDesc : public NFIDescStore
{
public:
	RoleSwordmaleDesc();
	virtual ~RoleSwordmaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleSwordmale_s* GetDesc(int id) const;
	proto_ff_s::E_RoleSwordmale_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleSwordmale_s, roleswordMale, MAX_ROLE_SWORDMALE_NUM);
DECLARE_IDCREATE(RoleSwordmaleDesc);
};
