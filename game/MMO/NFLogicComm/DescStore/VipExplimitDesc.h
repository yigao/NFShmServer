#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Vip_s.h"

#define MAX_VIP_EXPLIMIT_NUM 2048

class VipExplimitDesc : public NFIDescStore
{
public:
	VipExplimitDesc();
	virtual ~VipExplimitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_VipExplimit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_VipExplimit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_VipExplimit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_VipExplimit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(VipExplimitDesc, proto_ff_s::E_VipExplimit_s, E_VipExplimit, MAX_VIP_EXPLIMIT_NUM);
DECLARE_IDCREATE(VipExplimitDesc);
};
