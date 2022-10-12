#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_WARRIOR_NUM 2000

class RoleWarriorDesc : public NFIDescStore
{
public:
	RoleWarriorDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleWarriorDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::rolewarrior_s* GetDesc(int id) const;
	proto_ff_s::rolewarrior_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::rolewarrior_s, MAX_ROLE_WARRIOR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::rolewarrior_s, MAX_ROLE_WARRIOR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::rolewarrior_s, rolewarrior, MAX_ROLE_WARRIOR_NUM);
DECLARE_IDCREATE(RoleWarriorDesc);
};
