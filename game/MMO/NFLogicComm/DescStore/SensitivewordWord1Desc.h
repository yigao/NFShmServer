#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Sensitiveword_s.h"

#define MAX_SENSITIVEWORD_WORD1_NUM 32768

class SensitivewordWord1Desc : public NFIDescStore
{
public:
	SensitivewordWord1Desc();
	virtual ~SensitivewordWord1Desc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SensitivewordWord1_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SensitivewordWord1_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SensitivewordWord1_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SensitivewordWord1_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SensitivewordWord1Desc, proto_ff_s::E_SensitivewordWord1_s, E_SensitivewordWord1, MAX_SENSITIVEWORD_WORD1_NUM);
DECLARE_IDCREATE_GLOBAL(SensitivewordWord1Desc);
};
