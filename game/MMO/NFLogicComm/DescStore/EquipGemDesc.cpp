#include "EquipGemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(EquipGemDesc, EOT_CONST_EQUIP_GEM_DESC_ID, NFShmObj)

EquipGemDesc::EquipGemDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EquipGemDesc::~EquipGemDesc()
{
}

int EquipGemDesc::CreateInit()
{
	Initialize();
	return 0;
}

int EquipGemDesc::ResumeInit()
{
	return 0;
}

int EquipGemDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_equipgem table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.equipgem_list_size() < 0) || (table.equipgem_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.equipgem_list_size());
		return -2;
	}

	for (int i = 0; i < table.equipgem_list_size(); i++)
	{
		const proto_ff::equipgem& desc = table.equipgem_list(i);
		if (desc.has_position() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.position());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.position());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.equipgem_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int EquipGemDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::equipgem_s * EquipGemDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::equipgem_s * EquipGemDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

