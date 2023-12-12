#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_AWAKENPROGRESS_NUM 64

class ShentiAwakenprogressDesc : public NFIDescTemplate<ShentiAwakenprogressDesc, proto_ff_s::E_ShentiAwakenprogress_s, EOT_CONST_SHENTI_AWAKENPROGRESS_DESC_ID, MAX_SHENTI_AWAKENPROGRESS_NUM>
{
public:
	ShentiAwakenprogressDesc();
	virtual ~ShentiAwakenprogressDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
