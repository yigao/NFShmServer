#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_PREPOSE_NUM 8

class ShentiPreposeDesc : public NFIDescTemplate<ShentiPreposeDesc, proto_ff_s::E_ShentiPrepose_s, EOT_CONST_SHENTI_PREPOSE_DESC_ID, MAX_SHENTI_PREPOSE_NUM>
{
public:
	ShentiPreposeDesc();
	virtual ~ShentiPreposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
