#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_AWAKEN_NUM 64

class ShentiAwakenDesc : public NFIDescTemplate<ShentiAwakenDesc, proto_ff_s::E_ShentiAwaken_s, EOT_CONST_SHENTI_AWAKEN_DESC_ID, MAX_SHENTI_AWAKEN_NUM>
{
public:
	ShentiAwakenDesc();
	virtual ~ShentiAwakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
