#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_CONSTANT_NUM 256

class CloudpeakConstantDesc : public NFIDescTemplate<CloudpeakConstantDesc, proto_ff_s::E_CloudpeakConstant_s, EOT_CONST_CLOUDPEAK_CONSTANT_DESC_ID, MAX_CLOUDPEAK_CONSTANT_NUM>
{
public:
	CloudpeakConstantDesc();
	virtual ~CloudpeakConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
