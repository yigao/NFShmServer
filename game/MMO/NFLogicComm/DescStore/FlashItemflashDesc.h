#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/flash_s.h"

#define MAX_FLASH_ITEMFLASH_NUM 100

class FlashItemflashDesc : public NFIDescStore
{
public:
	FlashItemflashDesc(NFIPluginManager* pPluginManager);
	virtual ~FlashItemflashDesc();
	const proto_ff_s::flashitemFlash_s* GetDesc(int id) const;
	proto_ff_s::flashitemFlash_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::flashitemFlash_s, MAX_FLASH_ITEMFLASH_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::flashitemFlash_s, MAX_FLASH_ITEMFLASH_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::flashitemFlash_s, flashitemFlash, MAX_FLASH_ITEMFLASH_NUM);
DECLARE_IDCREATE(FlashItemflashDesc);
};
