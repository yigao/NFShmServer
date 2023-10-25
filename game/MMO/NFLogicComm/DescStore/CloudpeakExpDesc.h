#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_EXP_NUM 512

class CloudpeakExpDesc : public NFIDescStore
{
public:
	CloudpeakExpDesc();
	virtual ~CloudpeakExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_CloudpeakExp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CloudpeakExp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CloudpeakExp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CloudpeakExp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(CloudpeakExpDesc, proto_ff_s::E_CloudpeakExp_s, E_CloudpeakExp, MAX_CLOUDPEAK_EXP_NUM);
DECLARE_IDCREATE_GLOBAL(CloudpeakExpDesc);
};
