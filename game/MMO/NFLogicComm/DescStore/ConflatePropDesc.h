#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_PROP_NUM 512

class ConflatePropDesc : public NFIDescTemplate<ConflatePropDesc, proto_ff_s::E_ConflateProp_s, EOT_CONST_CONFLATE_PROP_DESC_ID, MAX_CONFLATE_PROP_NUM>
{
public:
	ConflatePropDesc();
	virtual ~ConflatePropDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
