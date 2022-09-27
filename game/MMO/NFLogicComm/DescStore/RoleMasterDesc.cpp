#include "RoleMasterDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(RoleMasterDesc, EOT_CONST_ROLE_MASTER_DESC_ID, NFShmObj)

RoleMasterDesc::RoleMasterDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RoleMasterDesc::~RoleMasterDesc()
{
}

int RoleMasterDesc::CreateInit()
{
	Initialize();
	return 0;
}

int RoleMasterDesc::ResumeInit()
{
	return 0;
}

int RoleMasterDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_rolemaster table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.rolemaster_list_size() < 0) || (table.rolemaster_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.rolemaster_list_size());
		return -2;
	}

	for (int i = 0; i < table.rolemaster_list_size(); i++)
	{
		const proto_ff::rolemaster& desc = table.rolemaster_list(i);
		auto pDesc = m_astDesc.Insert(desc.lv());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.lv());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.rolemaster_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int RoleMasterDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::rolemaster_s * RoleMasterDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::rolemaster_s * RoleMasterDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

