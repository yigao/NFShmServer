#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPATT_NUM 16

class XingchenXctpattDesc : public NFIDescTemplate<XingchenXctpattDesc, proto_ff_s::E_XingchenXctpatt_s, EOT_CONST_XINGCHEN_XCTPATT_DESC_ID, MAX_XINGCHEN_XCTPATT_NUM>
{
public:
	XingchenXctpattDesc();
	virtual ~XingchenXctpattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
