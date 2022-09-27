#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/headPortrait_s.h"

#define MAX_HEADPORTRAIT_HEAD_NUM 20

class HeadportraitHeadDesc : public NFIDescStore
{
public:
	HeadportraitHeadDesc(NFIPluginManager* pPluginManager);
	virtual ~HeadportraitHeadDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::headPortraithead_s* GetDesc(int id) const;
	proto_ff_s::headPortraithead_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::headPortraithead_s, MAX_HEADPORTRAIT_HEAD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::headPortraithead_s, MAX_HEADPORTRAIT_HEAD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::headPortraithead_s, headPortraithead, MAX_HEADPORTRAIT_HEAD_NUM);
DECLARE_IDCREATE(HeadportraitHeadDesc);
};
