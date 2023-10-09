#include "MoneyrewardMoneyrewardDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(MoneyrewardMoneyrewardDesc, EOT_CONST_MONEYREWARD_MONEYREWARD_DESC_ID, NFShmObj)

MoneyrewardMoneyrewardDesc::MoneyrewardMoneyrewardDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MoneyrewardMoneyrewardDesc::~MoneyrewardMoneyrewardDesc()
{
}

int MoneyrewardMoneyrewardDesc::CreateInit()
{
	return Initialize();
}

int MoneyrewardMoneyrewardDesc::ResumeInit()
{
	return 0;
}

int MoneyrewardMoneyrewardDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "MoneyrewardMoneyrewardDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_MoneyrewardMoneyreward table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_moneyrewardmoneyreward_list_size() < 0) || (table.e_moneyrewardmoneyreward_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_moneyrewardmoneyreward_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_moneyrewardmoneyreward_list_size(); i++)
	{
		const proto_ff::E_MoneyrewardMoneyreward& desc = table.e_moneyrewardmoneyreward_list(i);
		if (desc.has_m_taskreward() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_taskreward()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_taskreward());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_taskreward());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_taskreward());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_taskreward());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_taskreward(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_taskreward());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_taskreward()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_taskreward());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_moneyrewardmoneyreward_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int MoneyrewardMoneyrewardDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_MoneyrewardMoneyreward_s * MoneyrewardMoneyrewardDesc::GetDesc(int64_t id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		int index = iter->second;
		CHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
		return &m_astDesc[index];
	}

	return NULL;
}

proto_ff_s::E_MoneyrewardMoneyreward_s * MoneyrewardMoneyrewardDesc::GetDesc(int64_t id)
{
	return const_cast<proto_ff_s::E_MoneyrewardMoneyreward_s *>((static_cast<const MoneyrewardMoneyrewardDesc*>(this))->GetDesc(id));
}

int MoneyrewardMoneyrewardDesc::GetDescIndex(int id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		return iter->second;
	}

	return -1;
}

const proto_ff_s::E_MoneyrewardMoneyreward_s * MoneyrewardMoneyrewardDesc::GetDescByIndex(int index) const
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

proto_ff_s::E_MoneyrewardMoneyreward_s * MoneyrewardMoneyrewardDesc::GetDescByIndex(int index)
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

