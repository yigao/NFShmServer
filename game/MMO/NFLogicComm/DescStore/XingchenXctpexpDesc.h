#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPEXP_NUM 32

class XingchenXctpexpDesc : public NFIDescTemplate<XingchenXctpexpDesc, proto_ff_s::E_XingchenXctpexp_s, EOT_CONST_XINGCHEN_XCTPEXP_DESC_ID, MAX_XINGCHEN_XCTPEXP_NUM>
{
public:
	XingchenXctpexpDesc();
	virtual ~XingchenXctpexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
