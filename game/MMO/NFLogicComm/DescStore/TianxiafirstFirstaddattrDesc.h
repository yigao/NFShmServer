#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_FIRSTADDATTR_NUM 2

class TianxiafirstFirstaddattrDesc : public NFIDescTemplate<TianxiafirstFirstaddattrDesc, proto_ff_s::E_TianxiafirstFirstaddattr_s, EOT_CONST_TIANXIAFIRST_FIRSTADDATTR_DESC_ID, MAX_TIANXIAFIRST_FIRSTADDATTR_NUM>
{
public:
	TianxiafirstFirstaddattrDesc();
	virtual ~TianxiafirstFirstaddattrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
