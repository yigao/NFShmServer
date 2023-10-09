#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peractivity_s.h"

#define MAX_PERACTIVITY_PERACTIVITY_NUM 32

class PeractivityPeractivityDesc : public NFIDescStore
{
public:
	PeractivityPeractivityDesc();
	virtual ~PeractivityPeractivityDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PeractivityPeractivity_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PeractivityPeractivity_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PeractivityPeractivity_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PeractivityPeractivity_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PeractivityPeractivityDesc, proto_ff_s::E_PeractivityPeractivity_s, E_PeractivityPeractivity, MAX_PERACTIVITY_PERACTIVITY_NUM);
DECLARE_IDCREATE(PeractivityPeractivityDesc);
};
