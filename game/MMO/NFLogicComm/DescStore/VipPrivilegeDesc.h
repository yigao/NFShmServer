#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/vip_s.h"

#define MAX_VIP_PRIVILEGE_NUM 60

class VipPrivilegeDesc : public NFIDescStore
{
public:
	VipPrivilegeDesc();
	virtual ~VipPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_VipPrivilege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_VipPrivilege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_VipPrivilege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_VipPrivilege_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(VipPrivilegeDesc, proto_ff_s::E_VipPrivilege_s, E_VipPrivilege, MAX_VIP_PRIVILEGE_NUM);
DECLARE_IDCREATE(VipPrivilegeDesc);
};
