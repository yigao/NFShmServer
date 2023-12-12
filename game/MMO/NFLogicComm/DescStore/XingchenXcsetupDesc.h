#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCSETUP_NUM 32

class XingchenXcsetupDesc : public NFIDescTemplate<XingchenXcsetupDesc, proto_ff_s::E_XingchenXcsetup_s, EOT_CONST_XINGCHEN_XCSETUP_DESC_ID, MAX_XINGCHEN_XCSETUP_NUM>
{
public:
	XingchenXcsetupDesc();
	virtual ~XingchenXcsetupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
