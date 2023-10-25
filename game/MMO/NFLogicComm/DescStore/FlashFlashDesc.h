#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Flash_s.h"

#define MAX_FLASH_FLASH_NUM 512

class FlashFlashDesc : public NFIDescStore
{
public:
	FlashFlashDesc();
	virtual ~FlashFlashDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FlashFlash_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FlashFlash_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FlashFlash_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FlashFlash_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FlashFlashDesc, proto_ff_s::E_FlashFlash_s, E_FlashFlash, MAX_FLASH_FLASH_NUM);
DECLARE_IDCREATE_GLOBAL(FlashFlashDesc);
};
