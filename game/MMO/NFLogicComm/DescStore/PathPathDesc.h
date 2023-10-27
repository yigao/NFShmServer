#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Path_s.h"

#define MAX_PATH_PATH_NUM 2048

class PathPathDesc : public NFIDescTemplate<PathPathDesc, proto_ff_s::E_PathPath_s, EOT_CONST_PATH_PATH_DESC_ID, MAX_PATH_PATH_NUM>
{
public:
	PathPathDesc();
	virtual ~PathPathDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
