#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWEN_TYPE_NUM 4

class SoulGuwen_typeDesc : public NFIDescTemplate<SoulGuwen_typeDesc, proto_ff_s::E_SoulGuwen_type_s, EOT_CONST_SOUL_GUWEN_TYPE_DESC_ID, MAX_SOUL_GUWEN_TYPE_NUM>
{
public:
	SoulGuwen_typeDesc();
	virtual ~SoulGuwen_typeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
