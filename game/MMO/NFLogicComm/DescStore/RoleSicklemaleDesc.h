#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SICKLEMALE_NUM 2000

class RoleSicklemaleDesc : public NFIDescStore
{
public:
	RoleSicklemaleDesc();
	virtual ~RoleSicklemaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleSicklemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSicklemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSicklemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSicklemale_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleSicklemale_s, E_RoleSicklemale, MAX_ROLE_SICKLEMALE_NUM);
DECLARE_IDCREATE(RoleSicklemaleDesc);
};
