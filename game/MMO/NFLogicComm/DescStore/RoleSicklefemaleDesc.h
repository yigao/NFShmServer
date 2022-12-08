#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SICKLEFEMALE_NUM 2000

class RoleSicklefemaleDesc : public NFIDescStore
{
public:
	RoleSicklefemaleDesc();
	virtual ~RoleSicklefemaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rolesickleFemale_s* GetDesc(int id) const;
	proto_ff_s::rolesickleFemale_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::rolesickleFemale_s, rolesickleFemale, MAX_ROLE_SICKLEFEMALE_NUM);
DECLARE_IDCREATE(RoleSicklefemaleDesc);
};
