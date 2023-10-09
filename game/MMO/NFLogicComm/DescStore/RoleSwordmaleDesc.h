#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Role_s.h"

#define MAX_ROLE_SWORDMALE_NUM 2048

class RoleSwordmaleDesc : public NFIDescStore
{
public:
	RoleSwordmaleDesc();
	virtual ~RoleSwordmaleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RoleSwordmale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSwordmale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSwordmale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSwordmale_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RoleSwordmaleDesc, proto_ff_s::E_RoleSwordmale_s, E_RoleSwordmale, MAX_ROLE_SWORDMALE_NUM);
DECLARE_IDCREATE(RoleSwordmaleDesc);
};
