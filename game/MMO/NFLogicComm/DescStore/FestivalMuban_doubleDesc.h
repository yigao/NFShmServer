#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_DOUBLE_NUM 20

class FestivalMuban_doubleDesc : public NFIDescStore
{
public:
	FestivalMuban_doubleDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_doubleDesc();
	const proto_ff_s::festivalmuban_double_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_double_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_double_s, MAX_FESTIVAL_MUBAN_DOUBLE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_double_s, MAX_FESTIVAL_MUBAN_DOUBLE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_double_s, festivalmuban_double, MAX_FESTIVAL_MUBAN_DOUBLE_NUM);
DECLARE_IDCREATE(FestivalMuban_doubleDesc);
};
