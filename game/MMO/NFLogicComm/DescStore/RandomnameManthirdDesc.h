#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_MANTHIRD_NUM 500

class RandomnameManthirdDesc : public NFIDescStore
{
public:
	RandomnameManthirdDesc();
	virtual ~RandomnameManthirdDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::randomnamemanthird_s* GetDesc(int id) const;
	proto_ff_s::randomnamemanthird_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::randomnamemanthird_s, randomnamemanthird, MAX_RANDOMNAME_MANTHIRD_NUM);
DECLARE_IDCREATE(RandomnameManthirdDesc);
};
