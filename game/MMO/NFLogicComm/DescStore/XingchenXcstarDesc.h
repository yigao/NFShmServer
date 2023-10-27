#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCSTAR_NUM 16

class XingchenXcstarDesc : public NFIDescTemplate<XingchenXcstarDesc, proto_ff_s::E_XingchenXcstar_s, EOT_CONST_XINGCHEN_XCSTAR_DESC_ID, MAX_XINGCHEN_XCSTAR_NUM>
{
public:
	XingchenXcstarDesc();
	virtual ~XingchenXcstarDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
