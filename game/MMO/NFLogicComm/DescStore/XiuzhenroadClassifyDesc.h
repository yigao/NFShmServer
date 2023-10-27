#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_CLASSIFY_NUM 16

class XiuzhenroadClassifyDesc : public NFIDescTemplate<XiuzhenroadClassifyDesc, proto_ff_s::E_XiuzhenroadClassify_s, EOT_CONST_XIUZHENROAD_CLASSIFY_DESC_ID, MAX_XIUZHENROAD_CLASSIFY_NUM>
{
public:
	XiuzhenroadClassifyDesc();
	virtual ~XiuzhenroadClassifyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
