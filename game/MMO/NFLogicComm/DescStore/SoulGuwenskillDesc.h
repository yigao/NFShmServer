#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENSKILL_NUM 8

class SoulGuwenskillDesc : public NFIDescTemplate<SoulGuwenskillDesc, proto_ff_s::E_SoulGuwenskill_s, EOT_CONST_SOUL_GUWENSKILL_DESC_ID, MAX_SOUL_GUWENSKILL_NUM>
{
public:
	SoulGuwenskillDesc();
	virtual ~SoulGuwenskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
