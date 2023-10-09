#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILPRIVILEGE_NUM 32

class GodevilGodevilprivilegeDesc : public NFIDescStore
{
public:
	GodevilGodevilprivilegeDesc();
	virtual ~GodevilGodevilprivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilGodevilprivilege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilGodevilprivilege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilGodevilprivilege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilGodevilprivilege_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilGodevilprivilegeDesc, proto_ff_s::E_GodevilGodevilprivilege_s, E_GodevilGodevilprivilege, MAX_GODEVIL_GODEVILPRIVILEGE_NUM);
DECLARE_IDCREATE(GodevilGodevilprivilegeDesc);
};
