#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Sensitiveword_s.h"

#define MAX_SENSITIVEWORD_WORD2_NUM 32768

class SensitivewordWord2Desc : public NFIDescStore
{
public:
	SensitivewordWord2Desc();
	virtual ~SensitivewordWord2Desc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SensitivewordWord2_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SensitivewordWord2_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SensitivewordWord2_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SensitivewordWord2_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SensitivewordWord2Desc, proto_ff_s::E_SensitivewordWord2_s, E_SensitivewordWord2, MAX_SENSITIVEWORD_WORD2_NUM);
DECLARE_IDCREATE(SensitivewordWord2Desc);
};
