#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_AreaArea_s* GetDesc(int id) const;
	proto_ff_s::E_AreaArea_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AreaArea_s, areaarea, MAX_AREA_AREA_NUM);
DECLARE_IDCREATE(AreaAreaDesc);
};
