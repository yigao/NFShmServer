#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULLV_NUM 512

class FacadeSoullvDesc : public NFIDescTemplate<FacadeSoullvDesc, proto_ff_s::E_FacadeSoullv_s, EOT_CONST_FACADE_SOULLV_DESC_ID, MAX_FACADE_SOULLV_NUM>
{
public:
	FacadeSoullvDesc();
	virtual ~FacadeSoullvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
