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
	const proto_ff_s::E_PathPath_s* GetDesc(int id) const;
	proto_ff_s::E_PathPath_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PathPath_s, pathpath, MAX_PATH_PATH_NUM);
DECLARE_IDCREATE(PathPathDesc);
};
