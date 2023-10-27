#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Collect_s.h"

#define MAX_COLLECT_ATTRIBUTETPYE_NUM 256

class CollectAttributetpyeDesc : public NFIDescTemplate<CollectAttributetpyeDesc, proto_ff_s::E_CollectAttributetpye_s, EOT_CONST_COLLECT_ATTRIBUTETPYE_DESC_ID, MAX_COLLECT_ATTRIBUTETPYE_NUM>
{
public:
	CollectAttributetpyeDesc();
	virtual ~CollectAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
