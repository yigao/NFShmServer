#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMMERGEUP_NUM 32

class XiuzhenJmmergeupDesc : public NFIDescStore
{
public:
	XiuzhenJmmergeupDesc();
	virtual ~XiuzhenJmmergeupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenJmmergeup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenJmmergeup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenJmmergeup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenJmmergeup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenJmmergeupDesc, proto_ff_s::E_XiuzhenJmmergeup_s, E_XiuzhenJmmergeup, MAX_XIUZHEN_JMMERGEUP_NUM);
DECLARE_IDCREATE(XiuzhenJmmergeupDesc);
};
