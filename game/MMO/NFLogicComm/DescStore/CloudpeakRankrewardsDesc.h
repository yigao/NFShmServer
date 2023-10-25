#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_RANKREWARDS_NUM 32

class CloudpeakRankrewardsDesc : public NFIDescStore
{
public:
	CloudpeakRankrewardsDesc();
	virtual ~CloudpeakRankrewardsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_CloudpeakRankrewards_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CloudpeakRankrewards_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CloudpeakRankrewards_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CloudpeakRankrewards_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(CloudpeakRankrewardsDesc, proto_ff_s::E_CloudpeakRankrewards_s, E_CloudpeakRankrewards, MAX_CLOUDPEAK_RANKREWARDS_NUM);
DECLARE_IDCREATE_GLOBAL(CloudpeakRankrewardsDesc);
};
