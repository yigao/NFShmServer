#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_FESTIVAL_NUM 160

class FestivalFestivalDesc : public NFIDescStore
{
public:
	FestivalFestivalDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalFestivalDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalfestival_s* GetDesc(int id) const;
	proto_ff_s::festivalfestival_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalfestival_s, MAX_FESTIVAL_FESTIVAL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalfestival_s, MAX_FESTIVAL_FESTIVAL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalfestival_s, festivalfestival, MAX_FESTIVAL_FESTIVAL_NUM);
DECLARE_IDCREATE(FestivalFestivalDesc);
};
