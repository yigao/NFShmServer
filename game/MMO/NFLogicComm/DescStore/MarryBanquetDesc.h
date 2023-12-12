#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_BANQUET_NUM 32

class MarryBanquetDesc : public NFIDescTemplate<MarryBanquetDesc, proto_ff_s::E_MarryBanquet_s, EOT_CONST_MARRY_BANQUET_DESC_ID, MAX_MARRY_BANQUET_NUM>
{
public:
	MarryBanquetDesc();
	virtual ~MarryBanquetDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
