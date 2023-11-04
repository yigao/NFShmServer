#include "FunctionunlockFunctionunlockDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

FunctionunlockFunctionunlockDesc::FunctionunlockFunctionunlockDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FunctionunlockFunctionunlockDesc::~FunctionunlockFunctionunlockDesc()
{
}

int FunctionunlockFunctionunlockDesc::CreateInit()
{
	return 0;
}

int FunctionunlockFunctionunlockDesc::ResumeInit()
{
	return 0;
}

int FunctionunlockFunctionunlockDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FunctionunlockFunctionunlockDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FunctionunlockFunctionunlock table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_functionunlockfunctionunlock_list_size() < 0) || (table.e_functionunlockfunctionunlock_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_functionunlockfunctionunlock_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_functionunlockfunctionunlock_list_size(); i++)
	{
		const proto_ff::E_FunctionunlockFunctionunlock& desc = table.e_functionunlockfunctionunlock_list(i);
		if (desc.has_m_functionid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_functionid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_functionid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_functionid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_functionid());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_functionid()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_functionid());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_functionid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_functionid());
	}
	m_OpentypeOpenvalComIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		{
			FunctionunlockFunctionunlockOpentypeOpenval data;
			data.m_openType = pDesc->m_openType;
			data.m_openVal = pDesc->m_openVal;
			if(m_OpentypeOpenvalComIndexMap.size() >= m_OpentypeOpenvalComIndexMap.max_size())
			{
				CHECK_EXPR_ASSERT(m_OpentypeOpenvalComIndexMap.find(data) != m_OpentypeOpenvalComIndexMap.end(), -1, "space not enough");
			}
			CHECK_EXPR_ASSERT(m_OpentypeOpenvalComIndexMap[data].size() < m_OpentypeOpenvalComIndexMap[data].max_size(), -1, "space not enough");
			m_OpentypeOpenvalComIndexMap[data].push_back(iter->first);
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_functionunlockfunctionunlock_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FunctionunlockFunctionunlockDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

std::vector<const proto_ff_s::E_FunctionunlockFunctionunlock_s*> FunctionunlockFunctionunlockDesc::GetDescByOpentypeOpenval(int64_t Opentype, int64_t Openval)
{
	FunctionunlockFunctionunlockOpentypeOpenval data;
	data.m_openType = Opentype;
	data.m_openVal = Openval;
	std::vector<const proto_ff_s::E_FunctionunlockFunctionunlock_s*> m_vec;
	auto iter = m_OpentypeOpenvalComIndexMap.find(data);
	if(iter != m_OpentypeOpenvalComIndexMap.end())
	{
		for(int i = 0; i < (int)iter->second.size(); i++)
		{
			auto pDesc = GetDesc(iter->second[i]);
			CHECK_EXPR_CONTINUE(pDesc, "GetDesc failed:{}", iter->second[i]);
			m_vec.push_back(pDesc);
		}
	}
	return m_vec;
}

