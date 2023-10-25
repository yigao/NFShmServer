#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_STAGES_NUM 2048

class XiuzhenStagesDesc : public NFIDescStore
{
public:
	XiuzhenStagesDesc();
	virtual ~XiuzhenStagesDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenStages_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenStages_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenStages_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenStages_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenStagesDesc, proto_ff_s::E_XiuzhenStages_s, E_XiuzhenStages, MAX_XIUZHEN_STAGES_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenStagesDesc);
};
