#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SWORDFEMALE_NUM 2000

class RoleSwordfemaleDesc : public NFIDescStore
{
public:
	RoleSwordfemaleDesc();
	virtual ~RoleSwordfemaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleSwordfemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSwordfemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSwordfemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSwordfemale_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleSwordfemaleDesc, proto_ff_s::E_RoleSwordfemale_s, E_RoleSwordfemale, MAX_ROLE_SWORDFEMALE_NUM);
DECLARE_IDCREATE(RoleSwordfemaleDesc);
};
