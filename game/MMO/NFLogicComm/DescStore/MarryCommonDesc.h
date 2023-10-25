#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_COMMON_NUM 512

class MarryCommonDesc : public NFIDescStore
{
public:
	MarryCommonDesc();
	virtual ~MarryCommonDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryCommon_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryCommon_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryCommon_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryCommon_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryCommonDesc, proto_ff_s::E_MarryCommon_s, E_MarryCommon, MAX_MARRY_COMMON_NUM);
DECLARE_IDCREATE_GLOBAL(MarryCommonDesc);
};
