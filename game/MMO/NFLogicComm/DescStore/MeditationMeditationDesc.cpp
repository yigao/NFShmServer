#include "MeditationMeditationDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(MeditationMeditationDesc, EOT_CONST_MEDITATION_MEDITATION_DESC_ID, NFShmObj)

MeditationMeditationDesc::MeditationMeditationDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MeditationMeditationDesc::~MeditationMeditationDesc()
{
}

int MeditationMeditationDesc::CreateInit()
{
	Initialize();
	return 0;
}

int MeditationMeditationDesc::ResumeInit()
{
	return 0;
}

int MeditationMeditationDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "MeditationMeditationDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_MeditationMeditation table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());
	Initialize();

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_meditationmeditation_list_size() < 0) || (table.e_meditationmeditation_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_meditationmeditation_list_size());
		return -2;
	}

	m_astDesc.resize(table.e_meditationmeditation_list_size());
	m_astDescIndex.resize(m_astDescIndex.max_size());
	for(int i = 0; i < (int)m_astDescIndex.size(); i++)
	{
		m_astDescIndex[i] = -1;
	}
	for (int i = 0; i < (int)table.e_meditationmeditation_list_size(); i++)
	{
		const proto_ff::E_MeditationMeditation& desc = table.e_meditationmeditation_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = &m_astDesc[i];
		CHECK_EXPR(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_id(), i);
		CHECK_EXPR(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_id());
		uint64_t hashKey = desc.m_id();
		if (hashKey < NF_MAX_DESC_STORE_INDEX_SIZE)
		{
			if (m_astDescIndex[hashKey] != -1)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist repeated key:{}", GetFileName(), hashKey);
				m_astDescIndex[hashKey] = -1;
			}
			else
			{
				m_astDescIndex[hashKey] = i;
			}
		}
		else
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist key:{} than the max index:{}", GetFileName(), hashKey, NF_MAX_DESC_STORE_INDEX_SIZE);
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_meditationmeditation_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int MeditationMeditationDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_MeditationMeditation_s * MeditationMeditationDesc::GetDesc(int id) const
{
	if (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)
	{
		int index = m_astDescIndex[id];
		if (index >= 0)
		{
			CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
			return &m_astDesc[index];
		}
	}

	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		int index = iter->second;
		CHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
		return &m_astDesc[index];
	}

	return NULL;
}

proto_ff_s::E_MeditationMeditation_s * MeditationMeditationDesc::GetDesc(int id)
{
	return const_cast<proto_ff_s::E_MeditationMeditation_s *>((static_cast<const MeditationMeditationDesc*>(this))->GetDesc(id));
}

