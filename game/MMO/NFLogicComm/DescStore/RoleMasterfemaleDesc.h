#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_MASTERFEMALE_NUM 2048

class RoleMasterfemaleDesc : public NFIDescStore
{
public:
	RoleMasterfemaleDesc();
	virtual ~RoleMasterfemaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleMasterfemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleMasterfemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleMasterfemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleMasterfemale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleMasterfemaleDesc, proto_ff_s::E_RoleMasterfemale_s, E_RoleMasterfemale, MAX_ROLE_MASTERFEMALE_NUM);
DECLARE_IDCREATE(RoleMasterfemaleDesc);
};
