#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/privilege_s.h"

#define MAX_PRIVILEGE_PRIVILEGE_NUM 20

class PrivilegePrivilegeDesc : public NFIDescStore
{
public:
	PrivilegePrivilegeDesc(NFIPluginManager* pPluginManager);
	virtual ~PrivilegePrivilegeDesc();
	const proto_ff_s::privilegeprivilege_s* GetDesc(int id) const;
	proto_ff_s::privilegeprivilege_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::privilegeprivilege_s, MAX_PRIVILEGE_PRIVILEGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::privilegeprivilege_s, MAX_PRIVILEGE_PRIVILEGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::privilegeprivilege_s, privilegeprivilege, MAX_PRIVILEGE_PRIVILEGE_NUM);
DECLARE_IDCREATE(PrivilegePrivilegeDesc);
};
