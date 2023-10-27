#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Flash_s.h"

#define MAX_FLASH_ITEMFLASH_NUM 2

class FlashItemflashDesc : public NFIDescTemplate<FlashItemflashDesc, proto_ff_s::E_FlashItemflash_s, EOT_CONST_FLASH_ITEMFLASH_DESC_ID, MAX_FLASH_ITEMFLASH_NUM>
{
public:
	FlashItemflashDesc();
	virtual ~FlashItemflashDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
