#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GunValue_s.h"

#define MAX_GUNVALUE_CONFIG_NUM 64

class GunvalueConfigDesc : public NFIDescStore
{
public:
	GunvalueConfigDesc();
	virtual ~GunvalueConfigDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GunvalueConfig_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GunvalueConfig_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GunvalueConfig_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GunvalueConfig_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GunvalueConfigDesc, proto_ff_s::E_GunvalueConfig_s, E_GunvalueConfig, MAX_GUNVALUE_CONFIG_NUM);
DECLARE_IDCREATE(GunvalueConfigDesc);
};
