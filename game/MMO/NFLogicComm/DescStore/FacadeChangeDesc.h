#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Facade_s.h"

#define MAX_FACADE_CHANGE_NUM 64

#define MAX_INDEX_FACADE_CHANGE_TYPE_NUM 32

#define UNIQUE_KEY_MAX_INDEX_FACADE_CHANGE_TYPE_NUM 8

class FacadeChangeDesc : public NFIDescTemplate<FacadeChangeDesc, proto_ff_s::E_FacadeChange_s, EOT_CONST_FACADE_CHANGE_DESC_ID, MAX_FACADE_CHANGE_NUM>
{
public:
	FacadeChangeDesc();
	virtual ~FacadeChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FacadeChange_s*> GetDescByType(int64_t Type) const;
private:
	NFShmHashMap<int64_t, NFShmVector<uint64_t, MAX_INDEX_FACADE_CHANGE_TYPE_NUM>,UNIQUE_KEY_MAX_INDEX_FACADE_CHANGE_TYPE_NUM> m_TypeIndexMap;
};
