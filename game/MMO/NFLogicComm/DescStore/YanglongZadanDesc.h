#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Yanglong_s.h"

#define MAX_YANGLONG_ZADAN_NUM 16

class YanglongZadanDesc : public NFIDescTemplate<YanglongZadanDesc, proto_ff_s::E_YanglongZadan_s, EOT_CONST_YANGLONG_ZADAN_DESC_ID, MAX_YANGLONG_ZADAN_NUM>
{
public:
	YanglongZadanDesc();
	virtual ~YanglongZadanDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
