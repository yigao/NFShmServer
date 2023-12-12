#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_OPEN_NUM 8

class SoulOpenDesc : public NFIDescTemplate<SoulOpenDesc, proto_ff_s::E_SoulOpen_s, EOT_CONST_SOUL_OPEN_DESC_ID, MAX_SOUL_OPEN_NUM>
{
public:
	SoulOpenDesc();
	virtual ~SoulOpenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
