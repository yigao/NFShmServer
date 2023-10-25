#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SIGN_NUM 2

class FestivalMuban_signDesc : public NFIDescStore
{
public:
	FestivalMuban_signDesc();
	virtual ~FestivalMuban_signDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_sign_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_sign_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_sign_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_sign_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_signDesc, proto_ff_s::E_FestivalMuban_sign_s, E_FestivalMuban_sign, MAX_FESTIVAL_MUBAN_SIGN_NUM);
DECLARE_IDCREATE_GLOBAL(FestivalMuban_signDesc);
};
