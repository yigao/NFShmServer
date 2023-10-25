#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_STAGE_NUM 32

class OccupationStageDesc : public NFIDescStore
{
public:
	OccupationStageDesc();
	virtual ~OccupationStageDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OccupationStage_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationStage_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationStage_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationStage_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OccupationStageDesc, proto_ff_s::E_OccupationStage_s, E_OccupationStage, MAX_OCCUPATION_STAGE_NUM);
DECLARE_IDCREATE_GLOBAL(OccupationStageDesc);
};
