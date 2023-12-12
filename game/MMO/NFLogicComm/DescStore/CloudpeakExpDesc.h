#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_EXP_NUM 512

class CloudpeakExpDesc : public NFIDescTemplate<CloudpeakExpDesc, proto_ff_s::E_CloudpeakExp_s, EOT_CONST_CLOUDPEAK_EXP_DESC_ID, MAX_CLOUDPEAK_EXP_NUM>
{
public:
	CloudpeakExpDesc();
	virtual ~CloudpeakExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
