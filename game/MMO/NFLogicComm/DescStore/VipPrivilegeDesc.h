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
	const proto_ff_s::E_VipPrivilege_s* GetDesc(int id) const;
	proto_ff_s::E_VipPrivilege_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_VipPrivilege_s, vipprivilege, MAX_VIP_PRIVILEGE_NUM);
DECLARE_IDCREATE(VipPrivilegeDesc);
};
