#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/headPortrait_s.h"

#define MAX_HEADPORTRAIT_FRAME_NUM 20

class HeadportraitFrameDesc : public NFIDescStore
{
public:
	HeadportraitFrameDesc(NFIPluginManager* pPluginManager);
	virtual ~HeadportraitFrameDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::headPortraitframe_s* GetDesc(int id) const;
	proto_ff_s::headPortraitframe_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::headPortraitframe_s, MAX_HEADPORTRAIT_FRAME_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::headPortraitframe_s, MAX_HEADPORTRAIT_FRAME_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::headPortraitframe_s, headPortraitframe, MAX_HEADPORTRAIT_FRAME_NUM);
DECLARE_IDCREATE(HeadportraitFrameDesc);
};
