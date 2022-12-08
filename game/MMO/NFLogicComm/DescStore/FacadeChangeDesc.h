#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_CHANGE_NUM 60

class FacadeChangeDesc : public NFIDescStore
{
public:
	FacadeChangeDesc();
	virtual ~FacadeChangeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::facadechange_s* GetDesc(int id) const;
	proto_ff_s::facadechange_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadechange_s, facadechange, MAX_FACADE_CHANGE_NUM);
DECLARE_IDCREATE(FacadeChangeDesc);
};
