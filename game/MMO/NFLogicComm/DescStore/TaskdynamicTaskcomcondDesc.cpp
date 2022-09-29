#include "TaskdynamicTaskcomcondDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(TaskdynamicTaskcomcondDesc, EOT_CONST_TASKDYNAMIC_TASKCOMCOND_DESC_ID, NFShmObj)

TaskdynamicTaskcomcondDesc::TaskdynamicTaskcomcondDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
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

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.taskdynamictaskcomcond_list_size() < 0) || (table.taskdynamictaskcomcond_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.taskdynamictaskcomcond_list_size());
		return -2;
	}

	for (int i = 0; i < table.taskdynamictaskcomcond_list_size(); i++)
	{
		const proto_ff::taskdynamictaskcomcond& desc = table.taskdynamictaskcomcond_list(i);
		if (desc.has_comcondid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.comcondid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.comcondid());
		pDesc->read_from_pbmsg(desc);
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
	return m_astDesc.Find(id);
}

proto_ff_s::taskdynamictaskcomcond_s * TaskdynamicTaskcomcondDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

