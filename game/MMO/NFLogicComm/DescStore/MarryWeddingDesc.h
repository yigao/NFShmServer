#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_WEDDING_NUM 2

class MarryWeddingDesc : public NFIDescTemplate<MarryWeddingDesc, proto_ff_s::E_MarryWedding_s, EOT_CONST_MARRY_WEDDING_DESC_ID, MAX_MARRY_WEDDING_NUM>
{
public:
	MarryWeddingDesc();
	virtual ~MarryWeddingDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
