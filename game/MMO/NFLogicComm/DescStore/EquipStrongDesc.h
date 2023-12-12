#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONG_NUM 2048

#define MAX_COM_INDEX_EQUIP_STRONG_POSITION_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STRONG_POSITION_NUM 64

#define MAX_COM_INDEX_EQUIP_STRONG_WEARQUALITY_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STRONG_WEARQUALITY_NUM 64

struct EquipStrongPositionWearquality
{
	EquipStrongPositionWearquality()
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
		m_position=0;
		m_wearQuality=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_position;
	int64_t m_wearQuality;
	bool operator==(const EquipStrongPositionWearquality& data) const
	{
		 return m_position==data.m_position && m_wearQuality==data.m_wearQuality;
	}
};

namespace std
{
	template<>
	struct hash<EquipStrongPositionWearquality>
	{
		size_t operator()(const EquipStrongPositionWearquality& data) const
		{
			return NFHash::hash_combine(data.m_position,data.m_wearQuality);
		}
	};
}


class EquipStrongDesc : public NFIDescTemplate<EquipStrongDesc, proto_ff_s::E_EquipStrong_s, EOT_CONST_EQUIP_STRONG_DESC_ID, MAX_EQUIP_STRONG_NUM>
{
public:
	EquipStrongDesc();
	virtual ~EquipStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_EquipStrong_s* GetDescByPositionWearquality(int64_t Position, int64_t Wearquality);
private:
	NFShmHashMap<EquipStrongPositionWearquality ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STRONG_POSITION_NUM*UNIQUE_KEY_MAX_COM_INDEX_EQUIP_STRONG_WEARQUALITY_NUM> m_PositionWearqualityComIndexMap;
};
