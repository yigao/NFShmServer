#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_PRIVILEGE_NUM 8

class XiuzhenPrivilegeDesc : public NFIDescStore
{
public:
	XiuzhenPrivilegeDesc();
	virtual ~XiuzhenPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenPrivilege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenPrivilege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenPrivilege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenPrivilege_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenPrivilegeDesc, proto_ff_s::E_XiuzhenPrivilege_s, E_XiuzhenPrivilege, MAX_XIUZHEN_PRIVILEGE_NUM);
DECLARE_IDCREATE(XiuzhenPrivilegeDesc);
};
