#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMLVLUP_NUM 8192

class XiuzhenJmlvlupDesc : public NFIDescTemplate<XiuzhenJmlvlupDesc, proto_ff_s::E_XiuzhenJmlvlup_s, EOT_CONST_XIUZHEN_JMLVLUP_DESC_ID, MAX_XIUZHEN_JMLVLUP_NUM>
{
public:
	XiuzhenJmlvlupDesc();
	virtual ~XiuzhenJmlvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
