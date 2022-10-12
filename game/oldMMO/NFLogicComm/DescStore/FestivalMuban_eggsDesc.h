#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_EGGS_NUM 200

class FestivalMuban_eggsDesc : public NFIDescStore
{
public:
	FestivalMuban_eggsDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_eggsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_eggs_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_eggs_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_eggs_s, MAX_FESTIVAL_MUBAN_EGGS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_eggs_s, MAX_FESTIVAL_MUBAN_EGGS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_eggs_s, festivalmuban_eggs, MAX_FESTIVAL_MUBAN_EGGS_NUM);
DECLARE_IDCREATE(FestivalMuban_eggsDesc);
};
