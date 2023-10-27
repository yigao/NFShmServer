#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMAGATT_NUM 16

class XingchenXcmagattDesc : public NFIDescTemplate<XingchenXcmagattDesc, proto_ff_s::E_XingchenXcmagatt_s, EOT_CONST_XINGCHEN_XCMAGATT_DESC_ID, MAX_XINGCHEN_XCMAGATT_NUM>
{
public:
	XingchenXcmagattDesc();
	virtual ~XingchenXcmagattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
