#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCLVEXP_NUM 128

class XingchenXclvexpDesc : public NFIDescTemplate<XingchenXclvexpDesc, proto_ff_s::E_XingchenXclvexp_s, EOT_CONST_XINGCHEN_XCLVEXP_DESC_ID, MAX_XINGCHEN_XCLVEXP_NUM>
{
public:
	XingchenXclvexpDesc();
	virtual ~XingchenXclvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
