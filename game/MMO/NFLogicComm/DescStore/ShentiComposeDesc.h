#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_COMPOSE_NUM 128

class ShentiComposeDesc : public NFIDescTemplate<ShentiComposeDesc, proto_ff_s::E_ShentiCompose_s, EOT_CONST_SHENTI_COMPOSE_DESC_ID, MAX_SHENTI_COMPOSE_NUM>
{
public:
	ShentiComposeDesc();
	virtual ~ShentiComposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
