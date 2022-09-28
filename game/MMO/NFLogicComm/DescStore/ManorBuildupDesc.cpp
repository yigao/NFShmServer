#include "ManorBuildupDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ManorBuildupDesc, EOT_CONST_MANOR_BUILDUP_DESC_ID, NFShmObj)

ManorBuildupDesc::ManorBuildupDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ManorBuildupDesc::~ManorBuildupDesc()
{
}

int ManorBuildupDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ManorBuildupDesc::ResumeInit()
{
	return 0;
}

int ManorBuildupDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_manorbuildUp table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.manorbuildup_list_size() < 0) || (table.manorbuildup_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.manorbuildup_list_size());
		return -2;
	}

	for (int i = 0; i < table.manorbuildup_list_size(); i++)
	{
		const proto_ff::manorbuildUp& desc = table.manorbuildup_list(i);
		//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.level());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.level());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.manorbuildup_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int ManorBuildupDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::manorbuildUp_s * ManorBuildupDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::manorbuildUp_s * ManorBuildupDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

