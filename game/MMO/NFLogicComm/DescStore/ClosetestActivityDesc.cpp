#include "ClosetestActivityDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ClosetestActivityDesc, EOT_CONST_CLOSETEST_ACTIVITY_DESC_ID, NFShmObj)

ClosetestActivityDesc::ClosetestActivityDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ClosetestActivityDesc::~ClosetestActivityDesc()
{
}

int ClosetestActivityDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ClosetestActivityDesc::ResumeInit()
{
	return 0;
}

int ClosetestActivityDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_closetestActivity table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.closetestactivity_list_size() < 0) || (table.closetestactivity_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.closetestactivity_list_size());
		return -2;
	}

	for (int i = 0; i < table.closetestactivity_list_size(); i++)
	{
		const proto_ff::closetestActivity& desc = table.closetestactivity_list(i);
		//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.closetestactivity_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int ClosetestActivityDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::closetestActivity_s * ClosetestActivityDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::closetestActivity_s * ClosetestActivityDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

