#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STOVEEXP_NUM 128

class EquipStoveexpDesc : public NFIDescStore
{
public:
	EquipStoveexpDesc();
	virtual ~EquipStoveexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipStoveexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStoveexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStoveexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStoveexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipStoveexpDesc, proto_ff_s::E_EquipStoveexp_s, E_EquipStoveexp, MAX_EQUIP_STOVEEXP_NUM);
DECLARE_IDCREATE_GLOBAL(EquipStoveexpDesc);
};
