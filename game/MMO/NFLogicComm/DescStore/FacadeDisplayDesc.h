#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/facade_s.h"

#define MAX_FACADE_DISPLAY_NUM 20

class FacadeDisplayDesc : public NFIDescStore
{
public:
	FacadeDisplayDesc();
	virtual ~FacadeDisplayDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::facadedisplay_s* GetDesc(int id) const;
	proto_ff_s::facadedisplay_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::facadedisplay_s, facadedisplay, MAX_FACADE_DISPLAY_NUM);
DECLARE_IDCREATE(FacadeDisplayDesc);
};
