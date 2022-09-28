#include "TreasureFragmentDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(TreasureFragmentDesc, EOT_CONST_TREASURE_FRAGMENT_DESC_ID, NFShmObj)

TreasureFragmentDesc::TreasureFragmentDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TreasureFragmentDesc::~TreasureFragmentDesc()
{
}

int TreasureFragmentDesc::CreateInit()
{
	Initialize();
	return 0;
}

int TreasureFragmentDesc::ResumeInit()
{
	return 0;
}

int TreasureFragmentDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_treasurefragment table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.treasurefragment_list_size() < 0) || (table.treasurefragment_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.treasurefragment_list_size());
		return -2;
	}

	for (int i = 0; i < table.treasurefragment_list_size(); i++)
	{
		const proto_ff::treasurefragment& desc = table.treasurefragment_list(i);
		auto pDesc = m_astDesc.Insert(desc.fragmentid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.fragmentid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.treasurefragment_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int TreasureFragmentDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::treasurefragment_s * TreasureFragmentDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::treasurefragment_s * TreasureFragmentDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

