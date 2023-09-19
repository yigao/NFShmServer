#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_SOULACHIEVEMENT_NUM 160

class FacadeSoulachievementDesc : public NFIDescStore
{
public:
	FacadeSoulachievementDesc();
	virtual ~FacadeSoulachievementDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FacadeSoulachievement_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FacadeSoulachievement_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FacadeSoulachievement_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FacadeSoulachievement_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FacadeSoulachievementDesc, proto_ff_s::E_FacadeSoulachievement_s, E_FacadeSoulachievement, MAX_FACADE_SOULACHIEVEMENT_NUM);
DECLARE_IDCREATE(FacadeSoulachievementDesc);
};
