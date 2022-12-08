#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::perActivityperActivity_s* GetDesc(int id) const;
	proto_ff_s::perActivityperActivity_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::perActivityperActivity_s, perActivityperActivity, MAX_PERACTIVITY_PERACTIVITY_NUM);
DECLARE_IDCREATE(PeractivityPeractivityDesc);
};
