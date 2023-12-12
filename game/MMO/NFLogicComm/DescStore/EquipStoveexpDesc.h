#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STOVEEXP_NUM 128

#define MAX_COM_INDEX_EQUIP_STOVEEXP_WEARQUALITY_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STOVEEXP_WEARQUALITY_NUM 16

#define MAX_COM_INDEX_EQUIP_STOVEEXP_QUALITY_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STOVEEXP_QUALITY_NUM 8

struct EquipStoveexpWearqualityQuality
{
	EquipStoveexpWearqualityQuality()
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
		m_wearQuality=0;
		m_quality=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_wearQuality;
	int64_t m_quality;
	bool operator==(const EquipStoveexpWearqualityQuality& data) const
	{
		 return m_wearQuality==data.m_wearQuality && m_quality==data.m_quality;
	}
};

namespace std
{
	template<>
	struct hash<EquipStoveexpWearqualityQuality>
	{
		size_t operator()(const EquipStoveexpWearqualityQuality& data) const
		{
			return NFHash::hash_combine(data.m_wearQuality,data.m_quality);
		}
	};
}


class EquipStoveexpDesc : public NFIDescTemplate<EquipStoveexpDesc, proto_ff_s::E_EquipStoveexp_s, EOT_CONST_EQUIP_STOVEEXP_DESC_ID, MAX_EQUIP_STOVEEXP_NUM>
{
public:
	EquipStoveexpDesc();
	virtual ~EquipStoveexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_EquipStoveexp_s* GetDescByWearqualityQuality(int64_t Wearquality, int64_t Quality);
private:
	NFShmHashMap<EquipStoveexpWearqualityQuality ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STOVEEXP_WEARQUALITY_NUM*UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STOVEEXP_QUALITY_NUM> m_WearqualityQualityComIndexMap;
};
