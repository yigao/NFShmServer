#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYATT_NUM 32

#define MAX_COM_INDEX_MOFA_ZYATT_ATTID_NUM 4

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYATT_ATTID_NUM 16

#define MAX_COM_INDEX_MOFA_ZYATT_QUALITY_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYATT_QUALITY_NUM 4

struct MofaZyattAttidQuality
{
	MofaZyattAttidQuality()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}
	int CreateInit()
	{
		m_AttID=0;
		m_quality=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_AttID;
	int64_t m_quality;
	bool operator==(const MofaZyattAttidQuality& data) const
	{
		 return m_AttID==data.m_AttID && m_quality==data.m_quality;
	}
};

namespace std
{
	template<>
	struct hash<MofaZyattAttidQuality>
	{
		size_t operator()(const MofaZyattAttidQuality& data) const
		{
			return NFHash::hash_combine(data.m_AttID,data.m_quality);
		}
	};
}


class MofaZyattDesc : public NFIDescTemplate<MofaZyattDesc, proto_ff_s::E_MofaZyatt_s, EOT_CONST_MOFA_ZYATT_DESC_ID, MAX_MOFA_ZYATT_NUM>
{
public:
	MofaZyattDesc();
	virtual ~MofaZyattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_MofaZyatt_s* GetDescByAttidQuality(int64_t Attid, int64_t Quality);
private:
	NFShmHashMap<MofaZyattAttidQuality ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYATT_ATTID_NUM*UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYATT_QUALITY_NUM> m_AttidQualityComIndexMap;
};
