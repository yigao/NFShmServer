#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_CONSTANT_NUM 2

class QunxiongzhuluConstantDesc : public NFIDescTemplate<QunxiongzhuluConstantDesc, proto_ff_s::E_QunxiongzhuluConstant_s, EOT_CONST_QUNXIONGZHULU_CONSTANT_DESC_ID, MAX_QUNXIONGZHULU_CONSTANT_NUM>
{
public:
	QunxiongzhuluConstantDesc();
	virtual ~QunxiongzhuluConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
