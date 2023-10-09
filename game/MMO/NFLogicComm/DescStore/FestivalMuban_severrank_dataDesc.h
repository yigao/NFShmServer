#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SEVERRANK_DATA_NUM 64

class FestivalMuban_severrank_dataDesc : public NFIDescStore
{
public:
	FestivalMuban_severrank_dataDesc();
	virtual ~FestivalMuban_severrank_dataDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalMuban_severrank_data_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalMuban_severrank_data_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalMuban_severrank_data_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalMuban_severrank_data_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalMuban_severrank_dataDesc, proto_ff_s::E_FestivalMuban_severrank_data_s, E_FestivalMuban_severrank_data, MAX_FESTIVAL_MUBAN_SEVERRANK_DATA_NUM);
DECLARE_IDCREATE(FestivalMuban_severrank_dataDesc);
};
