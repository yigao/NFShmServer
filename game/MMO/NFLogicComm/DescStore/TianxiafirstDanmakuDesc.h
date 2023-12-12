#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_DANMAKU_NUM 16

class TianxiafirstDanmakuDesc : public NFIDescTemplate<TianxiafirstDanmakuDesc, proto_ff_s::E_TianxiafirstDanmaku_s, EOT_CONST_TIANXIAFIRST_DANMAKU_DESC_ID, MAX_TIANXIAFIRST_DANMAKU_NUM>
{
public:
	TianxiafirstDanmakuDesc();
	virtual ~TianxiafirstDanmakuDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
