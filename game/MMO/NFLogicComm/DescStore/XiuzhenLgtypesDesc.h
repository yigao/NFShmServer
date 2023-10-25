#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGTYPES_NUM 8

class XiuzhenLgtypesDesc : public NFIDescStore
{
public:
	XiuzhenLgtypesDesc();
	virtual ~XiuzhenLgtypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenLgtypes_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenLgtypes_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenLgtypes_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenLgtypes_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenLgtypesDesc, proto_ff_s::E_XiuzhenLgtypes_s, E_XiuzhenLgtypes, MAX_XIUZHEN_LGTYPES_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenLgtypesDesc);
};
