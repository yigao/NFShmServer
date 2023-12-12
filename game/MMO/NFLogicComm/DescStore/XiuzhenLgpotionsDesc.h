#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGPOTIONS_NUM 32

class XiuzhenLgpotionsDesc : public NFIDescTemplate<XiuzhenLgpotionsDesc, proto_ff_s::E_XiuzhenLgpotions_s, EOT_CONST_XIUZHEN_LGPOTIONS_DESC_ID, MAX_XIUZHEN_LGPOTIONS_NUM>
{
public:
	XiuzhenLgpotionsDesc();
	virtual ~XiuzhenLgpotionsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
