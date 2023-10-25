#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_ADVANCELV_NUM 16

class GodevilAdvancelvDesc : public NFIDescStore
{
public:
	GodevilAdvancelvDesc();
	virtual ~GodevilAdvancelvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilAdvancelv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilAdvancelv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilAdvancelv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilAdvancelv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilAdvancelvDesc, proto_ff_s::E_GodevilAdvancelv_s, E_GodevilAdvancelv, MAX_GODEVIL_ADVANCELV_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilAdvancelvDesc);
};
