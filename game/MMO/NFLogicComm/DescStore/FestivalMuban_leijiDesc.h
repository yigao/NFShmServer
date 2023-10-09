#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LEIJI_NUM 16

class FestivalMuban_leijiDesc : public NFIDescStore
{
public:
	FestivalMuban_leijiDesc();
	virtual ~FestivalMuban_leijiDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_leiji_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_leiji_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_leiji_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_leiji_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_leijiDesc, proto_ff_s::E_FestivalMuban_leiji_s, E_FestivalMuban_leiji, MAX_FESTIVAL_MUBAN_LEIJI_NUM);
DECLARE_IDCREATE(FestivalMuban_leijiDesc);
};
