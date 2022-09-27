#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_SHOP_NUM 140

class FestivalMuban_shopDesc : public NFIDescStore
{
public:
	FestivalMuban_shopDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_shopDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_shop_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_shop_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_shop_s, MAX_FESTIVAL_MUBAN_SHOP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_shop_s, MAX_FESTIVAL_MUBAN_SHOP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_shop_s, festivalmuban_shop, MAX_FESTIVAL_MUBAN_SHOP_NUM);
DECLARE_IDCREATE(FestivalMuban_shopDesc);
};
