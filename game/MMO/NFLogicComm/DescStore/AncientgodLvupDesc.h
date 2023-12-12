#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_LVUP_NUM 2048

class AncientgodLvupDesc : public NFIDescTemplate<AncientgodLvupDesc, proto_ff_s::E_AncientgodLvup_s, EOT_CONST_ANCIENTGOD_LVUP_DESC_ID, MAX_ANCIENTGOD_LVUP_NUM>
{
public:
	AncientgodLvupDesc();
	virtual ~AncientgodLvupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
