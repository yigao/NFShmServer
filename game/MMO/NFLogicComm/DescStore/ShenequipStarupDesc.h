#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/shenequip_s.h"

#define MAX_SHENEQUIP_STARUP_NUM 80

class ShenequipStarupDesc : public NFIDescStore
{
public:
	ShenequipStarupDesc();
	virtual ~ShenequipStarupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ShenequipStarup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShenequipStarup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShenequipStarup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShenequipStarup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ShenequipStarup_s, E_ShenequipStarup, MAX_SHENEQUIP_STARUP_NUM);
DECLARE_IDCREATE(ShenequipStarupDesc);
};
