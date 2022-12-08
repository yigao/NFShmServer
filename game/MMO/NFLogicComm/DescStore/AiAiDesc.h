#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ai_s.h"

#define MAX_AI_AI_NUM 20

class AiAiDesc : public NFIDescStore
{
public:
	AiAiDesc();
	virtual ~AiAiDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::aiai_s* GetDesc(int id) const;
	proto_ff_s::aiai_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::aiai_s, aiai, MAX_AI_AI_NUM);
DECLARE_IDCREATE(AiAiDesc);
};
