#include "IntimacyIntimacyDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(IntimacyIntimacyDesc, EOT_CONST_INTIMACY_INTIMACY_DESC_ID, NFShmObj)

IntimacyIntimacyDesc::IntimacyIntimacyDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

IntimacyIntimacyDesc::~IntimacyIntimacyDesc()
{
}

int IntimacyIntimacyDesc::CreateInit()
{
	Initialize();
	return 0;
}

int IntimacyIntimacyDesc::ResumeInit()
{
	return 0;
}

int IntimacyIntimacyDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_intimacyintimacy table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.intimacyintimacy_list_size() < 0) || (table.intimacyintimacy_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.intimacyintimacy_list_size());
		return -2;
	}

	for (int i = 0; i < table.intimacyintimacy_list_size(); i++)
	{
		const proto_ff::intimacyintimacy& desc = table.intimacyintimacy_list(i);
		auto pDesc = m_astDesc.Insert(desc.lv());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.lv());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.intimacyintimacy_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int IntimacyIntimacyDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::intimacyintimacy_s * IntimacyIntimacyDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::intimacyintimacy_s * IntimacyIntimacyDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

