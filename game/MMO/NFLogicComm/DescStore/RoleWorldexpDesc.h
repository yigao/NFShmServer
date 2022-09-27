#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_WORLDEXP_NUM 600

class RoleWorldexpDesc : public NFIDescStore
{
public:
	RoleWorldexpDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleWorldexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::roleworldexp_s* GetDesc(int id) const;
	proto_ff_s::roleworldexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleworldexp_s, MAX_ROLE_WORLDEXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleworldexp_s, MAX_ROLE_WORLDEXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleworldexp_s, roleworldexp, MAX_ROLE_WORLDEXP_NUM);
DECLARE_IDCREATE(RoleWorldexpDesc);
};
