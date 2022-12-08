#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::facadesoulAchievement_s* GetDesc(int id) const;
	proto_ff_s::facadesoulAchievement_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadesoulAchievement_s, facadesoulAchievement, MAX_FACADE_SOULACHIEVEMENT_NUM);
DECLARE_IDCREATE(FacadeSoulachievementDesc);
};
