#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGPOTIONS_NUM 32

class XiuzhenLgpotionsDesc : public NFIDescStore
{
public:
	XiuzhenLgpotionsDesc();
	virtual ~XiuzhenLgpotionsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenLgpotions_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenLgpotions_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenLgpotions_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenLgpotions_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenLgpotionsDesc, proto_ff_s::E_XiuzhenLgpotions_s, E_XiuzhenLgpotions, MAX_XIUZHEN_LGPOTIONS_NUM);
DECLARE_IDCREATE(XiuzhenLgpotionsDesc);
};
