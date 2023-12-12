#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_BONEKILL_NUM 1024

class SoulBonekillDesc : public NFIDescTemplate<SoulBonekillDesc, proto_ff_s::E_SoulBonekill_s, EOT_CONST_SOUL_BONEKILL_DESC_ID, MAX_SOUL_BONEKILL_NUM>
{
public:
	SoulBonekillDesc();
	virtual ~SoulBonekillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
