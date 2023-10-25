#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_ATT_NUM 4096

class ShenequipAttDesc : public NFIDescStore
{
public:
	ShenequipAttDesc();
	virtual ~ShenequipAttDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShenequipAtt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipAtt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipAtt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipAtt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShenequipAttDesc, proto_ff_s::E_ShenequipAtt_s, E_ShenequipAtt, MAX_SHENEQUIP_ATT_NUM);
DECLARE_IDCREATE_GLOBAL(ShenequipAttDesc);
};
