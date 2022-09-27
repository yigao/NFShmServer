#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/auction_s.h"

#define MAX_AUCTION_ACQUISITION_NUM 100

class AuctionAcquisitionDesc : public NFIDescStore
{
public:
	AuctionAcquisitionDesc(NFIPluginManager* pPluginManager);
	virtual ~AuctionAcquisitionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::auctionacquisition_s* GetDesc(int id) const;
	proto_ff_s::auctionacquisition_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::auctionacquisition_s, MAX_AUCTION_ACQUISITION_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::auctionacquisition_s, MAX_AUCTION_ACQUISITION_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::auctionacquisition_s, auctionacquisition, MAX_AUCTION_ACQUISITION_NUM);
DECLARE_IDCREATE(AuctionAcquisitionDesc);
};
