#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godrelics_s.h"

#define MAX_GODRELICS_CONDITION_NUM 128

#define MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM 16

#define UNIQUE_KEY_MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM 16

class GodrelicsConditionDesc : public NFIDescTemplate<GodrelicsConditionDesc, proto_ff_s::E_GodrelicsCondition_s, EOT_CONST_GODRELICS_CONDITION_DESC_ID, MAX_GODRELICS_CONDITION_NUM>
{
public:
	GodrelicsConditionDesc();
	virtual ~GodrelicsConditionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_GodrelicsCondition_s*> GetDescByGroup(int64_t Group) const;
private:
	NFShmHashMap<int64_t, NFShmVector<uint64_t, MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM>,UNIQUE_KEY_MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM> m_GroupIndexMap;
};
