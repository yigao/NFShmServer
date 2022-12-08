#include "TaskdynamicTaskcomcondDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(TaskdynamicTaskcomcondDesc, EOT_CONST_TASKDYNAMIC_TASKCOMCOND_DESC_ID, NFShmObj)

TaskdynamicTaskcomcondDesc::TaskdynamicTaskcomcondDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskdynamicTaskcomcondDesc::~TaskdynamicTaskcomcondDesc()
{
}

int TaskdynamicTaskcomcondDesc::CreateInit()
{
	Initialize();
	return 0;
}

int TaskdynamicTaskcomcondDesc::ResumeInit()
{
	return 0;
}

int TaskdynamicTaskcomcondDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_taskdynamictaskcomcond table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());
	Initialize();

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.taskdynamictaskcomcond_list_size() < 0) || (table.taskdynamictaskcomcond_list_size() > (int)(m_astDesc.GetMaxSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.taskdynamictaskcomcond_list_size());
		return -2;
	}

	m_astDesc.SetSize(table.taskdynamictaskcomcond_list_size());
	m_astDescIndex.SetSize(m_astDescIndex.GetMaxSize());
	for(int i = 0; i < (int)m_astDescIndex.GetSize(); i++)
	{
		m_astDescIndex[i] = -1;
	}
	for (int i = 0; i < (int)table.taskdynamictaskcomcond_list_size(); i++)
	{
		const proto_ff::taskdynamictaskcomcond& desc = table.taskdynamictaskcomcond_list(i);
		if (desc.has_comcondid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = &m_astDesc[i];
		CHECK_EXPR(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.comcondid());
		pDesc->read_from_pbmsg(desc);
		auto pIndex = m_astDescMap.Insert(desc.comcondid());
		CHECK_EXPR(pIndex, -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.comcondid());
		*pIndex = i;
		uint64_t hashKey = desc.comcondid();
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

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.taskdynamictaskcomcond_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int TaskdynamicTaskcomcondDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::taskdynamictaskcomcond_s * TaskdynamicTaskcomcondDesc::GetDesc(int id) const
{
	if (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)
	{
		int index = m_astDescIndex[id];
		if (index >= 0)
		{
			CHECK_EXPR_ASSERT(index < m_astDesc.GetSize(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.GetSize());
			return &m_astDesc[index];
		}
	}

	auto pIndex = m_astDescMap.Find(id);
	if (pIndex)
	{
		int index = *pIndex;
		CHECK_EXPR_ASSERT(index >= 0 && index < m_astDesc.GetSize(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.GetSize());
		return &m_astDesc[index];
	}

	return NULL;
}

proto_ff_s::taskdynamictaskcomcond_s * TaskdynamicTaskcomcondDesc::GetDesc(int id)
{
	return const_cast<proto_ff_s::taskdynamictaskcomcond_s *>((static_cast<const TaskdynamicTaskcomcondDesc*>(this))->GetDesc(id));
}

