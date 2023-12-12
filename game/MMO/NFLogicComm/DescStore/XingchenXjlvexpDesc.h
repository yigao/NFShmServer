#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJLVEXP_NUM 32

class XingchenXjlvexpDesc : public NFIDescTemplate<XingchenXjlvexpDesc, proto_ff_s::E_XingchenXjlvexp_s, EOT_CONST_XINGCHEN_XJLVEXP_DESC_ID, MAX_XINGCHEN_XJLVEXP_NUM>
{
public:
	XingchenXjlvexpDesc();
	virtual ~XingchenXjlvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
