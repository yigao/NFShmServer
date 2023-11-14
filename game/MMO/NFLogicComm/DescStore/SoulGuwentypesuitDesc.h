#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENTYPESUIT_NUM 16

class SoulGuwentypesuitDesc : public NFIDescTemplate<SoulGuwentypesuitDesc, proto_ff_s::E_SoulGuwentypesuit_s, EOT_CONST_SOUL_GUWENTYPESUIT_DESC_ID, MAX_SOUL_GUWENTYPESUIT_NUM>
{
public:
	SoulGuwentypesuitDesc();
	virtual ~SoulGuwentypesuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
