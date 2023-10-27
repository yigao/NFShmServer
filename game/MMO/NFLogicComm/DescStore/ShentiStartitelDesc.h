#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STARTITEL_NUM 16

class ShentiStartitelDesc : public NFIDescTemplate<ShentiStartitelDesc, proto_ff_s::E_ShentiStartitel_s, EOT_CONST_SHENTI_STARTITEL_DESC_ID, MAX_SHENTI_STARTITEL_NUM>
{
public:
	ShentiStartitelDesc();
	virtual ~ShentiStartitelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
