#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_TEMPLATE_NUM 2000

class FestivalTemplateDesc : public NFIDescStore
{
public:
	FestivalTemplateDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalTemplateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivaltemplate_s* GetDesc(int id) const;
	proto_ff_s::festivaltemplate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivaltemplate_s, MAX_FESTIVAL_TEMPLATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivaltemplate_s, MAX_FESTIVAL_TEMPLATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivaltemplate_s, festivaltemplate, MAX_FESTIVAL_TEMPLATE_NUM);
DECLARE_IDCREATE(FestivalTemplateDesc);
};
