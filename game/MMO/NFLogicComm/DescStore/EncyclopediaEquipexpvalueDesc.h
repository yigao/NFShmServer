#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_EQUIPEXPVALUE_NUM 64

class EncyclopediaEquipexpvalueDesc : public NFIDescStore
{
public:
	EncyclopediaEquipexpvalueDesc();
	virtual ~EncyclopediaEquipexpvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaEquipexpvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaEquipexpvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaEquipexpvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaEquipexpvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaEquipexpvalueDesc, proto_ff_s::E_EncyclopediaEquipexpvalue_s, E_EncyclopediaEquipexpvalue, MAX_ENCYCLOPEDIA_EQUIPEXPVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaEquipexpvalueDesc);
};
