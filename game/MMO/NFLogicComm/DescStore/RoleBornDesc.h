#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_BORN_NUM 20

class RoleBornDesc : public NFIDescStore
{
public:
	RoleBornDesc();
	virtual ~RoleBornDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleBorn_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleBorn_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleBorn_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleBorn_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleBornDesc, proto_ff_s::E_RoleBorn_s, E_RoleBorn, MAX_ROLE_BORN_NUM);
DECLARE_IDCREATE(RoleBornDesc);
};
