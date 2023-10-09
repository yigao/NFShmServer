#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ai_s.h"

#define MAX_AI_AI_NUM 16

class AiAiDesc : public NFIDescStore
{
public:
	AiAiDesc();
	virtual ~AiAiDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AiAi_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AiAi_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AiAi_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AiAi_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AiAiDesc, proto_ff_s::E_AiAi_s, E_AiAi, MAX_AI_AI_NUM);
DECLARE_IDCREATE(AiAiDesc);
};
