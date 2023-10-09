#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMSTAGEUP_NUM 256

class XiuzhenJmstageupDesc : public NFIDescStore
{
public:
	XiuzhenJmstageupDesc();
	virtual ~XiuzhenJmstageupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenJmstageup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenJmstageup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenJmstageup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenJmstageup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenJmstageupDesc, proto_ff_s::E_XiuzhenJmstageup_s, E_XiuzhenJmstageup, MAX_XIUZHEN_JMSTAGEUP_NUM);
DECLARE_IDCREATE(XiuzhenJmstageupDesc);
};
