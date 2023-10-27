#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMSTAGEUP_NUM 256

class XiuzhenJmstageupDesc : public NFIDescTemplate<XiuzhenJmstageupDesc, proto_ff_s::E_XiuzhenJmstageup_s, EOT_CONST_XIUZHEN_JMSTAGEUP_DESC_ID, MAX_XIUZHEN_JMSTAGEUP_NUM>
{
public:
	XiuzhenJmstageupDesc();
	virtual ~XiuzhenJmstageupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
