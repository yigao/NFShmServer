#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STOVEEXP_NUM 200

class EquipStoveexpDesc : public NFIDescStore
{
public:
	EquipStoveexpDesc();
	virtual ~EquipStoveexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStoveexp_s* GetDesc(int id) const;
	proto_ff_s::E_EquipStoveexp_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipStoveexp_s, E_EquipStoveexp, MAX_EQUIP_STOVEEXP_NUM);
DECLARE_IDCREATE(EquipStoveexpDesc);
};
