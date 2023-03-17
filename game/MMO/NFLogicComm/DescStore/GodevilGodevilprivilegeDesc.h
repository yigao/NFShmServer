#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godevil_s.h"

#define MAX_GODEVIL_GODEVILPRIVILEGE_NUM 40

class GodevilGodevilprivilegeDesc : public NFIDescStore
{
public:
	GodevilGodevilprivilegeDesc();
	virtual ~GodevilGodevilprivilegeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodevilGodevilprivilege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilGodevilprivilege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilGodevilprivilege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilGodevilprivilege_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodevilGodevilprivilegeDesc, proto_ff_s::E_GodevilGodevilprivilege_s, E_GodevilGodevilprivilege, MAX_GODEVIL_GODEVILPRIVILEGE_NUM);
DECLARE_IDCREATE(GodevilGodevilprivilegeDesc);
};
