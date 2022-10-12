#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/condition_s.h"

#define MAX_CONDITION_CONDITION_NUM 40

class ConditionConditionDesc : public NFIDescStore
{
public:
	ConditionConditionDesc(NFIPluginManager* pPluginManager);
	virtual ~ConditionConditionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::conditioncondition_s* GetDesc(int id) const;
	proto_ff_s::conditioncondition_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::conditioncondition_s, MAX_CONDITION_CONDITION_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::conditioncondition_s, MAX_CONDITION_CONDITION_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::conditioncondition_s, conditioncondition, MAX_CONDITION_CONDITION_NUM);
DECLARE_IDCREATE(ConditionConditionDesc);
};
