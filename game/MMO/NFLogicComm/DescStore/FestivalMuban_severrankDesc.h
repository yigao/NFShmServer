#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SEVERRANK_NUM 128

class FestivalMuban_severrankDesc : public NFIDescStore
{
public:
	FestivalMuban_severrankDesc();
	virtual ~FestivalMuban_severrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_severrank_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_severrank_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_severrank_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_severrank_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_severrankDesc, proto_ff_s::E_FestivalMuban_severrank_s, E_FestivalMuban_severrank, MAX_FESTIVAL_MUBAN_SEVERRANK_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_severrankDesc);
};
