#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_IntimacyIntimacy_s* GetDesc(int id) const;
	proto_ff_s::E_IntimacyIntimacy_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_IntimacyIntimacy_s, intimacyintimacy, MAX_INTIMACY_INTIMACY_NUM);
DECLARE_IDCREATE(IntimacyIntimacyDesc);
};
