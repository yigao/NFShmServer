#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_UPGRADE_NUM 128

class ShentiUpgradeDesc : public NFIDescStore
{
public:
	ShentiUpgradeDesc();
	virtual ~ShentiUpgradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiUpgrade_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiUpgrade_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiUpgrade_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiUpgrade_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiUpgradeDesc, proto_ff_s::E_ShentiUpgrade_s, E_ShentiUpgrade, MAX_SHENTI_UPGRADE_NUM);
DECLARE_IDCREATE(ShentiUpgradeDesc);
};
