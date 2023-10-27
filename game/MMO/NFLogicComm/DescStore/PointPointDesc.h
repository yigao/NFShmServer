#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Point_s.h"

#define MAX_POINT_POINT_NUM 2048

class PointPointDesc : public NFIDescTemplate<PointPointDesc, proto_ff_s::E_PointPoint_s, EOT_CONST_POINT_POINT_DESC_ID, MAX_POINT_POINT_NUM>
{
public:
	PointPointDesc();
	virtual ~PointPointDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
