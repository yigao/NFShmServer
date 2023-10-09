#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_HOLYBEAST_NUM 32

class MallHolybeastDesc : public NFIDescStore
{
public:
	MallHolybeastDesc();
	virtual ~MallHolybeastDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MallHolybeast_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MallHolybeast_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MallHolybeast_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MallHolybeast_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MallHolybeastDesc, proto_ff_s::E_MallHolybeast_s, E_MallHolybeast, MAX_MALL_HOLYBEAST_NUM);
DECLARE_IDCREATE(MallHolybeastDesc);
};
