#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_WORLDRANK_NUM 8

class QunxiongzhuluWorldrankDesc : public NFIDescTemplate<QunxiongzhuluWorldrankDesc, proto_ff_s::E_QunxiongzhuluWorldrank_s, EOT_CONST_QUNXIONGZHULU_WORLDRANK_DESC_ID, MAX_QUNXIONGZHULU_WORLDRANK_NUM>
{
public:
	QunxiongzhuluWorldrankDesc();
	virtual ~QunxiongzhuluWorldrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
