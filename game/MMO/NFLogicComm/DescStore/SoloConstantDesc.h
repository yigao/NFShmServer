#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/solo_s.h"

#define MAX_SOLO_CONSTANT_NUM 60

class SoloConstantDesc : public NFIDescStore
{
public:
	SoloConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~SoloConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::soloconstant_s* GetDesc(int id) const;
	proto_ff_s::soloconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::soloconstant_s, MAX_SOLO_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::soloconstant_s, MAX_SOLO_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::soloconstant_s, soloconstant, MAX_SOLO_CONSTANT_NUM);
DECLARE_IDCREATE(SoloConstantDesc);
};
