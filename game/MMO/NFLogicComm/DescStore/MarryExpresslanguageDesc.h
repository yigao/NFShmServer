#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXPRESSLANGUAGE_NUM 32

class MarryExpresslanguageDesc : public NFIDescTemplate<MarryExpresslanguageDesc, proto_ff_s::E_MarryExpresslanguage_s, EOT_CONST_MARRY_EXPRESSLANGUAGE_DESC_ID, MAX_MARRY_EXPRESSLANGUAGE_NUM>
{
public:
	MarryExpresslanguageDesc();
	virtual ~MarryExpresslanguageDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
