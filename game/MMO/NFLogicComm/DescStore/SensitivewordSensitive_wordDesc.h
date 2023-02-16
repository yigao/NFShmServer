#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/sensitiveword_s.h"

#define MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM 6000

class SensitivewordSensitive_wordDesc : public NFIDescStore
{
public:
	SensitivewordSensitive_wordDesc();
	virtual ~SensitivewordSensitive_wordDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SensitivewordSensitive_word_s* GetDesc(int id) const;
	proto_ff_s::E_SensitivewordSensitive_word_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_SensitivewordSensitive_word_s, E_SensitivewordSensitive_word, MAX_SENSITIVEWORD_SENSITIVE_WORD_NUM);
DECLARE_IDCREATE(SensitivewordSensitive_wordDesc);
};
