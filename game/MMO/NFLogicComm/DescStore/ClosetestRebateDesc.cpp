#include "ClosetestRebateDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ClosetestRebateDesc, EOT_CONST_CLOSETEST_REBATE_DESC_ID, NFShmObj)

ClosetestRebateDesc::ClosetestRebateDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ClosetestRebateDesc::~ClosetestRebateDesc()
{
}

int ClosetestRebateDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ClosetestRebateDesc::ResumeInit()
{
	return 0;
}

int ClosetestRebateDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_closetestRebate table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.closetestrebate_list_size() < 0) || (table.closetestrebate_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.closetestrebate_list_size());
		return -2;
	}

	for (int i = 0; i < table.closetestrebate_list_size(); i++)
	{
		const proto_ff::closetestRebate& desc = table.closetestrebate_list(i);
		auto pDesc = m_astDesc.Insert(desc.day());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.day());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.closetestrebate_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int ClosetestRebateDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::closetestRebate_s * ClosetestRebateDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::closetestRebate_s * ClosetestRebateDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

