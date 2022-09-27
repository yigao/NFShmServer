#include "ElementElementuiDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ElementElementuiDesc, EOT_CONST_ELEMENT_ELEMENTUI_DESC_ID, NFShmObj)

ElementElementuiDesc::ElementElementuiDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ElementElementuiDesc::~ElementElementuiDesc()
{
}

int ElementElementuiDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ElementElementuiDesc::ResumeInit()
{
	return 0;
}

int ElementElementuiDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_elementelementUI table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.elementelementUI_list_size() < 0) || (table.elementelementUI_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.elementelementUI_list_size());
		return -2;
	}

	for (int i = 0; i < table.elementelementUI_list_size(); i++)
	{
		const proto_ff::elementelementUI& desc = table.elementelementUI_list(i);
		auto pDesc = m_astDesc.Insert(desc.type());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.type());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.elementelementUI_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int ElementElementuiDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::elementelementUI_s * ElementElementuiDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::elementelementUI_s * ElementElementuiDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

