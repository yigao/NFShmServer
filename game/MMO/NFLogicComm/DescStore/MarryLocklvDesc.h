#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_LOCKLV_NUM 1024

class MarryLocklvDesc : public NFIDescTemplate<MarryLocklvDesc, proto_ff_s::E_MarryLocklv_s, EOT_CONST_MARRY_LOCKLV_DESC_ID, MAX_MARRY_LOCKLV_NUM>
{
public:
	MarryLocklvDesc();
	virtual ~MarryLocklvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
