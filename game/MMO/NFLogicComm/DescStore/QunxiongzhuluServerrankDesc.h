#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_SERVERRANK_NUM 8

class QunxiongzhuluServerrankDesc : public NFIDescTemplate<QunxiongzhuluServerrankDesc, proto_ff_s::E_QunxiongzhuluServerrank_s, EOT_CONST_QUNXIONGZHULU_SERVERRANK_DESC_ID, MAX_QUNXIONGZHULU_SERVERRANK_NUM>
{
public:
	QunxiongzhuluServerrankDesc();
	virtual ~QunxiongzhuluServerrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
