#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/sensitiveword_s.h"

#define MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM 60000

class SensitivewordSensitive_wordDesc : public NFIDescStore
{
public:
	SensitivewordSensitive_wordDesc(NFIPluginManager* pPluginManager);
	virtual ~SensitivewordSensitive_wordDesc();
	const proto_ff_s::sensitivewordsensitive_word_s* GetDesc(int id) const;
	proto_ff_s::sensitivewordsensitive_word_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::sensitivewordsensitive_word_s, MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::sensitivewordsensitive_word_s, MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::sensitivewordsensitive_word_s, sensitivewordsensitive_word, MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM);
DECLARE_IDCREATE(SensitivewordSensitive_wordDesc);
};
