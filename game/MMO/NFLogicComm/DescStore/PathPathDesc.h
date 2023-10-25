#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Path_s.h"

#define MAX_PATH_PATH_NUM 2048

class PathPathDesc : public NFIDescStore
{
public:
	PathPathDesc();
	virtual ~PathPathDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PathPath_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PathPath_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PathPath_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PathPath_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PathPathDesc, proto_ff_s::E_PathPath_s, E_PathPath, MAX_PATH_PATH_NUM);
DECLARE_IDCREATE_GLOBAL(PathPathDesc);
};
