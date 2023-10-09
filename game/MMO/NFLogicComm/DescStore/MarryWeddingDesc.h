#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_WEDDING_NUM 2

class MarryWeddingDesc : public NFIDescStore
{
public:
	MarryWeddingDesc();
	virtual ~MarryWeddingDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryWedding_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryWedding_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryWedding_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryWedding_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryWeddingDesc, proto_ff_s::E_MarryWedding_s, E_MarryWedding, MAX_MARRY_WEDDING_NUM);
DECLARE_IDCREATE(MarryWeddingDesc);
};
