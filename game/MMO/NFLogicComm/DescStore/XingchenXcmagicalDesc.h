#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMAGICAL_NUM 32

class XingchenXcmagicalDesc : public NFIDescTemplate<XingchenXcmagicalDesc, proto_ff_s::E_XingchenXcmagical_s, EOT_CONST_XINGCHEN_XCMAGICAL_DESC_ID, MAX_XINGCHEN_XCMAGICAL_NUM>
{
public:
	XingchenXcmagicalDesc();
	virtual ~XingchenXcmagicalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
