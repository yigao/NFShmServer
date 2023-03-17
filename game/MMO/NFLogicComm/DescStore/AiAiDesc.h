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
	const proto_ff_s::E_AiAi_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AiAi_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AiAi_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AiAi_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AiAiDesc, proto_ff_s::E_AiAi_s, E_AiAi, MAX_AI_AI_NUM);
DECLARE_IDCREATE(AiAiDesc);
};
