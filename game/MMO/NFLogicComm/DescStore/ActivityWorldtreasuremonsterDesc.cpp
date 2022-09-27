#include "ActivityWorldtreasuremonsterDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ActivityWorldtreasuremonsterDesc, EOT_CONST_ACTIVITY_WORLDTREASUREMONSTER_DESC_ID, NFShmObj)

ActivityWorldtreasuremonsterDesc::ActivityWorldtreasuremonsterDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ActivityWorldtreasuremonsterDesc::~ActivityWorldtreasuremonsterDesc()
{
}

int ActivityWorldtreasuremonsterDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ActivityWorldtreasuremonsterDesc::ResumeInit()
{
	return 0;
}

int ActivityWorldtreasuremonsterDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_activityworldTreasureMonster table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.activityworldTreasureMonster_list_size() < 0) || (table.activityworldTreasureMonster_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.activityworldTreasureMonster_list_size());
		return -2;
	}

	for (int i = 0; i < table.activityworldTreasureMonster_list_size(); i++)
	{
		const proto_ff::activityworldTreasureMonster& desc = table.activityworldTreasureMonster_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.activityworldTreasureMonster_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int ActivityWorldtreasuremonsterDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::activityworldTreasureMonster_s * ActivityWorldtreasuremonsterDesc::CetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::activityworldTreasureMonster_s * ActivityWorldtreasuremonsterDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

