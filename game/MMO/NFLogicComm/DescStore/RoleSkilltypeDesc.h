#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SKILLTYPE_NUM 200

class RoleSkilltypeDesc : public NFIDescStore
{
public:
	RoleSkilltypeDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleSkilltypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::roleskillType_s* GetDesc(int id) const;
	proto_ff_s::roleskillType_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleskillType_s, MAX_ROLE_SKILLTYPE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleskillType_s, MAX_ROLE_SKILLTYPE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleskillType_s, roleskillType, MAX_ROLE_SKILLTYPE_NUM);
DECLARE_IDCREATE(RoleSkilltypeDesc);
};
