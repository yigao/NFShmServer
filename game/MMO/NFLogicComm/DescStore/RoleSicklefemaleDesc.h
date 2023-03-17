#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_SICKLEFEMALE_NUM 2000

class RoleSicklefemaleDesc : public NFIDescStore
{
public:
	RoleSicklefemaleDesc();
	virtual ~RoleSicklefemaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleSicklefemale_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleSicklefemale_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleSicklefemale_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleSicklefemale_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleSicklefemaleDesc, proto_ff_s::E_RoleSicklefemale_s, E_RoleSicklefemale, MAX_ROLE_SICKLEFEMALE_NUM);
DECLARE_IDCREATE(RoleSicklefemaleDesc);
};
