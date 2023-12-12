#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_PREVIEW_NUM 8

class ShenequipPreviewDesc : public NFIDescTemplate<ShenequipPreviewDesc, proto_ff_s::E_ShenequipPreview_s, EOT_CONST_SHENEQUIP_PREVIEW_DESC_ID, MAX_SHENEQUIP_PREVIEW_NUM>
{
public:
	ShenequipPreviewDesc();
	virtual ~ShenequipPreviewDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
