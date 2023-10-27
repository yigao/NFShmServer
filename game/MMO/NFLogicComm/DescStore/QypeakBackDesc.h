#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qypeak_s.h"

#define MAX_QYPEAK_BACK_NUM 16

class QypeakBackDesc : public NFIDescTemplate<QypeakBackDesc, proto_ff_s::E_QypeakBack_s, EOT_CONST_QYPEAK_BACK_DESC_ID, MAX_QYPEAK_BACK_NUM>
{
public:
	QypeakBackDesc();
	virtual ~QypeakBackDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
