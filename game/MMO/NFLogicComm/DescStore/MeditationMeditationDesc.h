#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/meditation_s.h"

#define MAX_MEDITATION_MEDITATION_NUM 20

class MeditationMeditationDesc : public NFIDescStore
{
public:
	MeditationMeditationDesc();
	virtual ~MeditationMeditationDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MeditationMeditation_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MeditationMeditation_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MeditationMeditation_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MeditationMeditation_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MeditationMeditation_s, E_MeditationMeditation, MAX_MEDITATION_MEDITATION_NUM);
DECLARE_IDCREATE(MeditationMeditationDesc);
};
