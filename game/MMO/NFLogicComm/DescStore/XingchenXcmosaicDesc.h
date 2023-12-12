#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMOSAIC_NUM 16

class XingchenXcmosaicDesc : public NFIDescTemplate<XingchenXcmosaicDesc, proto_ff_s::E_XingchenXcmosaic_s, EOT_CONST_XINGCHEN_XCMOSAIC_DESC_ID, MAX_XINGCHEN_XCMOSAIC_NUM>
{
public:
	XingchenXcmosaicDesc();
	virtual ~XingchenXcmosaicDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
