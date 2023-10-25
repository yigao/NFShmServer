#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_PREPOSE_NUM 8

class ShenequipPreposeDesc : public NFIDescStore
{
public:
	ShenequipPreposeDesc();
	virtual ~ShenequipPreposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShenequipPrepose_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipPrepose_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipPrepose_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipPrepose_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShenequipPreposeDesc, proto_ff_s::E_ShenequipPrepose_s, E_ShenequipPrepose, MAX_SHENEQUIP_PREPOSE_NUM);
DECLARE_IDCREATE_GLOBAL(ShenequipPreposeDesc);
};
