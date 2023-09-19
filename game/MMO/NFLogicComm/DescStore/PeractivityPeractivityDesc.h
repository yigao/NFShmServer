#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/perActivity_s.h"

#define MAX_PERACTIVITY_PERACTIVITY_NUM 20

class PeractivityPeractivityDesc : public NFIDescStore
{
public:
	PeractivityPeractivityDesc();
	virtual ~PeractivityPeractivityDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PeractivityPeractivity_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PeractivityPeractivity_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PeractivityPeractivity_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PeractivityPeractivity_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PeractivityPeractivityDesc, proto_ff_s::E_PeractivityPeractivity_s, E_PeractivityPeractivity, MAX_PERACTIVITY_PERACTIVITY_NUM);
DECLARE_IDCREATE(PeractivityPeractivityDesc);
};
