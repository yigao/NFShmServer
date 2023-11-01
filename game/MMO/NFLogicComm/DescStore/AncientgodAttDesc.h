#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ATT_NUM 32

class AncientgodAttDesc : public NFIDescTemplate<AncientgodAttDesc, proto_ff_s::E_AncientgodAtt_s, EOT_CONST_ANCIENTGOD_ATT_DESC_ID, MAX_ANCIENTGOD_ATT_NUM>
{
public:
	AncientgodAttDesc();
	virtual ~AncientgodAttDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
