#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOULLV_NUM 140

class FacadeSoullvDesc : public NFIDescStore
{
public:
	FacadeSoullvDesc();
	virtual ~FacadeSoullvDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeSoullv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeSoullv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeSoullv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeSoullv_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FacadeSoullvDesc, proto_ff_s::E_FacadeSoullv_s, E_FacadeSoullv, MAX_FACADE_SOULLV_NUM);
DECLARE_IDCREATE(FacadeSoullvDesc);
};
