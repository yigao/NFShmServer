#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/back_s.h"

#define MAX_BACK_BACK_NUM 20

class BackBackDesc : public NFIDescStore
{
public:
	BackBackDesc();
	virtual ~BackBackDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_BackBack_s* GetDesc(int id) const;
	proto_ff_s::E_BackBack_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_BackBack_s, E_BackBack, MAX_BACK_BACK_NUM);
DECLARE_IDCREATE(BackBackDesc);
};
