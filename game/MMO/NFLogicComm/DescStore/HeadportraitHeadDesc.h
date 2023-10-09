#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Headportrait_s.h"

#define MAX_HEADPORTRAIT_HEAD_NUM 64

class HeadportraitHeadDesc : public NFIDescStore
{
public:
	HeadportraitHeadDesc();
	virtual ~HeadportraitHeadDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_HeadportraitHead_s* GetDesc(int64_t id) const;
	proto_ff_s::E_HeadportraitHead_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_HeadportraitHead_s* GetDescByIndex(int index) const;
	proto_ff_s::E_HeadportraitHead_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(HeadportraitHeadDesc, proto_ff_s::E_HeadportraitHead_s, E_HeadportraitHead, MAX_HEADPORTRAIT_HEAD_NUM);
DECLARE_IDCREATE(HeadportraitHeadDesc);
};
