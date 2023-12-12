#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XINCHEN_NUM 64

class XingchenXinchenDesc : public NFIDescTemplate<XingchenXinchenDesc, proto_ff_s::E_XingchenXinchen_s, EOT_CONST_XINGCHEN_XINCHEN_DESC_ID, MAX_XINGCHEN_XINCHEN_NUM>
{
public:
	XingchenXinchenDesc();
	virtual ~XingchenXinchenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
