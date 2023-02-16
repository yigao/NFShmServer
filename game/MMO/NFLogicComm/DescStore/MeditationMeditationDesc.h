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
	const proto_ff_s::E_MeditationMeditation_s* GetDesc(int id) const;
	proto_ff_s::E_MeditationMeditation_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MeditationMeditation_s, meditationmeditation, MAX_MEDITATION_MEDITATION_NUM);
DECLARE_IDCREATE(MeditationMeditationDesc);
};
