#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STAR_UP_NUM 32

class ShentiStar_upDesc : public NFIDescStore
{
public:
	ShentiStar_upDesc();
	virtual ~ShentiStar_upDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiStar_up_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiStar_up_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiStar_up_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiStar_up_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiStar_upDesc, proto_ff_s::E_ShentiStar_up_s, E_ShentiStar_up, MAX_SHENTI_STAR_UP_NUM);
DECLARE_IDCREATE(ShentiStar_upDesc);
};
