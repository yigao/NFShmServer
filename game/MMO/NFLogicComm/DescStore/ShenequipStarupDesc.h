#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_STARUP_NUM 128

class ShenequipStarupDesc : public NFIDescStore
{
public:
	ShenequipStarupDesc();
	virtual ~ShenequipStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShenequipStarup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipStarup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipStarup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipStarup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShenequipStarupDesc, proto_ff_s::E_ShenequipStarup_s, E_ShenequipStarup, MAX_SHENEQUIP_STARUP_NUM);
DECLARE_IDCREATE(ShenequipStarupDesc);
};
