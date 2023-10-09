#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DAILYTOTALRECHARGE_NUM 8

class FestivalMuban_dailytotalrechargeDesc : public NFIDescStore
{
public:
	FestivalMuban_dailytotalrechargeDesc();
	virtual ~FestivalMuban_dailytotalrechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_dailytotalrecharge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_dailytotalrecharge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_dailytotalrecharge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_dailytotalrecharge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_dailytotalrechargeDesc, proto_ff_s::E_FestivalMuban_dailytotalrecharge_s, E_FestivalMuban_dailytotalrecharge, MAX_FESTIVAL_MUBAN_DAILYTOTALRECHARGE_NUM);
DECLARE_IDCREATE(FestivalMuban_dailytotalrechargeDesc);
};
