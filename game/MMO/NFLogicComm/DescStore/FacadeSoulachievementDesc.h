#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULACHIEVEMENT_NUM 128

#define MAX_INDEX_FACADE_SOULACHIEVEMENT_SOULID_NUM 32

#define UNIQUE_KEY_MAX_INDEX_FACADE_SOULACHIEVEMENT_SOULID_NUM 4

class FacadeSoulachievementDesc : public NFIDescTemplate<FacadeSoulachievementDesc, proto_ff_s::E_FacadeSoulachievement_s, EOT_CONST_FACADE_SOULACHIEVEMENT_DESC_ID, MAX_FACADE_SOULACHIEVEMENT_NUM>
{
public:
	FacadeSoulachievementDesc();
	virtual ~FacadeSoulachievementDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FacadeSoulachievement_s*> GetDescBySoulid(int64_t Soulid) const;
private:
	NFShmHashMap<int64_t, NFShmVector<uint64_t, MAX_INDEX_FACADE_SOULACHIEVEMENT_SOULID_NUM>,UNIQUE_KEY_MAX_INDEX_FACADE_SOULACHIEVEMENT_SOULID_NUM> m_SoulidIndexMap;
};
