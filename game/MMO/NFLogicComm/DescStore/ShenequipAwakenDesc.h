#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_AWAKEN_NUM 16

class ShenequipAwakenDesc : public NFIDescTemplate<ShenequipAwakenDesc, proto_ff_s::E_ShenequipAwaken_s, EOT_CONST_SHENEQUIP_AWAKEN_DESC_ID, MAX_SHENEQUIP_AWAKEN_NUM>
{
public:
	ShenequipAwakenDesc();
	virtual ~ShenequipAwakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
