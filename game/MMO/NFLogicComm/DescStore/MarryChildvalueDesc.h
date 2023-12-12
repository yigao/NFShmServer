#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILDVALUE_NUM 128

class MarryChildvalueDesc : public NFIDescTemplate<MarryChildvalueDesc, proto_ff_s::E_MarryChildvalue_s, EOT_CONST_MARRY_CHILDVALUE_DESC_ID, MAX_MARRY_CHILDVALUE_NUM>
{
public:
	MarryChildvalueDesc();
	virtual ~MarryChildvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
