#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_STARUP_NUM 512

#define MAX_COM_INDEX_FACADE_STARUP_UPATTRIBUTEID_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_FACADE_STARUP_UPATTRIBUTEID_NUM 128

#define MAX_COM_INDEX_FACADE_STARUP_STARID_NUM 128

#define UNIQUE_KEY_MAX_COM_INDEX_FACADE_STARUP_STARID_NUM 8

struct FacadeStarupUpattributeidStarid
{
	FacadeStarupUpattributeidStarid()
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
		m_upAttributeId=0;
		m_starID=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_upAttributeId;
	int64_t m_starID;
	bool operator==(const FacadeStarupUpattributeidStarid& data) const
	{
		 return m_upAttributeId==data.m_upAttributeId && m_starID==data.m_starID;
	}
};

namespace std
{
	template<>
	struct hash<FacadeStarupUpattributeidStarid>
	{
		size_t operator()(const FacadeStarupUpattributeidStarid& data) const
		{
			return NFHash::hash_combine(data.m_upAttributeId,data.m_starID);
		}
	};
}


class FacadeStarupDesc : public NFIDescTemplate<FacadeStarupDesc, proto_ff_s::E_FacadeStarup_s, EOT_CONST_FACADE_STARUP_DESC_ID, MAX_FACADE_STARUP_NUM>
{
public:
	FacadeStarupDesc();
	virtual ~FacadeStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	const proto_ff_s::E_FacadeStarup_s* GetDescByUpattributeidStarid(int64_t Upattributeid, int64_t Starid);
private:
	NFShmHashMap<FacadeStarupUpattributeidStarid ,uint64_t, UNIQUE_KEY_MAX_COM_INDEX_FACADE_STARUP_UPATTRIBUTEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FACADE_STARUP_STARID_NUM> m_UpattributeidStaridComIndexMap;
};
