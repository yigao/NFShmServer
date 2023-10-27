#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STAR_UP_NUM 32

class ShentiStar_upDesc : public NFIDescTemplate<ShentiStar_upDesc, proto_ff_s::E_ShentiStar_up_s, EOT_CONST_SHENTI_STAR_UP_DESC_ID, MAX_SHENTI_STAR_UP_NUM>
{
public:
	ShentiStar_upDesc();
	virtual ~ShentiStar_upDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
