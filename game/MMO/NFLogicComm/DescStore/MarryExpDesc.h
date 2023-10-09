#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXP_NUM 512

class MarryExpDesc : public NFIDescStore
{
public:
	MarryExpDesc();
	virtual ~MarryExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryExp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryExp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryExp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryExp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryExpDesc, proto_ff_s::E_MarryExp_s, E_MarryExp, MAX_MARRY_EXP_NUM);
DECLARE_IDCREATE(MarryExpDesc);
};
