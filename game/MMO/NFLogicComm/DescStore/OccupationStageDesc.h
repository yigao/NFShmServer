#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_STAGE_NUM 40

class OccupationStageDesc : public NFIDescStore
{
public:
	OccupationStageDesc();
	virtual ~OccupationStageDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_OccupationStage_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationStage_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationStage_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationStage_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_OccupationStage_s, E_OccupationStage, MAX_OCCUPATION_STAGE_NUM);
DECLARE_IDCREATE(OccupationStageDesc);
};
