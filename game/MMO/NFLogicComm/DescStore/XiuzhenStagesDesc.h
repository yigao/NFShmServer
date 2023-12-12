#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_STAGES_NUM 2048

class XiuzhenStagesDesc : public NFIDescTemplate<XiuzhenStagesDesc, proto_ff_s::E_XiuzhenStages_s, EOT_CONST_XIUZHEN_STAGES_DESC_ID, MAX_XIUZHEN_STAGES_NUM>
{
public:
	XiuzhenStagesDesc();
	virtual ~XiuzhenStagesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
