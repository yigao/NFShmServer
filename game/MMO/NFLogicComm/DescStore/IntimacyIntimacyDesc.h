#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/intimacy_s.h"

#define MAX_INTIMACY_INTIMACY_NUM 20

class IntimacyIntimacyDesc : public NFIDescStore
{
public:
	IntimacyIntimacyDesc();
	virtual ~IntimacyIntimacyDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_IntimacyIntimacy_s* GetDesc(int64_t id) const;
	proto_ff_s::E_IntimacyIntimacy_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_IntimacyIntimacy_s* GetDescByIndex(int index) const;
	proto_ff_s::E_IntimacyIntimacy_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(IntimacyIntimacyDesc, proto_ff_s::E_IntimacyIntimacy_s, E_IntimacyIntimacy, MAX_INTIMACY_INTIMACY_NUM);
DECLARE_IDCREATE(IntimacyIntimacyDesc);
};
