#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_LOCKLV_NUM 1024

class MarryLocklvDesc : public NFIDescStore
{
public:
	MarryLocklvDesc();
	virtual ~MarryLocklvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryLocklv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryLocklv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryLocklv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryLocklv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryLocklvDesc, proto_ff_s::E_MarryLocklv_s, E_MarryLocklv, MAX_MARRY_LOCKLV_NUM);
DECLARE_IDCREATE(MarryLocklvDesc);
};
