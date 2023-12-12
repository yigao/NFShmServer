#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fashion_s.h"

#define MAX_FASHION_FASHION_NUM 64

class FashionFashionDesc : public NFIDescTemplate<FashionFashionDesc, proto_ff_s::E_FashionFashion_s, EOT_CONST_FASHION_FASHION_DESC_ID, MAX_FASHION_FASHION_NUM>
{
public:
	FashionFashionDesc();
	virtual ~FashionFashionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
