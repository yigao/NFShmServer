#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenworld_s.h"

#define MAX_XIUZHENWORLD_WORLD_NUM 16

class XiuzhenworldWorldDesc : public NFIDescTemplate<XiuzhenworldWorldDesc, proto_ff_s::E_XiuzhenworldWorld_s, EOT_CONST_XIUZHENWORLD_WORLD_DESC_ID, MAX_XIUZHENWORLD_WORLD_NUM>
{
public:
	XiuzhenworldWorldDesc();
	virtual ~XiuzhenworldWorldDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
