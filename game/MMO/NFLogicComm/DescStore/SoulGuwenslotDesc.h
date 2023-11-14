#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENSLOT_NUM 8

class SoulGuwenslotDesc : public NFIDescTemplate<SoulGuwenslotDesc, proto_ff_s::E_SoulGuwenslot_s, EOT_CONST_SOUL_GUWENSLOT_DESC_ID, MAX_SOUL_GUWENSLOT_NUM>
{
public:
	SoulGuwenslotDesc();
	virtual ~SoulGuwenslotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
