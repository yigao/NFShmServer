#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_TASKREWARD_NUM 8

class FestivalMuban_love_taskrewardDesc : public NFIDescStore
{
public:
	FestivalMuban_love_taskrewardDesc();
	virtual ~FestivalMuban_love_taskrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_love_taskreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_love_taskreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_love_taskreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_love_taskreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_love_taskrewardDesc, proto_ff_s::E_FestivalMuban_love_taskreward_s, E_FestivalMuban_love_taskreward, MAX_FESTIVAL_MUBAN_LOVE_TASKREWARD_NUM);
DECLARE_IDCREATE(FestivalMuban_love_taskrewardDesc);
};
