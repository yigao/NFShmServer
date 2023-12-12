#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_LVLUP_NUM 2048

class XiuzhenGb_lvlupDesc : public NFIDescTemplate<XiuzhenGb_lvlupDesc, proto_ff_s::E_XiuzhenGb_lvlup_s, EOT_CONST_XIUZHEN_GB_LVLUP_DESC_ID, MAX_XIUZHEN_GB_LVLUP_NUM>
{
public:
	XiuzhenGb_lvlupDesc();
	virtual ~XiuzhenGb_lvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
