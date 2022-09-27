#include "EquipEquipDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(EquipEquipDesc, EOT_CONST_EQUIP_EQUIP_DESC_ID, NFShmObj)

EquipEquipDesc::EquipEquipDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipEquipDesc::~EquipEquipDesc()
{
}

int EquipEquipDesc::CreateInit()
{
	Initialize();
	return 0;
}

int EquipEquipDesc::ResumeInit()
{
	return 0;
}

int EquipEquipDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_equipequip table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.equipequip_list_size() < 0) || (table.equipequip_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.equipequip_list_size());
		return -2;
	}

	for (int i = 0; i < table.equipequip_list_size(); i++)
	{
		const proto_ff::equipequip& desc = table.equipequip_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.equipequip_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int EquipEquipDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::equipequip_s * EquipEquipDesc::CetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::equipequip_s * EquipEquipDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

