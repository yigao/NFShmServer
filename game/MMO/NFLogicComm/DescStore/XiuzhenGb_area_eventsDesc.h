#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_AREA_EVENTS_NUM 32

class XiuzhenGb_area_eventsDesc : public NFIDescTemplate<XiuzhenGb_area_eventsDesc, proto_ff_s::E_XiuzhenGb_area_events_s, EOT_CONST_XIUZHEN_GB_AREA_EVENTS_DESC_ID, MAX_XIUZHEN_GB_AREA_EVENTS_NUM>
{
public:
	XiuzhenGb_area_eventsDesc();
	virtual ~XiuzhenGb_area_eventsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
