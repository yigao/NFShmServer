#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOUL_NUM 8

class FacadeSoulDesc : public NFIDescTemplate<FacadeSoulDesc, proto_ff_s::E_FacadeSoul_s, EOT_CONST_FACADE_SOUL_DESC_ID, MAX_FACADE_SOUL_NUM>
{
public:
	FacadeSoulDesc();
	virtual ~FacadeSoulDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
