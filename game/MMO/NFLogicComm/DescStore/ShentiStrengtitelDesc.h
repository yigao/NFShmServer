#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STRENGTITEL_NUM 64

class ShentiStrengtitelDesc : public NFIDescTemplate<ShentiStrengtitelDesc, proto_ff_s::E_ShentiStrengtitel_s, EOT_CONST_SHENTI_STRENGTITEL_DESC_ID, MAX_SHENTI_STRENGTITEL_NUM>
{
public:
	ShentiStrengtitelDesc();
	virtual ~ShentiStrengtitelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
