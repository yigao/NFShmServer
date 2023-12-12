#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCADVATT_NUM 4

class XingchenXcadvattDesc : public NFIDescTemplate<XingchenXcadvattDesc, proto_ff_s::E_XingchenXcadvatt_s, EOT_CONST_XINGCHEN_XCADVATT_DESC_ID, MAX_XINGCHEN_XCADVATT_NUM>
{
public:
	XingchenXcadvattDesc();
	virtual ~XingchenXcadvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
