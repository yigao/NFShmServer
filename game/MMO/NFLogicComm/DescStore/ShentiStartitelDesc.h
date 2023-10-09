#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STARTITEL_NUM 16

class ShentiStartitelDesc : public NFIDescStore
{
public:
	ShentiStartitelDesc();
	virtual ~ShentiStartitelDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiStartitel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiStartitel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiStartitel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiStartitel_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiStartitelDesc, proto_ff_s::E_ShentiStartitel_s, E_ShentiStartitel, MAX_SHENTI_STARTITEL_NUM);
DECLARE_IDCREATE(ShentiStartitelDesc);
};
