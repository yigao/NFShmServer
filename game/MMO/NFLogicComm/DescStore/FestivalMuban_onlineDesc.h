#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_ONLINE_NUM 4

class FestivalMuban_onlineDesc : public NFIDescStore
{
public:
	FestivalMuban_onlineDesc();
	virtual ~FestivalMuban_onlineDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_online_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_online_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_online_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_online_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_onlineDesc, proto_ff_s::E_FestivalMuban_online_s, E_FestivalMuban_online, MAX_FESTIVAL_MUBAN_ONLINE_NUM);
DECLARE_IDCREATE(FestivalMuban_onlineDesc);
};
