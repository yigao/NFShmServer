#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Jinglian_s.h"

#define MAX_JINGLIAN_RACE_NUM 8

class JinglianRaceDesc : public NFIDescStore
{
public:
	JinglianRaceDesc();
	virtual ~JinglianRaceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_JinglianRace_s* GetDesc(int64_t id) const;
	proto_ff_s::E_JinglianRace_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_JinglianRace_s* GetDescByIndex(int index) const;
	proto_ff_s::E_JinglianRace_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(JinglianRaceDesc, proto_ff_s::E_JinglianRace_s, E_JinglianRace, MAX_JINGLIAN_RACE_NUM);
DECLARE_IDCREATE(JinglianRaceDesc);
};
