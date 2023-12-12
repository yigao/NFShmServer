#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_AREAS_NUM 64

class XiuzhenGb_areasDesc : public NFIDescTemplate<XiuzhenGb_areasDesc, proto_ff_s::E_XiuzhenGb_areas_s, EOT_CONST_XIUZHEN_GB_AREAS_DESC_ID, MAX_XIUZHEN_GB_AREAS_NUM>
{
public:
	XiuzhenGb_areasDesc();
	virtual ~XiuzhenGb_areasDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
