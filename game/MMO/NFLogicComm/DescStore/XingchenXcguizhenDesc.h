#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCGUIZHEN_NUM 32

class XingchenXcguizhenDesc : public NFIDescTemplate<XingchenXcguizhenDesc, proto_ff_s::E_XingchenXcguizhen_s, EOT_CONST_XINGCHEN_XCGUIZHEN_DESC_ID, MAX_XINGCHEN_XCGUIZHEN_NUM>
{
public:
	XingchenXcguizhenDesc();
	virtual ~XingchenXcguizhenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
