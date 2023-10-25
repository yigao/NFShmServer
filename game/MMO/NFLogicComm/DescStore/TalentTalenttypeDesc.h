#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Talent_s.h"

#define MAX_TALENT_TALENTTYPE_NUM 4

class TalentTalenttypeDesc : public NFIDescStore
{
public:
	TalentTalenttypeDesc();
	virtual ~TalentTalenttypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TalentTalenttype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TalentTalenttype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TalentTalenttype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TalentTalenttype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TalentTalenttypeDesc, proto_ff_s::E_TalentTalenttype_s, E_TalentTalenttype, MAX_TALENT_TALENTTYPE_NUM);
DECLARE_IDCREATE_GLOBAL(TalentTalenttypeDesc);
};
