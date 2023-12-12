#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULACTIVE_NUM 32

class FacadeSoulactiveDesc : public NFIDescTemplate<FacadeSoulactiveDesc, proto_ff_s::E_FacadeSoulactive_s, EOT_CONST_FACADE_SOULACTIVE_DESC_ID, MAX_FACADE_SOULACTIVE_NUM>
{
public:
	FacadeSoulactiveDesc();
	virtual ~FacadeSoulactiveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
