#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Avatar_s.h"

#define MAX_AVATAR_VALUE_NUM 4096

#define MAX_COM_INDEX_AVATAR_VALUE_TYPE_NUM 1024

#define UNIQUE_KEY_MAX_COM_INDEX_AVATAR_VALUE_TYPE_NUM 16

#define MAX_COM_INDEX_AVATAR_VALUE_LV_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_AVATAR_VALUE_LV_NUM 1024

struct AvatarValueTypeLv
{
	AvatarValueTypeLv()
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
		m_type=0;
		m_lv=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_type;
	int64_t m_lv;
	bool operator==(const AvatarValueTypeLv& data) const
	{
		 return m_type==data.m_type && m_lv==data.m_lv;
	}
};

namespace std
{
	template<>
	struct hash<AvatarValueTypeLv>
	{
		size_t operator()(const AvatarValueTypeLv& data) const
		{
			return NFHash::hash_combine(data.m_type,data.m_lv);
		}
	};
}


class AvatarValueDesc : public NFIDescTemplate<AvatarValueDesc, proto_ff_s::E_AvatarValue_s, EOT_CONST_AVATAR_VALUE_DESC_ID, MAX_AVATAR_VALUE_NUM>
{
public:
	AvatarValueDesc();
	virtual ~AvatarValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_AvatarValue_s* GetDescByTypeLv(int64_t Type, int64_t Lv);
private:
	NFShmHashMap<AvatarValueTypeLv ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_AVATAR_VALUE_TYPE_NUM*UNIQUE_KEY_MAX_COM_INDEX_AVATAR_VALUE_LV_NUM> m_TypeLvComIndexMap;
};
