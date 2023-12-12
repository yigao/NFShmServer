#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWEN_NUM 32

class SoulGuwenDesc : public NFIDescTemplate<SoulGuwenDesc, proto_ff_s::E_SoulGuwen_s, EOT_CONST_SOUL_GUWEN_DESC_ID, MAX_SOUL_GUWEN_NUM>
{
public:
	SoulGuwenDesc();
	virtual ~SoulGuwenDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
