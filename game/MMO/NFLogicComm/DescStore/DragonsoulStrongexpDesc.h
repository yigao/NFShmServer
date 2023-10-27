#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_STRONGEXP_NUM 2048

class DragonsoulStrongexpDesc : public NFIDescTemplate<DragonsoulStrongexpDesc, proto_ff_s::E_DragonsoulStrongexp_s, EOT_CONST_DRAGONSOUL_STRONGEXP_DESC_ID, MAX_DRAGONSOUL_STRONGEXP_NUM>
{
public:
	DragonsoulStrongexpDesc();
	virtual ~DragonsoulStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
