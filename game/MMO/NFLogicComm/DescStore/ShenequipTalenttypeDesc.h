#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_TALENTTYPE_NUM 8

class ShenequipTalenttypeDesc : public NFIDescTemplate<ShenequipTalenttypeDesc, proto_ff_s::E_ShenequipTalenttype_s, EOT_CONST_SHENEQUIP_TALENTTYPE_DESC_ID, MAX_SHENEQUIP_TALENTTYPE_NUM>
{
public:
	ShenequipTalenttypeDesc();
	virtual ~ShenequipTalenttypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
