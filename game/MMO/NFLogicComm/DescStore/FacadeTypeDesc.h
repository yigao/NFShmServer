#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_TYPE_NUM 8

class FacadeTypeDesc : public NFIDescTemplate<FacadeTypeDesc, proto_ff_s::E_FacadeType_s, EOT_CONST_FACADE_TYPE_DESC_ID, MAX_FACADE_TYPE_NUM>
{
public:
	FacadeTypeDesc();
	virtual ~FacadeTypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
