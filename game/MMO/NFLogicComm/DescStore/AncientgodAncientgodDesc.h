#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ANCIENTGOD_NUM 16

class AncientgodAncientgodDesc : public NFIDescTemplate<AncientgodAncientgodDesc, proto_ff_s::E_AncientgodAncientgod_s, EOT_CONST_ANCIENTGOD_ANCIENTGOD_DESC_ID, MAX_ANCIENTGOD_ANCIENTGOD_NUM>
{
public:
	AncientgodAncientgodDesc();
	virtual ~AncientgodAncientgodDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
