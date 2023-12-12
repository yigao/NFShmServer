#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFTYPES_NUM 32

class XiuzhenGftypesDesc : public NFIDescTemplate<XiuzhenGftypesDesc, proto_ff_s::E_XiuzhenGftypes_s, EOT_CONST_XIUZHEN_GFTYPES_DESC_ID, MAX_XIUZHEN_GFTYPES_NUM>
{
public:
	XiuzhenGftypesDesc();
	virtual ~XiuzhenGftypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
