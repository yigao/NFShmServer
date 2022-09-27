#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_DOUBLEGIFT_NUM 20

class FestivalMuban_doublegiftDesc : public NFIDescStore
{
public:
	FestivalMuban_doublegiftDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_doublegiftDesc();
	const proto_ff_s::festivalmuban_doubleGift_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_doubleGift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_doubleGift_s, MAX_FESTIVAL_MUBAN_DOUBLEGIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_doubleGift_s, MAX_FESTIVAL_MUBAN_DOUBLEGIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_doubleGift_s, festivalmuban_doubleGift, MAX_FESTIVAL_MUBAN_DOUBLEGIFT_NUM);
DECLARE_IDCREATE(FestivalMuban_doublegiftDesc);
};
