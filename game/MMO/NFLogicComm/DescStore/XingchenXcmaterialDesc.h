#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMATERIAL_NUM 8

class XingchenXcmaterialDesc : public NFIDescTemplate<XingchenXcmaterialDesc, proto_ff_s::E_XingchenXcmaterial_s, EOT_CONST_XINGCHEN_XCMATERIAL_DESC_ID, MAX_XINGCHEN_XCMATERIAL_NUM>
{
public:
	XingchenXcmaterialDesc();
	virtual ~XingchenXcmaterialDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
