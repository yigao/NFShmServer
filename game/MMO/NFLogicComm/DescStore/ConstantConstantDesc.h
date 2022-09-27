#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/constant_s.h"

#define MAX_CONSTANT_CONSTANT_NUM 200

class ConstantConstantDesc : public NFIDescStore
{
public:
	ConstantConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~ConstantConstantDesc();
	const proto_ff_s::constantconstant_s* GetDesc(int id) const;
	proto_ff_s::constantconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::constantconstant_s, MAX_CONSTANT_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::constantconstant_s, MAX_CONSTANT_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::constantconstant_s, constantconstant, MAX_CONSTANT_CONSTANT_NUM);
DECLARE_IDCREATE(ConstantConstantDesc);
};
