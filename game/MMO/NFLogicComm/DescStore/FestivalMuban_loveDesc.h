#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_NUM 8

class FestivalMuban_loveDesc : public NFIDescStore
{
public:
	FestivalMuban_loveDesc();
	virtual ~FestivalMuban_loveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_love_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_love_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_love_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_love_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_loveDesc, proto_ff_s::E_FestivalMuban_love_s, E_FestivalMuban_love, MAX_FESTIVAL_MUBAN_LOVE_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_loveDesc);
};
