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
	const proto_ff_s::sensitivewordrolesensitive_s* GetDesc(int id) const;
	proto_ff_s::sensitivewordrolesensitive_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::sensitivewordrolesensitive_s, sensitivewordrolesensitive, MAX_SENSITIVEWORD_ROLESENSITIVE_NUM);
DECLARE_IDCREATE(SensitivewordRolesensitiveDesc);
};
