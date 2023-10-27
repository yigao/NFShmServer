#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloudpeak_s.h"

#define MAX_CLOUDPEAK_RANKREWARDS_NUM 32

class CloudpeakRankrewardsDesc : public NFIDescTemplate<CloudpeakRankrewardsDesc, proto_ff_s::E_CloudpeakRankrewards_s, EOT_CONST_CLOUDPEAK_RANKREWARDS_DESC_ID, MAX_CLOUDPEAK_RANKREWARDS_NUM>
{
public:
	CloudpeakRankrewardsDesc();
	virtual ~CloudpeakRankrewardsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
