#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/flash_s.h"

#define MAX_FLASH_FLASH_NUM 60

class FlashFlashDesc : public NFIDescStore
{
public:
	FlashFlashDesc();
	virtual ~FlashFlashDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FlashFlash_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FlashFlash_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FlashFlash_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FlashFlash_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FlashFlashDesc, proto_ff_s::E_FlashFlash_s, E_FlashFlash, MAX_FLASH_FLASH_NUM);
DECLARE_IDCREATE(FlashFlashDesc);
};
