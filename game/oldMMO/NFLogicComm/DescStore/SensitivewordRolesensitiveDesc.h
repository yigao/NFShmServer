#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/sensitiveword_s.h"

#define MAX_SENSITIVEWORD_ROLESENSITIVE_NUM 300

class SensitivewordRolesensitiveDesc : public NFIDescStore
{
public:
	SensitivewordRolesensitiveDesc(NFIPluginManager* pPluginManager);
	virtual ~SensitivewordRolesensitiveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::sensitivewordrolesensitive_s* GetDesc(int id) const;
	proto_ff_s::sensitivewordrolesensitive_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::sensitivewordrolesensitive_s, MAX_SENSITIVEWORD_ROLESENSITIVE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::sensitivewordrolesensitive_s, MAX_SENSITIVEWORD_ROLESENSITIVE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::sensitivewordrolesensitive_s, sensitivewordrolesensitive, MAX_SENSITIVEWORD_ROLESENSITIVE_NUM);
DECLARE_IDCREATE(SensitivewordRolesensitiveDesc);
};
