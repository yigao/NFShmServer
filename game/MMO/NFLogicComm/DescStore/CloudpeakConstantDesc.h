#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_CONSTANT_NUM 256

class CloudpeakConstantDesc : public NFIDescStore
{
public:
	CloudpeakConstantDesc();
	virtual ~CloudpeakConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_CloudpeakConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CloudpeakConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CloudpeakConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CloudpeakConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(CloudpeakConstantDesc, proto_ff_s::E_CloudpeakConstant_s, E_CloudpeakConstant, MAX_CLOUDPEAK_CONSTANT_NUM);
DECLARE_IDCREATE(CloudpeakConstantDesc);
};
