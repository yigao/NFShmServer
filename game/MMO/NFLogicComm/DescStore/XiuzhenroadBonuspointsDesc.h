#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_BONUSPOINTS_NUM 32

class XiuzhenroadBonuspointsDesc : public NFIDescStore
{
public:
	XiuzhenroadBonuspointsDesc();
	virtual ~XiuzhenroadBonuspointsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenroadBonuspoints_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenroadBonuspoints_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenroadBonuspoints_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenroadBonuspoints_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenroadBonuspointsDesc, proto_ff_s::E_XiuzhenroadBonuspoints_s, E_XiuzhenroadBonuspoints, MAX_XIUZHENROAD_BONUSPOINTS_NUM);
DECLARE_IDCREATE(XiuzhenroadBonuspointsDesc);
};
