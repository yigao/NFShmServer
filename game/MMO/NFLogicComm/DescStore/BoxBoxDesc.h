#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Box_s.h"

#define MAX_BOX_BOX_NUM 4096

class BoxBoxDesc : public NFIDescStore
{
public:
	BoxBoxDesc();
	virtual ~BoxBoxDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BoxBox_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BoxBox_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BoxBox_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BoxBox_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BoxBoxDesc, proto_ff_s::E_BoxBox_s, E_BoxBox, MAX_BOX_BOX_NUM);
DECLARE_IDCREATE_GLOBAL(BoxBoxDesc);
};
