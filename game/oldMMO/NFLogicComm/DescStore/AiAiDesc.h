#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ai_s.h"

#define MAX_AI_AI_NUM 120

class AiAiDesc : public NFIDescStore
{
public:
	AiAiDesc(NFIPluginManager* pPluginManager);
	virtual ~AiAiDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::aiai_s* GetDesc(int id) const;
	proto_ff_s::aiai_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::aiai_s, MAX_AI_AI_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::aiai_s, MAX_AI_AI_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::aiai_s, aiai, MAX_AI_AI_NUM);
DECLARE_IDCREATE(AiAiDesc);
};
