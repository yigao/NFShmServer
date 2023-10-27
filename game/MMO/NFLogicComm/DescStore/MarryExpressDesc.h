#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXPRESS_NUM 1024

class MarryExpressDesc : public NFIDescTemplate<MarryExpressDesc, proto_ff_s::E_MarryExpress_s, EOT_CONST_MARRY_EXPRESS_DESC_ID, MAX_MARRY_EXPRESS_NUM>
{
public:
	MarryExpressDesc();
	virtual ~MarryExpressDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
