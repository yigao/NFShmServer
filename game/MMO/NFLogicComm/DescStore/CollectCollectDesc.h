#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Collect_s.h"

#define MAX_COLLECT_COLLECT_NUM 64

class CollectCollectDesc : public NFIDescTemplate<CollectCollectDesc, proto_ff_s::E_CollectCollect_s, EOT_CONST_COLLECT_COLLECT_DESC_ID, MAX_COLLECT_COLLECT_NUM>
{
public:
	CollectCollectDesc();
	virtual ~CollectCollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
