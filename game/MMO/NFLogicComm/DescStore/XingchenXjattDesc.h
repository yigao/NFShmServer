#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJATT_NUM 32

class XingchenXjattDesc : public NFIDescTemplate<XingchenXjattDesc, proto_ff_s::E_XingchenXjatt_s, EOT_CONST_XINGCHEN_XJATT_DESC_ID, MAX_XINGCHEN_XJATT_NUM>
{
public:
	XingchenXjattDesc();
	virtual ~XingchenXjattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
