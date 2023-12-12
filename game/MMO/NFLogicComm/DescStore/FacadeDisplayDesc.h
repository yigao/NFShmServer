#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_DISPLAY_NUM 8

class FacadeDisplayDesc : public NFIDescTemplate<FacadeDisplayDesc, proto_ff_s::E_FacadeDisplay_s, EOT_CONST_FACADE_DISPLAY_DESC_ID, MAX_FACADE_DISPLAY_NUM>
{
public:
	FacadeDisplayDesc();
	virtual ~FacadeDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
