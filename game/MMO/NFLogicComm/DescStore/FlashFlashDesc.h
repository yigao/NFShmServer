#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/flash_s.h"

#define MAX_FLASH_FLASH_NUM 20

class FlashFlashDesc : public NFIDescStore
{
public:
	FlashFlashDesc();
	virtual ~FlashFlashDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FlashFlash_s* GetDesc(int id) const;
	proto_ff_s::E_FlashFlash_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FlashFlash_s, flashflash, MAX_FLASH_FLASH_NUM);
DECLARE_IDCREATE(FlashFlashDesc);
};
