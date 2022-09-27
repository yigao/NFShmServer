#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/chooseGift_s.h"

#define MAX_CHOOSEGIFT_CHOOSEGIFT_NUM 20

class ChoosegiftChoosegiftDesc : public NFIDescStore
{
public:
	ChoosegiftChoosegiftDesc(NFIPluginManager* pPluginManager);
	virtual ~ChoosegiftChoosegiftDesc();
	const proto_ff_s::chooseGiftchooseGift_s* GetDesc(int id) const;
	proto_ff_s::chooseGiftchooseGift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::chooseGiftchooseGift_s, MAX_CHOOSEGIFT_CHOOSEGIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::chooseGiftchooseGift_s, MAX_CHOOSEGIFT_CHOOSEGIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::chooseGiftchooseGift_s, chooseGiftchooseGift, MAX_CHOOSEGIFT_CHOOSEGIFT_NUM);
DECLARE_IDCREATE(ChoosegiftChoosegiftDesc);
};
