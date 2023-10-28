#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_SOUL_NUM 2

class SoulSoulDesc : public NFIDescTemplate<SoulSoulDesc, proto_ff_s::E_SoulSoul_s, EOT_CONST_SOUL_SOUL_DESC_ID, MAX_SOUL_SOUL_NUM>
{
public:
	SoulSoulDesc();
	virtual ~SoulSoulDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
