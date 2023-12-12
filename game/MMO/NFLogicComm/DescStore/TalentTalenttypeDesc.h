#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Talent_s.h"

#define MAX_TALENT_TALENTTYPE_NUM 4

class TalentTalenttypeDesc : public NFIDescTemplate<TalentTalenttypeDesc, proto_ff_s::E_TalentTalenttype_s, EOT_CONST_TALENT_TALENTTYPE_DESC_ID, MAX_TALENT_TALENTTYPE_NUM>
{
public:
	TalentTalenttypeDesc();
	virtual ~TalentTalenttypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
