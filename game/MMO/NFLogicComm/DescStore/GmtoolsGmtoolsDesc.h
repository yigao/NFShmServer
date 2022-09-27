#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMtools_s.h"

#define MAX_GMTOOLS_GMTOOLS_NUM 20

class GmtoolsGmtoolsDesc : public NFIDescStore
{
public:
	GmtoolsGmtoolsDesc(NFIPluginManager* pPluginManager);
	virtual ~GmtoolsGmtoolsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::GMtoolsGMTools_s* GetDesc(int id) const;
	proto_ff_s::GMtoolsGMTools_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::GMtoolsGMTools_s, MAX_GMTOOLS_GMTOOLS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::GMtoolsGMTools_s, MAX_GMTOOLS_GMTOOLS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::GMtoolsGMTools_s, GMtoolsGMTools, MAX_GMTOOLS_GMTOOLS_NUM);
DECLARE_IDCREATE(GmtoolsGmtoolsDesc);
};
