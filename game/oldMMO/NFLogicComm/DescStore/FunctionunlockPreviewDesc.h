#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_PREVIEW_NUM 20

class FunctionunlockPreviewDesc : public NFIDescStore
{
public:
	FunctionunlockPreviewDesc();
	virtual ~FunctionunlockPreviewDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FunctionunlockPreview_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FunctionunlockPreview_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FunctionunlockPreview_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FunctionunlockPreview_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(FunctionunlockPreviewDesc, proto_ff_s::E_FunctionunlockPreview_s, E_FunctionunlockPreview, MAX_FUNCTIONUNLOCK_PREVIEW_NUM);
DECLARE_IDCREATE(FunctionunlockPreviewDesc);
};
