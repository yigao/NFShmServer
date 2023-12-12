#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXATT_NUM 128

#define MAX_COM_INDEX_MOFA_ZYJXATT_ATTID_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXATT_ATTID_NUM 16

#define MAX_COM_INDEX_MOFA_ZYJXATT_JXLV_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXATT_JXLV_NUM 16

struct MofaZyjxattAttidJxlv
{
	MofaZyjxattAttidJxlv()
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
	bool operator==(const MofaZyjxattAttidJxlv& data) const
	{
		 return m_AttID==data.m_AttID && m_JxLv==data.m_JxLv;
	}
};

namespace std
{
	template<>
	struct hash<MofaZyjxattAttidJxlv>
	{
		size_t operator()(const MofaZyjxattAttidJxlv& data) const
		{
			return NFHash::hash_combine(data.m_AttID,data.m_JxLv);
		}
	};
}


class MofaZyjxattDesc : public NFIDescTemplate<MofaZyjxattDesc, proto_ff_s::E_MofaZyjxatt_s, EOT_CONST_MOFA_ZYJXATT_DESC_ID, MAX_MOFA_ZYJXATT_NUM>
{
public:
	MofaZyjxattDesc();
	virtual ~MofaZyjxattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_MofaZyjxatt_s* GetDescByAttidJxlv(int64_t Attid, int64_t Jxlv);
private:
	NFShmHashMap<MofaZyjxattAttidJxlv ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXATT_ATTID_NUM*UNIQUE_KEY_MAX_COM_INDEX_MOFA_ZYJXATT_JXLV_NUM> m_AttidJxlvComIndexMap;
};
