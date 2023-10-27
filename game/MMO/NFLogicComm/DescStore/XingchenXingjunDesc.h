#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XINGJUN_NUM 8

class XingchenXingjunDesc : public NFIDescTemplate<XingchenXingjunDesc, proto_ff_s::E_XingchenXingjun_s, EOT_CONST_XINGCHEN_XINGJUN_DESC_ID, MAX_XINGCHEN_XINGJUN_NUM>
{
public:
	XingchenXingjunDesc();
	virtual ~XingchenXingjunDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
