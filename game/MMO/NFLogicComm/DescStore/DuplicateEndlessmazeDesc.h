#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_ENDLESSMAZE_NUM 20

class DuplicateEndlessmazeDesc : public NFIDescStore
{
public:
	DuplicateEndlessmazeDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateEndlessmazeDesc();
	const proto_ff_s::duplicateendlessMaze_s* GetDesc(int id) const;
	proto_ff_s::duplicateendlessMaze_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateendlessMaze_s, MAX_DUPLICATE_ENDLESSMAZE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateendlessMaze_s, MAX_DUPLICATE_ENDLESSMAZE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateendlessMaze_s, duplicateendlessMaze, MAX_DUPLICATE_ENDLESSMAZE_NUM);
DECLARE_IDCREATE(DuplicateEndlessmazeDesc);
};
