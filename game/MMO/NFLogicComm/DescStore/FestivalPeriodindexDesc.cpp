#include "FestivalPeriodindexDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(FestivalPeriodindexDesc, EOT_CONST_FESTIVAL_PERIODINDEX_DESC_ID, NFShmObj)

FestivalPeriodindexDesc::FestivalPeriodindexDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalPeriodindexDesc::~FestivalPeriodindexDesc()
{
}

int FestivalPeriodindexDesc::CreateInit()
{
	return Initialize();
}

int FestivalPeriodindexDesc::ResumeInit()
{
	return 0;
}

int FestivalPeriodindexDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FestivalPeriodindexDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FestivalPeriodindex table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_festivalperiodindex_list_size() < 0) || (table.e_festivalperiodindex_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_festivalperiodindex_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_festivalperiodindex_list_size(); i++)
	{
		const proto_ff::E_FestivalPeriodindex& desc = table.e_festivalperiodindex_list(i);
		if (desc.has_m_minorigalday() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_minorigalday()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_minorigalday());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_minorigalday());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_minorigalday());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_minorigalday());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_minorigalday(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_minorigalday());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_minorigalday()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_minorigalday());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_festivalperiodindex_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FestivalPeriodindexDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_FestivalPeriodindex_s * FestivalPeriodindexDesc::GetDesc(int64_t id) const
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

proto_ff_s::E_FestivalPeriodindex_s * FestivalPeriodindexDesc::GetDesc(int64_t id)
{
	return const_cast<proto_ff_s::E_FestivalPeriodindex_s *>((static_cast<const FestivalPeriodindexDesc*>(this))->GetDesc(id));
}

int FestivalPeriodindexDesc::GetDescIndex(int id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		return iter->second;
	}

	return -1;
}

const proto_ff_s::E_FestivalPeriodindex_s * FestivalPeriodindexDesc::GetDescByIndex(int index) const
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

proto_ff_s::E_FestivalPeriodindex_s * FestivalPeriodindexDesc::GetDescByIndex(int index)
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

