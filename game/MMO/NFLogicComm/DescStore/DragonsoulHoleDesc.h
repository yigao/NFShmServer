#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_HOLE_NUM 16

class DragonsoulHoleDesc : public NFIDescTemplate<DragonsoulHoleDesc, proto_ff_s::E_DragonsoulHole_s, EOT_CONST_DRAGONSOUL_HOLE_DESC_ID, MAX_DRAGONSOUL_HOLE_NUM>
{
public:
	DragonsoulHoleDesc();
	virtual ~DragonsoulHoleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
