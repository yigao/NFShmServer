#include "SoloDuanweiDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(SoloDuanweiDesc, EOT_CONST_SOLO_DUANWEI_DESC_ID, NFShmObj)

SoloDuanweiDesc::SoloDuanweiDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SoloDuanweiDesc::~SoloDuanweiDesc()
{
}

int SoloDuanweiDesc::CreateInit()
{
	Initialize();
	return 0;
}

int SoloDuanweiDesc::ResumeInit()
{
	return 0;
}

int SoloDuanweiDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_soloduanwei table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.soloduanwei_list_size() < 0) || (table.soloduanwei_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.soloduanwei_list_size());
		return -2;
	}

	for (int i = 0; i < table.soloduanwei_list_size(); i++)
	{
		const proto_ff::soloduanwei& desc = table.soloduanwei_list(i);
		auto pDesc = m_astDesc.Insert(desc.duanweiid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.duanweiid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.soloduanwei_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int SoloDuanweiDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::soloduanwei_s * SoloDuanweiDesc::CetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::soloduanwei_s * SoloDuanweiDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

