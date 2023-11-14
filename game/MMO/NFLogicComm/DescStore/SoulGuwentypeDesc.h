#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENTYPE_NUM 4

class SoulGuwentypeDesc : public NFIDescTemplate<SoulGuwentypeDesc, proto_ff_s::E_SoulGuwentype_s, EOT_CONST_SOUL_GUWENTYPE_DESC_ID, MAX_SOUL_GUWENTYPE_NUM>
{
public:
	SoulGuwentypeDesc();
	virtual ~SoulGuwentypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
