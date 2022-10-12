#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_MASTER_NUM 2000

class RoleMasterDesc : public NFIDescStore
{
public:
	RoleMasterDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleMasterDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rolemaster_s* GetDesc(int id) const;
	proto_ff_s::rolemaster_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rolemaster_s, MAX_ROLE_MASTER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rolemaster_s, MAX_ROLE_MASTER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rolemaster_s, rolemaster, MAX_ROLE_MASTER_NUM);
DECLARE_IDCREATE(RoleMasterDesc);
};
