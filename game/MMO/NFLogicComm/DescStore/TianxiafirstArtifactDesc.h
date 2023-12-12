#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_ARTIFACT_NUM 4

class TianxiafirstArtifactDesc : public NFIDescTemplate<TianxiafirstArtifactDesc, proto_ff_s::E_TianxiafirstArtifact_s, EOT_CONST_TIANXIAFIRST_ARTIFACT_DESC_ID, MAX_TIANXIAFIRST_ARTIFACT_NUM>
{
public:
	TianxiafirstArtifactDesc();
	virtual ~TianxiafirstArtifactDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
