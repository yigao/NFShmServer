#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_TAIDAOMALE_NUM 2048

class RoleTaidaomaleDesc : public NFIDescStore
{
public:
	RoleTaidaomaleDesc();
	virtual ~RoleTaidaomaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleTaidaomale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleTaidaomale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleTaidaomale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleTaidaomale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleTaidaomaleDesc, proto_ff_s::E_RoleTaidaomale_s, E_RoleTaidaomale, MAX_ROLE_TAIDAOMALE_NUM);
DECLARE_IDCREATE_GLOBAL(RoleTaidaomaleDesc);
};
