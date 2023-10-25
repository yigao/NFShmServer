#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMTYPES_NUM 16

class XiuzhenJmtypesDesc : public NFIDescStore
{
public:
	XiuzhenJmtypesDesc();
	virtual ~XiuzhenJmtypesDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenJmtypes_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenJmtypes_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenJmtypes_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenJmtypes_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenJmtypesDesc, proto_ff_s::E_XiuzhenJmtypes_s, E_XiuzhenJmtypes, MAX_XIUZHEN_JMTYPES_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenJmtypesDesc);
};
