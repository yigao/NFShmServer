#include "GodrelicsConditionDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

GodrelicsConditionDesc::GodrelicsConditionDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodrelicsConditionDesc::~GodrelicsConditionDesc()
{
}

int GodrelicsConditionDesc::CreateInit()
{
	return 0;
}

int GodrelicsConditionDesc::ResumeInit()
{
	return 0;
}

int GodrelicsConditionDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GodrelicsConditionDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_GodrelicsCondition table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_godrelicscondition_list_size() < 0) || (table.e_godrelicscondition_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_godrelicscondition_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_godrelicscondition_list_size(); i++)
	{
		const proto_ff::E_GodrelicsCondition& desc = table.e_godrelicscondition_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_id()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_id());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_id());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_id());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_id()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_id()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_id());
	}
	m_GroupIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		if(m_GroupIndexMap.size() >= m_GroupIndexMap.max_size())
		{
			CHECK_EXPR_ASSERT(m_GroupIndexMap.find(pDesc->m_group) != m_GroupIndexMap.end(), -1, "index:group key:{}, space not enough", pDesc->m_group);
		}
		m_GroupIndexMap[pDesc->m_group].push_back(iter->first);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_godrelicscondition_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int GodrelicsConditionDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

std::vector<const proto_ff_s::E_GodrelicsCondition_s*> GodrelicsConditionDesc::GetDescByGroup(int64_t Group) const
{
	std::vector<const proto_ff_s::E_GodrelicsCondition_s*> m_vec;
	auto iter = m_GroupIndexMap.find(Group);
	if(iter != m_GroupIndexMap.end())
	{
		for(int i = 0; i < (int)iter->second.size(); i++)
		{
			auto pDesc = GetDesc(iter->second[i]);
			CHECK_EXPR_CONTINUE(pDesc, "key:{} GetDesc error:{}", Group, iter->second[i]);
			m_vec.push_back(pDesc);
		}
	}
	return m_vec;
}

