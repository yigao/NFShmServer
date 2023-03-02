#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_MASTERMALE_NUM 2000

class RoleMastermaleDesc : public NFIDescStore
{
public:
	RoleMastermaleDesc();
	virtual ~RoleMastermaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleMastermale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleMastermale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleMastermale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleMastermale_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleMastermale_s, E_RoleMastermale, MAX_ROLE_MASTERMALE_NUM);
DECLARE_IDCREATE(RoleMastermaleDesc);
};
