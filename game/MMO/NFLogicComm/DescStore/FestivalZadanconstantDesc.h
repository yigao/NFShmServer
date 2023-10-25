#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_ZADANCONSTANT_NUM 32

class FestivalZadanconstantDesc : public NFIDescStore
{
public:
	FestivalZadanconstantDesc();
	virtual ~FestivalZadanconstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalZadanconstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalZadanconstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalZadanconstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalZadanconstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalZadanconstantDesc, proto_ff_s::E_FestivalZadanconstant_s, E_FestivalZadanconstant, MAX_FESTIVAL_ZADANCONSTANT_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalZadanconstantDesc);
};
