#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_LV_NUM 512

class WaremblemLvDesc : public NFIDescStore
{
public:
	WaremblemLvDesc();
	virtual ~WaremblemLvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WaremblemLv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WaremblemLv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WaremblemLv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WaremblemLv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WaremblemLvDesc, proto_ff_s::E_WaremblemLv_s, E_WaremblemLv, MAX_WAREMBLEM_LV_NUM);
DECLARE_IDCREATE_GLOBAL(WaremblemLvDesc);
};
