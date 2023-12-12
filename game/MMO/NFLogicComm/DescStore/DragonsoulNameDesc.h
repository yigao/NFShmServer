#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_NAME_NUM 8

class DragonsoulNameDesc : public NFIDescTemplate<DragonsoulNameDesc, proto_ff_s::E_DragonsoulName_s, EOT_CONST_DRAGONSOUL_NAME_DESC_ID, MAX_DRAGONSOUL_NAME_NUM>
{
public:
	DragonsoulNameDesc();
	virtual ~DragonsoulNameDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
