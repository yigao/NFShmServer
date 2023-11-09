#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Functionunlock_s.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM 512

#define MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENTYPE_NUM 256

#define UNIQUE_KEY_MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENTYPE_NUM 16

#define MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENVAL_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENVAL_NUM 128

struct FunctionunlockFunctionunlockOpentypeOpenval
{
	FunctionunlockFunctionunlockOpentypeOpenval()
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
		m_openType=0;
		m_openVal=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
	}
	int64_t m_openType;
	int64_t m_openVal;
	bool operator==(const FunctionunlockFunctionunlockOpentypeOpenval& data) const
	{
		 return m_openType==data.m_openType && m_openVal==data.m_openVal;
	}
};

namespace std
{
	template<>
	struct hash<FunctionunlockFunctionunlockOpentypeOpenval>
	{
		size_t operator()(const FunctionunlockFunctionunlockOpentypeOpenval& data) const
		{
			return NFHash::hash_combine(data.m_openType,data.m_openVal);
		}
	};
}


class FunctionunlockFunctionunlockDesc : public NFIDescTemplate<FunctionunlockFunctionunlockDesc, proto_ff_s::E_FunctionunlockFunctionunlock_s, EOT_CONST_FUNCTIONUNLOCK_FUNCTIONUNLOCK_DESC_ID, MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_NUM>
{
public:
	FunctionunlockFunctionunlockDesc();
	virtual ~FunctionunlockFunctionunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FunctionunlockFunctionunlock_s*> GetDescByOpentypeOpenval(int64_t Opentype, int64_t Openval);
private:
	NFShmHashMap<FunctionunlockFunctionunlockOpentypeOpenval ,NFShmVector<uint64_t, MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENVAL_NUM>, UNIQUE_KEY_MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENTYPE_NUM*UNIQUE_KEY_MAX_COM_INDEX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_OPENVAL_NUM> m_OpentypeOpenvalComIndexMap;
};
