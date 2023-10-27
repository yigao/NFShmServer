#include "GodevilAdvancelvDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

GodevilAdvancelvDesc::GodevilAdvancelvDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

GodevilAdvancelvDesc::~GodevilAdvancelvDesc()
{
}

int GodevilAdvancelvDesc::CreateInit()
{
	return 0;
}

int GodevilAdvancelvDesc::ResumeInit()
{
	return 0;
}

int GodevilAdvancelvDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GodevilAdvancelvDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_GodevilAdvancelv table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_godeviladvancelv_list_size() < 0) || (table.e_godeviladvancelv_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_godeviladvancelv_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_godeviladvancelv_list_size(); i++)
	{
		const proto_ff::E_GodevilAdvancelv& desc = table.e_godeviladvancelv_list(i);
		if (desc.has_m_wearlv() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_wearlv()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_wearlv());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_wearlv());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_wearlv());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_wearlv());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_wearlv(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_wearlv());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_wearlv()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_wearlv());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_godeviladvancelv_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int GodevilAdvancelvDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

