#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/headPortrait_s.h"

#define MAX_HEADPORTRAIT_BUBBLE_NUM 20

class HeadportraitBubbleDesc : public NFIDescStore
{
public:
	HeadportraitBubbleDesc(NFIPluginManager* pPluginManager);
	virtual ~HeadportraitBubbleDesc();
	const proto_ff_s::headPortraitbubble_s* GetDesc(int id) const;
	proto_ff_s::headPortraitbubble_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::headPortraitbubble_s, MAX_HEADPORTRAIT_BUBBLE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::headPortraitbubble_s, MAX_HEADPORTRAIT_BUBBLE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::headPortraitbubble_s, headPortraitbubble, MAX_HEADPORTRAIT_BUBBLE_NUM);
DECLARE_IDCREATE(HeadportraitBubbleDesc);
};
