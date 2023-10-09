#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SOARING_NUM 32

class EquipimproveSoaringDesc : public NFIDescStore
{
public:
	EquipimproveSoaringDesc();
	virtual ~EquipimproveSoaringDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipimproveSoaring_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipimproveSoaring_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipimproveSoaring_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipimproveSoaring_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipimproveSoaringDesc, proto_ff_s::E_EquipimproveSoaring_s, E_EquipimproveSoaring, MAX_EQUIPIMPROVE_SOARING_NUM);
DECLARE_IDCREATE(EquipimproveSoaringDesc);
};