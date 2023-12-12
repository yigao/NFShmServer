#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_STAGE_NUM 4

class NickgodStageDesc : public NFIDescTemplate<NickgodStageDesc, proto_ff_s::E_NickgodStage_s, EOT_CONST_NICKGOD_STAGE_DESC_ID, MAX_NICKGOD_STAGE_NUM>
{
public:
	NickgodStageDesc();
	virtual ~NickgodStageDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
