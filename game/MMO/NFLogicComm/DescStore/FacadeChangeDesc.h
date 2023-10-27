#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_CHANGE_NUM 64

class FacadeChangeDesc : public NFIDescTemplate<FacadeChangeDesc, proto_ff_s::E_FacadeChange_s, EOT_CONST_FACADE_CHANGE_DESC_ID, MAX_FACADE_CHANGE_NUM>
{
public:
	FacadeChangeDesc();
	virtual ~FacadeChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
