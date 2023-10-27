#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_LEVEL_NUM 32

class Pk3v3LevelDesc : public NFIDescTemplate<Pk3v3LevelDesc, proto_ff_s::E_Pk3v3Level_s, EOT_CONST_PK3V3_LEVEL_DESC_ID, MAX_PK3V3_LEVEL_NUM>
{
public:
	Pk3v3LevelDesc();
	virtual ~Pk3v3LevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
