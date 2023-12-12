#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXP_NUM 512

class MarryExpDesc : public NFIDescTemplate<MarryExpDesc, proto_ff_s::E_MarryExp_s, EOT_CONST_MARRY_EXP_DESC_ID, MAX_MARRY_EXP_NUM>
{
public:
	MarryExpDesc();
	virtual ~MarryExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
