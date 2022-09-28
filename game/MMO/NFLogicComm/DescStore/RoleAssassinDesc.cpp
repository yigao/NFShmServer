#include "RoleAssassinDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(RoleAssassinDesc, EOT_CONST_ROLE_ASSASSIN_DESC_ID, NFShmObj)

RoleAssassinDesc::RoleAssassinDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RoleAssassinDesc::~RoleAssassinDesc()
{
}

int RoleAssassinDesc::CreateInit()
{
	Initialize();
	return 0;
}

int RoleAssassinDesc::ResumeInit()
{
	return 0;
}

int RoleAssassinDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_roleassassin table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.roleassassin_list_size() < 0) || (table.roleassassin_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.roleassassin_list_size());
		return -2;
	}

	for (int i = 0; i < table.roleassassin_list_size(); i++)
	{
		const proto_ff::roleassassin& desc = table.roleassassin_list(i);
		auto pDesc = m_astDesc.Insert(desc.lv());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.lv());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.roleassassin_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int RoleAssassinDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::roleassassin_s * RoleAssassinDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::roleassassin_s * RoleAssassinDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

