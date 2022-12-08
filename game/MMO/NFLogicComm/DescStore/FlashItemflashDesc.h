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
	const proto_ff_s::flashitemFlash_s* GetDesc(int id) const;
	proto_ff_s::flashitemFlash_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::flashitemFlash_s, flashitemFlash, MAX_FLASH_ITEMFLASH_NUM);
DECLARE_IDCREATE(FlashItemflashDesc);
};
