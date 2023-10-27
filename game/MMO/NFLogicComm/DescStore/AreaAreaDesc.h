#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Area_s.h"

#define MAX_AREA_AREA_NUM 32

class AreaAreaDesc : public NFIDescTemplate<AreaAreaDesc, proto_ff_s::E_AreaArea_s, EOT_CONST_AREA_AREA_DESC_ID, MAX_AREA_AREA_NUM>
{
public:
	AreaAreaDesc();
	virtual ~AreaAreaDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
