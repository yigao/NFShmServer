#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALLTYPE_NUM 16

class MallMalltypeDesc : public NFIDescTemplate<MallMalltypeDesc, proto_ff_s::E_MallMalltype_s, EOT_CONST_MALL_MALLTYPE_DESC_ID, MAX_MALL_MALLTYPE_NUM>
{
public:
	MallMalltypeDesc();
	virtual ~MallMalltypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
