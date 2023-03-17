#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOULACTIVE_NUM 40

class FacadeSoulactiveDesc : public NFIDescStore
{
public:
	FacadeSoulactiveDesc();
	virtual ~FacadeSoulactiveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeSoulactive_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeSoulactive_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeSoulactive_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeSoulactive_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FacadeSoulactiveDesc, proto_ff_s::E_FacadeSoulactive_s, E_FacadeSoulactive, MAX_FACADE_SOULACTIVE_NUM);
DECLARE_IDCREATE(FacadeSoulactiveDesc);
};
