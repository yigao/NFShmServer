#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_VALUE_NUM 1024

class FacadeValueDesc : public NFIDescTemplate<FacadeValueDesc, proto_ff_s::E_FacadeValue_s, EOT_CONST_FACADE_VALUE_DESC_ID, MAX_FACADE_VALUE_NUM>
{
public:
	FacadeValueDesc();
	virtual ~FacadeValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
