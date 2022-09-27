#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/vip_s.h"

#define MAX_VIP_PRIVILEGE_NUM 400

class VipPrivilegeDesc : public NFIDescStore
{
public:
	VipPrivilegeDesc(NFIPluginManager* pPluginManager);
	virtual ~VipPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::vipprivilege_s* GetDesc(int id) const;
	proto_ff_s::vipprivilege_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::vipprivilege_s, MAX_VIP_PRIVILEGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::vipprivilege_s, MAX_VIP_PRIVILEGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::vipprivilege_s, vipprivilege, MAX_VIP_PRIVILEGE_NUM);
DECLARE_IDCREATE(VipPrivilegeDesc);
};
