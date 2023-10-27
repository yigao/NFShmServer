#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Flash_s.h"

#define MAX_FLASH_FLASH_NUM 512

class FlashFlashDesc : public NFIDescTemplate<FlashFlashDesc, proto_ff_s::E_FlashFlash_s, EOT_CONST_FLASH_FLASH_DESC_ID, MAX_FLASH_FLASH_NUM>
{
public:
	FlashFlashDesc();
	virtual ~FlashFlashDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
