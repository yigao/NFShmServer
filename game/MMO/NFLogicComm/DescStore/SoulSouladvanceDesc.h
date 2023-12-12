#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_SOULADVANCE_NUM 512

class SoulSouladvanceDesc : public NFIDescTemplate<SoulSouladvanceDesc, proto_ff_s::E_SoulSouladvance_s, EOT_CONST_SOUL_SOULADVANCE_DESC_ID, MAX_SOUL_SOULADVANCE_NUM>
{
public:
	SoulSouladvanceDesc();
	virtual ~SoulSouladvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
