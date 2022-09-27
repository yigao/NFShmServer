#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/flash_s.h"

#define MAX_FLASH_FLASH_NUM 600

class FlashFlashDesc : public NFIDescStore
{
public:
	FlashFlashDesc(NFIPluginManager* pPluginManager);
	virtual ~FlashFlashDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::flashflash_s* GetDesc(int id) const;
	proto_ff_s::flashflash_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::flashflash_s, MAX_FLASH_FLASH_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::flashflash_s, MAX_FLASH_FLASH_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::flashflash_s, flashflash, MAX_FLASH_FLASH_NUM);
DECLARE_IDCREATE(FlashFlashDesc);
};
