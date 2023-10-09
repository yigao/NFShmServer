#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_CONSTANT_NUM 2

class Pk3v3ConstantDesc : public NFIDescStore
{
public:
	Pk3v3ConstantDesc();
	virtual ~Pk3v3ConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk3v3Constant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk3v3Constant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk3v3Constant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk3v3Constant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk3v3ConstantDesc, proto_ff_s::E_Pk3v3Constant_s, E_Pk3v3Constant, MAX_PK3V3_CONSTANT_NUM);
DECLARE_IDCREATE(Pk3v3ConstantDesc);
};
