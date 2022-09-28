#include "FestivalD_diaoluoDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(FestivalD_diaoluoDesc, EOT_CONST_FESTIVAL_D_DIAOLUO_DESC_ID, NFShmObj)

FestivalD_diaoluoDesc::FestivalD_diaoluoDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalD_diaoluoDesc::~FestivalD_diaoluoDesc()
{
}

int FestivalD_diaoluoDesc::CreateInit()
{
	Initialize();
	return 0;
}

int FestivalD_diaoluoDesc::ResumeInit()
{
	return 0;
}

int FestivalD_diaoluoDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_festivald_diaoluo table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.festivald_diaoluo_list_size() < 0) || (table.festivald_diaoluo_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.festivald_diaoluo_list_size());
		return -2;
	}

	for (int i = 0; i < table.festivald_diaoluo_list_size(); i++)
	{
		const proto_ff::festivald_diaoluo& desc = table.festivald_diaoluo_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.festivald_diaoluo_list_size());
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
	return 0;
}

int FestivalD_diaoluoDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::festivald_diaoluo_s * FestivalD_diaoluoDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::festivald_diaoluo_s * FestivalD_diaoluoDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

