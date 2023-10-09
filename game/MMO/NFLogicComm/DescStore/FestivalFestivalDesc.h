#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_FESTIVAL_NUM 16

class FestivalFestivalDesc : public NFIDescStore
{
public:
	FestivalFestivalDesc();
	virtual ~FestivalFestivalDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalFestival_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalFestival_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalFestival_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalFestival_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalFestivalDesc, proto_ff_s::E_FestivalFestival_s, E_FestivalFestival, MAX_FESTIVAL_FESTIVAL_NUM);
DECLARE_IDCREATE(FestivalFestivalDesc);
};
