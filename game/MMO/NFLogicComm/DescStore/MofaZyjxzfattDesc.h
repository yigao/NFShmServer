#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXZFATT_NUM 128

#define MAX_COM_INDEX_MOFA_ZYJXZFATT_ATTID_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXZFATT_ATTID_NUM 16

#define MAX_COM_INDEX_MOFA_ZYJXZFATT_JXLV_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXZFATT_JXLV_NUM 16

struct MofaZyjxzfattAttidJxlv
{
	MofaZyjxzfattAttidJxlv()
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
		m_JxLv=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_AttID;
	int64_t m_JxLv;
	bool operator==(const MofaZyjxzfattAttidJxlv& data) const
	{
		 return m_AttID==data.m_AttID && m_JxLv==data.m_JxLv;
	}
};

namespace std
{
	template<>
	struct hash<MofaZyjxzfattAttidJxlv>
	{
		size_t operator()(const MofaZyjxzfattAttidJxlv& data) const
		{
			return NFHash::hash_combine(data.m_AttID,data.m_JxLv);
		}
	};
}


class MofaZyjxzfattDesc : public NFIDescTemplate<MofaZyjxzfattDesc, proto_ff_s::E_MofaZyjxzfatt_s, EOT_CONST_MOFA_ZYJXZFATT_DESC_ID, MAX_MOFA_ZYJXZFATT_NUM>
{
public:
	MofaZyjxzfattDesc();
	virtual ~MofaZyjxzfattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_MofaZyjxzfatt_s* GetDescByAttidJxlv(int64_t Attid, int64_t Jxlv);
private:
	NFShmHashMap<MofaZyjxzfattAttidJxlv ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXZFATT_ATTID_NUM*UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXZFATT_JXLV_NUM> m_AttidJxlvComIndexMap;
};
