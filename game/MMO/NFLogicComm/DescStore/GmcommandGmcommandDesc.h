#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMCommand_s.h"

#define MAX_GMCOMMAND_GMCOMMAND_NUM 80

class GmcommandGmcommandDesc : public NFIDescStore
{
public:
	GmcommandGmcommandDesc(NFIPluginManager* pPluginManager);
	virtual ~GmcommandGmcommandDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::GMCommandGMCommand_s* GetDesc(int id) const;
	proto_ff_s::GMCommandGMCommand_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::GMCommandGMCommand_s, MAX_GMCOMMAND_GMCOMMAND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::GMCommandGMCommand_s, MAX_GMCOMMAND_GMCOMMAND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::GMCommandGMCommand_s, GMCommandGMCommand, MAX_GMCOMMAND_GMCOMMAND_NUM);
DECLARE_IDCREATE(GmcommandGmcommandDesc);
};
