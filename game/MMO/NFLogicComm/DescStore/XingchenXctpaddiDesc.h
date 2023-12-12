#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPADDI_NUM 128

class XingchenXctpaddiDesc : public NFIDescTemplate<XingchenXctpaddiDesc, proto_ff_s::E_XingchenXctpaddi_s, EOT_CONST_XINGCHEN_XCTPADDI_DESC_ID, MAX_XINGCHEN_XCTPADDI_NUM>
{
public:
	XingchenXctpaddiDesc();
	virtual ~XingchenXctpaddiDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
