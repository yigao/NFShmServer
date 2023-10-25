#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFTYPES_NUM 32

class XiuzhenGftypesDesc : public NFIDescStore
{
public:
	XiuzhenGftypesDesc();
	virtual ~XiuzhenGftypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGftypes_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGftypes_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGftypes_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGftypes_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGftypesDesc, proto_ff_s::E_XiuzhenGftypes_s, E_XiuzhenGftypes, MAX_XIUZHEN_GFTYPES_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenGftypesDesc);
};
