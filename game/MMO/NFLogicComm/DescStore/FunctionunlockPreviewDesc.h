#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_PREVIEW_NUM 32

class FunctionunlockPreviewDesc : public NFIDescStore
{
public:
	FunctionunlockPreviewDesc();
	virtual ~FunctionunlockPreviewDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FunctionunlockPreview_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FunctionunlockPreview_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FunctionunlockPreview_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FunctionunlockPreview_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FunctionunlockPreviewDesc, proto_ff_s::E_FunctionunlockPreview_s, E_FunctionunlockPreview, MAX_FUNCTIONUNLOCK_PREVIEW_NUM);
DECLARE_IDCREATE(FunctionunlockPreviewDesc);
};
