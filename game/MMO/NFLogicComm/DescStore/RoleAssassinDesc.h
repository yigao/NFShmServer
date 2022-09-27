#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_ASSASSIN_NUM 2000

class RoleAssassinDesc : public NFIDescStore
{
public:
	RoleAssassinDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleAssassinDesc();
	const proto_ff_s::roleassassin_s* GetDesc(int id) const;
	proto_ff_s::roleassassin_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleassassin_s, MAX_ROLE_ASSASSIN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleassassin_s, MAX_ROLE_ASSASSIN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleassassin_s, roleassassin, MAX_ROLE_ASSASSIN_NUM);
DECLARE_IDCREATE(RoleAssassinDesc);
};
