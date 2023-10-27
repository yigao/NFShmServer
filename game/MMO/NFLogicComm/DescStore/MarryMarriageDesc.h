#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_MARRIAGE_NUM 4

class MarryMarriageDesc : public NFIDescTemplate<MarryMarriageDesc, proto_ff_s::E_MarryMarriage_s, EOT_CONST_MARRY_MARRIAGE_DESC_ID, MAX_MARRY_MARRIAGE_NUM>
{
public:
	MarryMarriageDesc();
	virtual ~MarryMarriageDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
