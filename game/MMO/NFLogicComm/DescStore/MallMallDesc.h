#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALL_NUM 512

class MallMallDesc : public NFIDescTemplate<MallMallDesc, proto_ff_s::E_MallMall_s, EOT_CONST_MALL_MALL_DESC_ID, MAX_MALL_MALL_NUM>
{
public:
	MallMallDesc();
	virtual ~MallMallDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
