#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Yanglong_s.h"

#define MAX_YANGLONG_YANGLONG_NUM 16

class YanglongYanglongDesc : public NFIDescTemplate<YanglongYanglongDesc, proto_ff_s::E_YanglongYanglong_s, EOT_CONST_YANGLONG_YANGLONG_DESC_ID, MAX_YANGLONG_YANGLONG_NUM>
{
public:
	YanglongYanglongDesc();
	virtual ~YanglongYanglongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
