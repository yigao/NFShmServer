#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_BONUSPOINTS_NUM 32

class XiuzhenroadBonuspointsDesc : public NFIDescTemplate<XiuzhenroadBonuspointsDesc, proto_ff_s::E_XiuzhenroadBonuspoints_s, EOT_CONST_XIUZHENROAD_BONUSPOINTS_DESC_ID, MAX_XIUZHENROAD_BONUSPOINTS_NUM>
{
public:
	XiuzhenroadBonuspointsDesc();
	virtual ~XiuzhenroadBonuspointsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
