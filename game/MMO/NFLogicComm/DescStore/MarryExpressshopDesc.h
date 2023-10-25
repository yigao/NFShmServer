#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXPRESSSHOP_NUM 4

class MarryExpressshopDesc : public NFIDescStore
{
public:
	MarryExpressshopDesc();
	virtual ~MarryExpressshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryExpressshop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryExpressshop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryExpressshop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryExpressshop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryExpressshopDesc, proto_ff_s::E_MarryExpressshop_s, E_MarryExpressshop, MAX_MARRY_EXPRESSSHOP_NUM);
DECLARE_IDCREATE_GLOBAL(MarryExpressshopDesc);
};
