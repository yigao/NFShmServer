#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SICKLEMALE_NUM 2048

class RoleSicklemaleDesc : public NFIDescStore
{
public:
	RoleSicklemaleDesc();
	virtual ~RoleSicklemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleSicklemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSicklemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSicklemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSicklemale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleSicklemaleDesc, proto_ff_s::E_RoleSicklemale_s, E_RoleSicklemale, MAX_ROLE_SICKLEMALE_NUM);
DECLARE_IDCREATE_GLOBAL(RoleSicklemaleDesc);
};
