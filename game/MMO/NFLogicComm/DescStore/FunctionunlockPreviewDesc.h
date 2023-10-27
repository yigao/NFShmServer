#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_PREVIEW_NUM 32

class FunctionunlockPreviewDesc : public NFIDescTemplate<FunctionunlockPreviewDesc, proto_ff_s::E_FunctionunlockPreview_s, EOT_CONST_FUNCTIONUNLOCK_PREVIEW_DESC_ID, MAX_FUNCTIONUNLOCK_PREVIEW_NUM>
{
public:
	FunctionunlockPreviewDesc();
	virtual ~FunctionunlockPreviewDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
