#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_COSNTANT_NUM 2

class VipCosntantDesc : public NFIDescStore
{
public:
	VipCosntantDesc();
	virtual ~VipCosntantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_VipCosntant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_VipCosntant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_VipCosntant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_VipCosntant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(VipCosntantDesc, proto_ff_s::E_VipCosntant_s, E_VipCosntant, MAX_VIP_COSNTANT_NUM);
DECLARE_IDCREATE(VipCosntantDesc);
};
