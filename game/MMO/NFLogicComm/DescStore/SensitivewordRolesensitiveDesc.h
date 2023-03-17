#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/sensitiveword_s.h"

#define MAX_SENSITIVEWORD_ROLESENSITIVE_NUM 300

class SensitivewordRolesensitiveDesc : public NFIDescStore
{
public:
	SensitivewordRolesensitiveDesc();
	virtual ~SensitivewordRolesensitiveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SensitivewordRolesensitive_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SensitivewordRolesensitive_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SensitivewordRolesensitive_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SensitivewordRolesensitive_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(SensitivewordRolesensitiveDesc, proto_ff_s::E_SensitivewordRolesensitive_s, E_SensitivewordRolesensitive, MAX_SENSITIVEWORD_ROLESENSITIVE_NUM);
DECLARE_IDCREATE(SensitivewordRolesensitiveDesc);
};
