#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_TASK_NUM 16

class FestivalMuban_love_taskDesc : public NFIDescStore
{
public:
	FestivalMuban_love_taskDesc();
	virtual ~FestivalMuban_love_taskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_love_task_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_love_task_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_love_task_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_love_task_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_love_taskDesc, proto_ff_s::E_FestivalMuban_love_task_s, E_FestivalMuban_love_task, MAX_FESTIVAL_MUBAN_LOVE_TASK_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_love_taskDesc);
};
