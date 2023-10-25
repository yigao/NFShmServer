#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_ACCRUEREWARD_NUM 16

class WelfareAccruerewardDesc : public NFIDescStore
{
public:
	WelfareAccruerewardDesc();
	virtual ~WelfareAccruerewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareAccruereward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareAccruereward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareAccruereward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareAccruereward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareAccruerewardDesc, proto_ff_s::E_WelfareAccruereward_s, E_WelfareAccruereward, MAX_WELFARE_ACCRUEREWARD_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareAccruerewardDesc);
};
