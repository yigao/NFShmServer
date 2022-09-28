#include "IndulttaskTaskDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(IndulttaskTaskDesc, EOT_CONST_INDULTTASK_TASK_DESC_ID, NFShmObj)

IndulttaskTaskDesc::IndulttaskTaskDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

IndulttaskTaskDesc::~IndulttaskTaskDesc()
{
}

int IndulttaskTaskDesc::CreateInit()
{
	Initialize();
	return 0;
}

int IndulttaskTaskDesc::ResumeInit()
{
	return 0;
}

int IndulttaskTaskDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_indultTasktask table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.indulttasktask_list_size() < 0) || (table.indulttasktask_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.indulttasktask_list_size());
		return -2;
	}

	for (int i = 0; i < table.indulttasktask_list_size(); i++)
	{
		const proto_ff::indultTasktask& desc = table.indulttasktask_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.indulttasktask_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int IndulttaskTaskDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::indultTasktask_s * IndulttaskTaskDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::indultTasktask_s * IndulttaskTaskDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

