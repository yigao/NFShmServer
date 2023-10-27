#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_EQUIP_NUM 2048

class ConflateEquipDesc : public NFIDescTemplate<ConflateEquipDesc, proto_ff_s::E_ConflateEquip_s, EOT_CONST_CONFLATE_EQUIP_DESC_ID, MAX_CONFLATE_EQUIP_NUM>
{
public:
	ConflateEquipDesc();
	virtual ~ConflateEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
