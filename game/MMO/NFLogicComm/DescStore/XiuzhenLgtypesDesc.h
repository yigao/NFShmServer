#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGTYPES_NUM 8

class XiuzhenLgtypesDesc : public NFIDescTemplate<XiuzhenLgtypesDesc, proto_ff_s::E_XiuzhenLgtypes_s, EOT_CONST_XIUZHEN_LGTYPES_DESC_ID, MAX_XIUZHEN_LGTYPES_NUM>
{
public:
	XiuzhenLgtypesDesc();
	virtual ~XiuzhenLgtypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
