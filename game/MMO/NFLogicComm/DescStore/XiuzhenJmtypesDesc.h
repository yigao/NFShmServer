#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMTYPES_NUM 16

class XiuzhenJmtypesDesc : public NFIDescTemplate<XiuzhenJmtypesDesc, proto_ff_s::E_XiuzhenJmtypes_s, EOT_CONST_XIUZHEN_JMTYPES_DESC_ID, MAX_XIUZHEN_JMTYPES_NUM>
{
public:
	XiuzhenJmtypesDesc();
	virtual ~XiuzhenJmtypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
