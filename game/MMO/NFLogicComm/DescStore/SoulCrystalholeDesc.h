#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_CRYSTALHOLE_NUM 16

class SoulCrystalholeDesc : public NFIDescTemplate<SoulCrystalholeDesc, proto_ff_s::E_SoulCrystalhole_s, EOT_CONST_SOUL_CRYSTALHOLE_DESC_ID, MAX_SOUL_CRYSTALHOLE_NUM>
{
public:
	SoulCrystalholeDesc();
	virtual ~SoulCrystalholeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
