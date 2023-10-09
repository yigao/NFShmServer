#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_SEVER_NUM 64

class FestivalMuban_donate_severDesc : public NFIDescStore
{
public:
	FestivalMuban_donate_severDesc();
	virtual ~FestivalMuban_donate_severDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_donate_sever_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_donate_sever_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_donate_sever_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_donate_sever_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_donate_severDesc, proto_ff_s::E_FestivalMuban_donate_sever_s, E_FestivalMuban_donate_sever, MAX_FESTIVAL_MUBAN_DONATE_SEVER_NUM);
DECLARE_IDCREATE(FestivalMuban_donate_severDesc);
};
