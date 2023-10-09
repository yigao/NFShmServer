#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_BANQUET_NUM 32

class MarryBanquetDesc : public NFIDescStore
{
public:
	MarryBanquetDesc();
	virtual ~MarryBanquetDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryBanquet_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryBanquet_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryBanquet_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryBanquet_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryBanquetDesc, proto_ff_s::E_MarryBanquet_s, E_MarryBanquet, MAX_MARRY_BANQUET_NUM);
DECLARE_IDCREATE(MarryBanquetDesc);
};
