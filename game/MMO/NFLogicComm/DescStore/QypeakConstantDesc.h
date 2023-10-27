#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qypeak_s.h"

#define MAX_QYPEAK_CONSTANT_NUM 2

class QypeakConstantDesc : public NFIDescTemplate<QypeakConstantDesc, proto_ff_s::E_QypeakConstant_s, EOT_CONST_QYPEAK_CONSTANT_DESC_ID, MAX_QYPEAK_CONSTANT_NUM>
{
public:
	QypeakConstantDesc();
	virtual ~QypeakConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
