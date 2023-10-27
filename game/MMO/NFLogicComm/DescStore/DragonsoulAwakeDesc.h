#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_AWAKE_NUM 16

class DragonsoulAwakeDesc : public NFIDescTemplate<DragonsoulAwakeDesc, proto_ff_s::E_DragonsoulAwake_s, EOT_CONST_DRAGONSOUL_AWAKE_DESC_ID, MAX_DRAGONSOUL_AWAKE_NUM>
{
public:
	DragonsoulAwakeDesc();
	virtual ~DragonsoulAwakeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
