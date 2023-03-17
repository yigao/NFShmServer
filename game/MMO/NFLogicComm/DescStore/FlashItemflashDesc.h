#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/flash_s.h"

#define MAX_FLASH_ITEMFLASH_NUM 20

class FlashItemflashDesc : public NFIDescStore
{
public:
	FlashItemflashDesc();
	virtual ~FlashItemflashDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FlashItemflash_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FlashItemflash_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FlashItemflash_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FlashItemflash_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FlashItemflashDesc, proto_ff_s::E_FlashItemflash_s, E_FlashItemflash, MAX_FLASH_ITEMFLASH_NUM);
DECLARE_IDCREATE(FlashItemflashDesc);
};
