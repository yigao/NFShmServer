#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_LOCALRANK_NUM 8

class QunxiongzhuluLocalrankDesc : public NFIDescTemplate<QunxiongzhuluLocalrankDesc, proto_ff_s::E_QunxiongzhuluLocalrank_s, EOT_CONST_QUNXIONGZHULU_LOCALRANK_DESC_ID, MAX_QUNXIONGZHULU_LOCALRANK_NUM>
{
public:
	QunxiongzhuluLocalrankDesc();
	virtual ~QunxiongzhuluLocalrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
