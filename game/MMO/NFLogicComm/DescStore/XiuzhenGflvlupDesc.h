#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFLVLUP_NUM 16384

class XiuzhenGflvlupDesc : public NFIDescTemplate<XiuzhenGflvlupDesc, proto_ff_s::E_XiuzhenGflvlup_s, EOT_CONST_XIUZHEN_GFLVLUP_DESC_ID, MAX_XIUZHEN_GFLVLUP_NUM>
{
public:
	XiuzhenGflvlupDesc();
	virtual ~XiuzhenGflvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
