#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_YANHUA_NUM 3000

class FestivalMuban_yanhuaDesc : public NFIDescStore
{
public:
	FestivalMuban_yanhuaDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_yanhuaDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_yanhua_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_yanhua_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_yanhua_s, MAX_FESTIVAL_MUBAN_YANHUA_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_yanhua_s, MAX_FESTIVAL_MUBAN_YANHUA_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_yanhua_s, festivalmuban_yanhua, MAX_FESTIVAL_MUBAN_YANHUA_NUM);
DECLARE_IDCREATE(FestivalMuban_yanhuaDesc);
};
