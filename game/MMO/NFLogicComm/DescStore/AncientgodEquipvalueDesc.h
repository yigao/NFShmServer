#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_EQUIPVALUE_NUM 64

class AncientgodEquipvalueDesc : public NFIDescStore
{
public:
	AncientgodEquipvalueDesc();
	virtual ~AncientgodEquipvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodEquipvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodEquipvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodEquipvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodEquipvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodEquipvalueDesc, proto_ff_s::E_AncientgodEquipvalue_s, E_AncientgodEquipvalue, MAX_ANCIENTGOD_EQUIPVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(AncientgodEquipvalueDesc);
};
