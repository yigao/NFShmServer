#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENSUIT_NUM 64

class SoulGuwensuitDesc : public NFIDescTemplate<SoulGuwensuitDesc, proto_ff_s::E_SoulGuwensuit_s, EOT_CONST_SOUL_GUWENSUIT_DESC_ID, MAX_SOUL_GUWENSUIT_NUM>
{
public:
	SoulGuwensuitDesc();
	virtual ~SoulGuwensuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
