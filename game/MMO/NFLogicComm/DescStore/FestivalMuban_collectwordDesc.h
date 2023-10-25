#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_COLLECTWORD_NUM 16

class FestivalMuban_collectwordDesc : public NFIDescStore
{
public:
	FestivalMuban_collectwordDesc();
	virtual ~FestivalMuban_collectwordDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_collectword_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_collectword_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_collectword_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_collectword_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_collectwordDesc, proto_ff_s::E_FestivalMuban_collectword_s, E_FestivalMuban_collectword, MAX_FESTIVAL_MUBAN_COLLECTWORD_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_collectwordDesc);
};
