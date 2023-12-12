#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_HOLYBEAST_NUM 32

class MallHolybeastDesc : public NFIDescTemplate<MallHolybeastDesc, proto_ff_s::E_MallHolybeast_s, EOT_CONST_MALL_HOLYBEAST_DESC_ID, MAX_MALL_HOLYBEAST_NUM>
{
public:
	MallHolybeastDesc();
	virtual ~MallHolybeastDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
