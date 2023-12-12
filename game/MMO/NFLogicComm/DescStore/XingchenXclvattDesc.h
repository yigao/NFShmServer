#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCLVATT_NUM 64

class XingchenXclvattDesc : public NFIDescTemplate<XingchenXclvattDesc, proto_ff_s::E_XingchenXclvatt_s, EOT_CONST_XINGCHEN_XCLVATT_DESC_ID, MAX_XINGCHEN_XCLVATT_NUM>
{
public:
	XingchenXclvattDesc();
	virtual ~XingchenXclvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
