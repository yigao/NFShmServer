#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJCW_NUM 4

class XingchenXjcwDesc : public NFIDescTemplate<XingchenXjcwDesc, proto_ff_s::E_XingchenXjcw_s, EOT_CONST_XINGCHEN_XJCW_DESC_ID, MAX_XINGCHEN_XJCW_NUM>
{
public:
	XingchenXjcwDesc();
	virtual ~XingchenXjcwDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
