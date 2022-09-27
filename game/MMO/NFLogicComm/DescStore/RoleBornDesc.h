#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_BORN_NUM 20

class RoleBornDesc : public NFIDescStore
{
public:
	RoleBornDesc(NFIPluginManager* pPluginManager);
	virtual ~RoleBornDesc();
	const proto_ff_s::roleborn_s* GetDesc(int id) const;
	proto_ff_s::roleborn_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::roleborn_s, MAX_ROLE_BORN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::roleborn_s, MAX_ROLE_BORN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::roleborn_s, roleborn, MAX_ROLE_BORN_NUM);
DECLARE_IDCREATE(RoleBornDesc);
};
