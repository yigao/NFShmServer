#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_TEMPLATE_NUM 64

class FestivalTemplateDesc : public NFIDescStore
{
public:
	FestivalTemplateDesc();
	virtual ~FestivalTemplateDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FestivalTemplate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FestivalTemplate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FestivalTemplate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FestivalTemplate_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FestivalTemplateDesc, proto_ff_s::E_FestivalTemplate_s, E_FestivalTemplate, MAX_FESTIVAL_TEMPLATE_NUM);
DECLARE_IDCREATE(FestivalTemplateDesc);
};
