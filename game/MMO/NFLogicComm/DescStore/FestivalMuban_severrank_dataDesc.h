#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SEVERRANK_DATA_NUM 128

class FestivalMuban_severrank_dataDesc : public NFIDescTemplate<FestivalMuban_severrank_dataDesc, proto_ff_s::E_FestivalMuban_severrank_data_s, EOT_CONST_FESTIVAL_MUBAN_SEVERRANK_DATA_DESC_ID, MAX_FESTIVAL_MUBAN_SEVERRANK_DATA_NUM>
{
public:
	FestivalMuban_severrank_dataDesc();
	virtual ~FestivalMuban_severrank_dataDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
