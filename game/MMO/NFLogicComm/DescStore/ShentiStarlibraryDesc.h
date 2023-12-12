#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STARLIBRARY_NUM 64

class ShentiStarlibraryDesc : public NFIDescTemplate<ShentiStarlibraryDesc, proto_ff_s::E_ShentiStarlibrary_s, EOT_CONST_SHENTI_STARLIBRARY_DESC_ID, MAX_SHENTI_STARLIBRARY_NUM>
{
public:
	ShentiStarlibraryDesc();
	virtual ~ShentiStarlibraryDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
