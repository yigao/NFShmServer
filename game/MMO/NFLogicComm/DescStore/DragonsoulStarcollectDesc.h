#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_STARCOLLECT_NUM 32

class DragonsoulStarcollectDesc : public NFIDescTemplate<DragonsoulStarcollectDesc, proto_ff_s::E_DragonsoulStarcollect_s, EOT_CONST_DRAGONSOUL_STARCOLLECT_DESC_ID, MAX_DRAGONSOUL_STARCOLLECT_NUM>
{
public:
	DragonsoulStarcollectDesc();
	virtual ~DragonsoulStarcollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
