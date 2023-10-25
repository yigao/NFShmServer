#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEALSUIT_NUM 1024

class EquipimproveSealsuitDesc : public NFIDescStore
{
public:
	EquipimproveSealsuitDesc();
	virtual ~EquipimproveSealsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipimproveSealsuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipimproveSealsuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipimproveSealsuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipimproveSealsuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipimproveSealsuitDesc, proto_ff_s::E_EquipimproveSealsuit_s, E_EquipimproveSealsuit, MAX_EQUIPIMPROVE_SEALSUIT_NUM);
DECLARE_IDCREATE_GLOBAL(EquipimproveSealsuitDesc);
};
