#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/artifact_s.h"

#define MAX_ARTIFACT_ARTIFACT_NUM 40

class ArtifactArtifactDesc : public NFIDescStore
{
public:
	ArtifactArtifactDesc(NFIPluginManager* pPluginManager);
	virtual ~ArtifactArtifactDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::artifactartifact_s* GetDesc(int id) const;
	proto_ff_s::artifactartifact_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::artifactartifact_s, MAX_ARTIFACT_ARTIFACT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::artifactartifact_s, MAX_ARTIFACT_ARTIFACT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::artifactartifact_s, artifactartifact, MAX_ARTIFACT_ARTIFACT_NUM);
DECLARE_IDCREATE(ArtifactArtifactDesc);
};
