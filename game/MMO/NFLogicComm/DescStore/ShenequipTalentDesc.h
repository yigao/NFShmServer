#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_TALENT_NUM 64

class ShenequipTalentDesc : public NFIDescTemplate<ShenequipTalentDesc, proto_ff_s::E_ShenequipTalent_s, EOT_CONST_SHENEQUIP_TALENT_DESC_ID, MAX_SHENEQUIP_TALENT_NUM>
{
public:
	ShenequipTalentDesc();
	virtual ~ShenequipTalentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
