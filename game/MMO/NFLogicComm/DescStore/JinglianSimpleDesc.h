#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_SIMPLE_NUM 16

class JinglianSimpleDesc : public NFIDescStore
{
public:
	JinglianSimpleDesc();
	virtual ~JinglianSimpleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_JinglianSimple_s* GetDesc(int64_t id) const;
	proto_ff_s::E_JinglianSimple_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_JinglianSimple_s* GetDescByIndex(int index) const;
	proto_ff_s::E_JinglianSimple_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(JinglianSimpleDesc, proto_ff_s::E_JinglianSimple_s, E_JinglianSimple, MAX_JINGLIAN_SIMPLE_NUM);
DECLARE_IDCREATE_GLOBAL(JinglianSimpleDesc);
};
