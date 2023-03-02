#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/box_s.h"

#define MAX_BOX_BOX_NUM 60

class BoxBoxDesc : public NFIDescStore
{
public:
	BoxBoxDesc();
	virtual ~BoxBoxDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_BoxBox_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BoxBox_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BoxBox_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BoxBox_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_BoxBox_s, E_BoxBox, MAX_BOX_BOX_NUM);
DECLARE_IDCREATE(BoxBoxDesc);
};
