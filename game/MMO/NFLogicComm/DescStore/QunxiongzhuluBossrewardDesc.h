#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_BOSSREWARD_NUM 4

class QunxiongzhuluBossrewardDesc : public NFIDescTemplate<QunxiongzhuluBossrewardDesc, proto_ff_s::E_QunxiongzhuluBossreward_s, EOT_CONST_QUNXIONGZHULU_BOSSREWARD_DESC_ID, MAX_QUNXIONGZHULU_BOSSREWARD_NUM>
{
public:
	QunxiongzhuluBossrewardDesc();
	virtual ~QunxiongzhuluBossrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
