#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Talent_s.h"

#define MAX_TALENT_TALENT_NUM 64

class TalentTalentDesc : public NFIDescStore
{
public:
	TalentTalentDesc();
	virtual ~TalentTalentDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TalentTalent_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TalentTalent_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TalentTalent_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TalentTalent_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TalentTalentDesc, proto_ff_s::E_TalentTalent_s, E_TalentTalent, MAX_TALENT_TALENT_NUM);
DECLARE_IDCREATE_GLOBAL(TalentTalentDesc);
};
