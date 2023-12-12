#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_TEMPLATE_NUM 256

#define MAX_INDEX_FESTIVAL_TEMPLATE_FESTIVALID_NUM 128

#define UNIQUE_KEY_MAX_INDEX_FESTIVAL_TEMPLATE_FESTIVALID_NUM 8

class FestivalTemplateDesc : public NFIDescTemplate<FestivalTemplateDesc, proto_ff_s::E_FestivalTemplate_s, EOT_CONST_FESTIVAL_TEMPLATE_DESC_ID, MAX_FESTIVAL_TEMPLATE_NUM>
{
public:
	FestivalTemplateDesc();
	virtual ~FestivalTemplateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FestivalTemplate_s*> GetDescByFestivalid(int64_t Festivalid) const;
private:
	NFShmHashMap<int64_t, NFShmVector<uint64_t, MAX_INDEX_FESTIVAL_TEMPLATE_FESTIVALID_NUM>,UNIQUE_KEY_MAX_INDEX_FESTIVAL_TEMPLATE_FESTIVALID_NUM> m_FestivalidIndexMap;
};
