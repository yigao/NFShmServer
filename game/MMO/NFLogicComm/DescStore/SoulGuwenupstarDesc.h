#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENUPSTAR_NUM 64

class SoulGuwenupstarDesc : public NFIDescTemplate<SoulGuwenupstarDesc, proto_ff_s::E_SoulGuwenupstar_s, EOT_CONST_SOUL_GUWENUPSTAR_DESC_ID, MAX_SOUL_GUWENUPSTAR_NUM>
{
public:
	SoulGuwenupstarDesc();
	virtual ~SoulGuwenupstarDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
