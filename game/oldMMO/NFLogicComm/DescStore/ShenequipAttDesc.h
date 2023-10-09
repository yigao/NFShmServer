#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_ATT_NUM 11000

class ShenequipAttDesc : public NFIDescStore
{
public:
	ShenequipAttDesc();
	virtual ~ShenequipAttDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipAtt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipAtt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipAtt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipAtt_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ShenequipAttDesc, proto_ff_s::E_ShenequipAtt_s, E_ShenequipAtt, MAX_SHENEQUIP_ATT_NUM);
DECLARE_IDCREATE(ShenequipAttDesc);
};
