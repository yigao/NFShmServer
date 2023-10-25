#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Meditation_s.h"

#define MAX_MEDITATION_MEDITATION_NUM 16

class MeditationMeditationDesc : public NFIDescStore
{
public:
	MeditationMeditationDesc();
	virtual ~MeditationMeditationDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MeditationMeditation_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MeditationMeditation_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MeditationMeditation_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MeditationMeditation_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MeditationMeditationDesc, proto_ff_s::E_MeditationMeditation_s, E_MeditationMeditation, MAX_MEDITATION_MEDITATION_NUM);
DECLARE_IDCREATE_GLOBAL(MeditationMeditationDesc);
};
