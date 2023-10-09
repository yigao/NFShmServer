#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_VIP_NUM 16

class VipVipDesc : public NFIDescStore
{
public:
	VipVipDesc();
	virtual ~VipVipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_VipVip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_VipVip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_VipVip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_VipVip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(VipVipDesc, proto_ff_s::E_VipVip_s, E_VipVip, MAX_VIP_VIP_NUM);
DECLARE_IDCREATE(VipVipDesc);
};
