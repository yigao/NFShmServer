#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_LATTICE_NUM 64

class NickgodLatticeDesc : public NFIDescTemplate<NickgodLatticeDesc, proto_ff_s::E_NickgodLattice_s, EOT_CONST_NICKGOD_LATTICE_DESC_ID, MAX_NICKGOD_LATTICE_NUM>
{
public:
	NickgodLatticeDesc();
	virtual ~NickgodLatticeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
