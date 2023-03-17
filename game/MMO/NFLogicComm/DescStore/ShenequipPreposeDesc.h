#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_PREPOSE_NUM 20

class ShenequipPreposeDesc : public NFIDescStore
{
public:
	ShenequipPreposeDesc();
	virtual ~ShenequipPreposeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipPrepose_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipPrepose_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipPrepose_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipPrepose_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipPreposeDesc, proto_ff_s::E_ShenequipPrepose_s, E_ShenequipPrepose, MAX_SHENEQUIP_PREPOSE_NUM);
DECLARE_IDCREATE(ShenequipPreposeDesc);
};
