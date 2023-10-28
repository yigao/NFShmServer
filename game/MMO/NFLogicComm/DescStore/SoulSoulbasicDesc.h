#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_SOULBASIC_NUM 1024

class SoulSoulbasicDesc : public NFIDescTemplate<SoulSoulbasicDesc, proto_ff_s::E_SoulSoulbasic_s, EOT_CONST_SOUL_SOULBASIC_DESC_ID, MAX_SOUL_SOULBASIC_NUM>
{
public:
	SoulSoulbasicDesc();
	virtual ~SoulSoulbasicDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
