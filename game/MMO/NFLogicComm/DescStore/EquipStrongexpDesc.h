#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONGEXP_NUM 800

class EquipStrongexpDesc : public NFIDescStore
{
public:
	EquipStrongexpDesc();
	virtual ~EquipStrongexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStrongexp_s* GetDesc(int id) const;
	proto_ff_s::E_EquipStrongexp_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipStrongexp_s, E_EquipStrongexp, MAX_EQUIP_STRONGEXP_NUM);
DECLARE_IDCREATE(EquipStrongexpDesc);
};
