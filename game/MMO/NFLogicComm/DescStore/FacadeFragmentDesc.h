#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_FRAGMENT_NUM 16

class FacadeFragmentDesc : public NFIDescTemplate<FacadeFragmentDesc, proto_ff_s::E_FacadeFragment_s, EOT_CONST_FACADE_FRAGMENT_DESC_ID, MAX_FACADE_FRAGMENT_NUM>
{
public:
	FacadeFragmentDesc();
	virtual ~FacadeFragmentDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
