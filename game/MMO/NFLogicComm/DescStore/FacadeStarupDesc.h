#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_STARUP_NUM 512

class FacadeStarupDesc : public NFIDescTemplate<FacadeStarupDesc, proto_ff_s::E_FacadeStarup_s, EOT_CONST_FACADE_STARUP_DESC_ID, MAX_FACADE_STARUP_NUM>
{
public:
	FacadeStarupDesc();
	virtual ~FacadeStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
