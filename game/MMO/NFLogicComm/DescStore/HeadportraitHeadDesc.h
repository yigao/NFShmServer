#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/headPortrait_s.h"

#define MAX_HEADPORTRAIT_HEAD_NUM 100

class HeadportraitHeadDesc : public NFIDescStore
{
public:
	HeadportraitHeadDesc();
	virtual ~HeadportraitHeadDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_HeadportraitHead_s* GetDesc(int id) const;
	proto_ff_s::E_HeadportraitHead_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_HeadportraitHead_s, headPortraithead, MAX_HEADPORTRAIT_HEAD_NUM);
DECLARE_IDCREATE(HeadportraitHeadDesc);
};
