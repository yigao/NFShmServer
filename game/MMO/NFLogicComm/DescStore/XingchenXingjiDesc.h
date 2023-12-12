#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XINGJI_NUM 64

class XingchenXingjiDesc : public NFIDescTemplate<XingchenXingjiDesc, proto_ff_s::E_XingchenXingji_s, EOT_CONST_XINGCHEN_XINGJI_DESC_ID, MAX_XINGCHEN_XINGJI_NUM>
{
public:
	XingchenXingjiDesc();
	virtual ~XingchenXingjiDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
