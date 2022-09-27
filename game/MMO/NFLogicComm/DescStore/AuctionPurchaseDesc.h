#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/auction_s.h"

#define MAX_AUCTION_PURCHASE_NUM 2000

class AuctionPurchaseDesc : public NFIDescStore
{
public:
	AuctionPurchaseDesc(NFIPluginManager* pPluginManager);
	virtual ~AuctionPurchaseDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::auctionpurchase_s* GetDesc(int id) const;
	proto_ff_s::auctionpurchase_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::auctionpurchase_s, MAX_AUCTION_PURCHASE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::auctionpurchase_s, MAX_AUCTION_PURCHASE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::auctionpurchase_s, auctionpurchase, MAX_AUCTION_PURCHASE_NUM);
DECLARE_IDCREATE(AuctionPurchaseDesc);
};
