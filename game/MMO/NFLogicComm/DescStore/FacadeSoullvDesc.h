#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_SOULLV_NUM 512

#define MAX_COM_INDEX_FACADE_SOULLV_SOULID_NUM 128

#define UNIQUE_KEY_MAX_COM_INDEX_FACADE_SOULLV_SOULID_NUM 4

#define MAX_COM_INDEX_FACADE_SOULLV_SOULLLV_NUM 4

#define UNIQUE_KEY_MAX_COM_INDEX_FACADE_SOULLV_SOULLLV_NUM 128

struct FacadeSoullvSoulidSoulllv
{
	FacadeSoullvSoulidSoulllv()
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
		m_soulID=0;
		m_soullLv=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_soulID;
	int64_t m_soullLv;
	bool operator==(const FacadeSoullvSoulidSoulllv& data) const
	{
		 return m_soulID==data.m_soulID && m_soullLv==data.m_soullLv;
	}
};

namespace std
{
	template<>
	struct hash<FacadeSoullvSoulidSoulllv>
	{
		size_t operator()(const FacadeSoullvSoulidSoulllv& data) const
		{
			return NFHash::hash_combine(data.m_soulID,data.m_soullLv);
		}
	};
}


class FacadeSoullvDesc : public NFIDescTemplate<FacadeSoullvDesc, proto_ff_s::E_FacadeSoullv_s, EOT_CONST_FACADE_SOULLV_DESC_ID, MAX_FACADE_SOULLV_NUM>
{
public:
	FacadeSoullvDesc();
	virtual ~FacadeSoullvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_FacadeSoullv_s* GetDescBySoulidSoulllv(int64_t Soulid, int64_t Soulllv);
private:
	NFShmHashMap<FacadeSoullvSoulidSoulllv ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_FACADE_SOULLV_SOULID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FACADE_SOULLV_SOULLLV_NUM> m_SoulidSoulllvComIndexMap;
};
