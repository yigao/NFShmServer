#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/area_s.h"

#define MAX_AREA_AREA_NUM 20

class AreaAreaDesc : public NFIDescStore
{
public:
	AreaAreaDesc();
	virtual ~AreaAreaDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AreaArea_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AreaArea_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AreaArea_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AreaArea_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AreaAreaDesc, proto_ff_s::E_AreaArea_s, E_AreaArea, MAX_AREA_AREA_NUM);
DECLARE_IDCREATE(AreaAreaDesc);
};
