#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_TAIDAOFEMALE_NUM 2048

class RoleTaidaofemaleDesc : public NFIDescStore
{
public:
	RoleTaidaofemaleDesc();
	virtual ~RoleTaidaofemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleTaidaofemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleTaidaofemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleTaidaofemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleTaidaofemale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleTaidaofemaleDesc, proto_ff_s::E_RoleTaidaofemale_s, E_RoleTaidaofemale, MAX_ROLE_TAIDAOFEMALE_NUM);
DECLARE_IDCREATE_GLOBAL(RoleTaidaofemaleDesc);
};
