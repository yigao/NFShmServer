#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_ZBSHOP_NUM 16

class XingchenZbshopDesc : public NFIDescTemplate<XingchenZbshopDesc, proto_ff_s::E_XingchenZbshop_s, EOT_CONST_XINGCHEN_ZBSHOP_DESC_ID, MAX_XINGCHEN_ZBSHOP_NUM>
{
public:
	XingchenZbshopDesc();
	virtual ~XingchenZbshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
