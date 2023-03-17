#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/path_s.h"

#define MAX_PATH_PATH_NUM 20

class PathPathDesc : public NFIDescStore
{
public:
	PathPathDesc();
	virtual ~PathPathDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PathPath_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PathPath_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PathPath_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PathPath_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PathPathDesc, proto_ff_s::E_PathPath_s, E_PathPath, MAX_PATH_PATH_NUM);
DECLARE_IDCREATE(PathPathDesc);
};
