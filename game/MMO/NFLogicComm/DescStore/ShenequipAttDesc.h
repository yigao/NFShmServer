#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_ATT_NUM 4096

class ShenequipAttDesc : public NFIDescTemplate<ShenequipAttDesc, proto_ff_s::E_ShenequipAtt_s, EOT_CONST_SHENEQUIP_ATT_DESC_ID, MAX_SHENEQUIP_ATT_NUM>
{
public:
	ShenequipAttDesc();
	virtual ~ShenequipAttDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
