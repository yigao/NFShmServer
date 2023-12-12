#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Footprint_s.h"

#define MAX_FOOTPRINT_FOOTPRINT_NUM 8

class FootprintFootprintDesc : public NFIDescTemplate<FootprintFootprintDesc, proto_ff_s::E_FootprintFootprint_s, EOT_CONST_FOOTPRINT_FOOTPRINT_DESC_ID, MAX_FOOTPRINT_FOOTPRINT_NUM>
{
public:
	FootprintFootprintDesc();
	virtual ~FootprintFootprintDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
