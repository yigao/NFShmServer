#include "HandbookFateDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(HandbookFateDesc, EOT_CONST_HANDBOOK_FATE_DESC_ID, NFShmObj)

HandbookFateDesc::HandbookFateDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

HandbookFateDesc::~HandbookFateDesc()
{
}

int HandbookFateDesc::CreateInit()
{
	Initialize();
	return 0;
}

int HandbookFateDesc::ResumeInit()
{
	return 0;
}

int HandbookFateDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_handbookfate table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.handbookfate_list_size() < 0) || (table.handbookfate_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.handbookfate_list_size());
		return -2;
	}

	for (int i = 0; i < table.handbookfate_list_size(); i++)
	{
		const proto_ff::handbookfate& desc = table.handbookfate_list(i);
		auto pDesc = m_astDesc.Insert(desc.fateid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.fateid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.handbookfate_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int HandbookFateDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::handbookfate_s * HandbookFateDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::handbookfate_s * HandbookFateDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

