#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_MASTERMALE_NUM 2048

class RoleMastermaleDesc : public NFIDescStore
{
public:
	RoleMastermaleDesc();
	virtual ~RoleMastermaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleMastermale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleMastermale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleMastermale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleMastermale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleMastermaleDesc, proto_ff_s::E_RoleMastermale_s, E_RoleMastermale, MAX_ROLE_MASTERMALE_NUM);
DECLARE_IDCREATE(RoleMastermaleDesc);
};
