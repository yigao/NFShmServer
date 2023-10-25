#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULLV_NUM 512

class FacadeSoullvDesc : public NFIDescStore
{
public:
	FacadeSoullvDesc();
	virtual ~FacadeSoullvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FacadeSoullv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeSoullv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeSoullv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeSoullv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FacadeSoullvDesc, proto_ff_s::E_FacadeSoullv_s, E_FacadeSoullv, MAX_FACADE_SOULLV_NUM);
DECLARE_IDCREATE_GLOBAL(FacadeSoullvDesc);
};
