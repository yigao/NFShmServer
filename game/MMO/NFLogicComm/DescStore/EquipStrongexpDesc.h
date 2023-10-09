#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONGEXP_NUM 512

class EquipStrongexpDesc : public NFIDescStore
{
public:
	EquipStrongexpDesc();
	virtual ~EquipStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipStrongexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStrongexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStrongexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStrongexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipStrongexpDesc, proto_ff_s::E_EquipStrongexp_s, E_EquipStrongexp, MAX_EQUIP_STRONGEXP_NUM);
DECLARE_IDCREATE(EquipStrongexpDesc);
};
