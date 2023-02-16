#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_MASTERFEMALE_NUM 2000

class RoleMasterfemaleDesc : public NFIDescStore
{
public:
	RoleMasterfemaleDesc();
	virtual ~RoleMasterfemaleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleMasterfemale_s* GetDesc(int id) const;
	proto_ff_s::E_RoleMasterfemale_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_RoleMasterfemale_s, E_RoleMasterfemale, MAX_ROLE_MASTERFEMALE_NUM);
DECLARE_IDCREATE(RoleMasterfemaleDesc);
};
