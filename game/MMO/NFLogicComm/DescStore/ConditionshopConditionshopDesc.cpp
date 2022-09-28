#include "ConditionshopConditionshopDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ConditionshopConditionshopDesc, EOT_CONST_CONDITIONSHOP_CONDITIONSHOP_DESC_ID, NFShmObj)

ConditionshopConditionshopDesc::ConditionshopConditionshopDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ConditionshopConditionshopDesc::~ConditionshopConditionshopDesc()
{
}

int ConditionshopConditionshopDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ConditionshopConditionshopDesc::ResumeInit()
{
	return 0;
}

int ConditionshopConditionshopDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_conditionshopconditionshop table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.conditionshopconditionshop_list_size() < 0) || (table.conditionshopconditionshop_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.conditionshopconditionshop_list_size());
		return -2;
	}

	for (int i = 0; i < table.conditionshopconditionshop_list_size(); i++)
	{
		const proto_ff::conditionshopconditionshop& desc = table.conditionshopconditionshop_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.conditionshopconditionshop_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int ConditionshopConditionshopDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::conditionshopconditionshop_s * ConditionshopConditionshopDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::conditionshopconditionshop_s * ConditionshopConditionshopDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

