#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Talent_s.h"

#define MAX_TALENT_TALENT_NUM 64

class TalentTalentDesc : public NFIDescTemplate<TalentTalentDesc, proto_ff_s::E_TalentTalent_s, EOT_CONST_TALENT_TALENT_DESC_ID, MAX_TALENT_TALENT_NUM>
{
public:
	TalentTalentDesc();
	virtual ~TalentTalentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
