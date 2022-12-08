#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONG_NUM 400

class EquipStrongDesc : public NFIDescStore
{
public:
	EquipStrongDesc();
	virtual ~EquipStrongDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::equipstrong_s* GetDesc(int id) const;
	proto_ff_s::equipstrong_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::equipstrong_s, equipstrong, MAX_EQUIP_STRONG_NUM);
DECLARE_IDCREATE(EquipStrongDesc);
};
