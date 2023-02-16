#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_FacadeSoullv_s* GetDesc(int id) const;
	proto_ff_s::E_FacadeSoullv_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FacadeSoullv_s, E_FacadeSoullv, MAX_FACADE_SOULLV_NUM);
DECLARE_IDCREATE(FacadeSoullvDesc);
};
