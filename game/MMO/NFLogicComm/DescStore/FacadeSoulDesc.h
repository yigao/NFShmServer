#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOUL_NUM 20

class FacadeSoulDesc : public NFIDescStore
{
public:
	FacadeSoulDesc();
	virtual ~FacadeSoulDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeSoul_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeSoul_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeSoul_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeSoul_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FacadeSoulDesc, proto_ff_s::E_FacadeSoul_s, E_FacadeSoul, MAX_FACADE_SOUL_NUM);
DECLARE_IDCREATE(FacadeSoulDesc);
};
