#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_EXTRAADDATTR_NUM 64

class TianxiafirstExtraaddattrDesc : public NFIDescTemplate<TianxiafirstExtraaddattrDesc, proto_ff_s::E_TianxiafirstExtraaddattr_s, EOT_CONST_TIANXIAFIRST_EXTRAADDATTR_DESC_ID, MAX_TIANXIAFIRST_EXTRAADDATTR_NUM>
{
public:
	TianxiafirstExtraaddattrDesc();
	virtual ~TianxiafirstExtraaddattrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
