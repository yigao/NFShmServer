#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_CRYSTAL_NUM 512

class SoulCrystalDesc : public NFIDescTemplate<SoulCrystalDesc, proto_ff_s::E_SoulCrystal_s, EOT_CONST_SOUL_CRYSTAL_DESC_ID, MAX_SOUL_CRYSTAL_NUM>
{
public:
	SoulCrystalDesc();
	virtual ~SoulCrystalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
