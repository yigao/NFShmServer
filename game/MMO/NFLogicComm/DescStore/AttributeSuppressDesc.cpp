#include "AttributeSuppressDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

AttributeSuppressDesc::AttributeSuppressDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AttributeSuppressDesc::~AttributeSuppressDesc()
{
}

int AttributeSuppressDesc::CreateInit()
{
	return 0;
}

int AttributeSuppressDesc::ResumeInit()
{
	return 0;
}

int AttributeSuppressDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AttributeSuppressDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AttributeSuppress table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_attributesuppress_list_size() < 0) || (table.e_attributesuppress_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_attributesuppress_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_attributesuppress_list_size(); i++)
	{
		const proto_ff::E_AttributeSuppress& desc = table.e_attributesuppress_list(i);
		if (desc.has_m_lvldiff() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_lvldiff()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_lvldiff());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_lvldiff());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_lvldiff());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_lvldiff());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_lvldiff(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_lvldiff());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_lvldiff()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_lvldiff());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_attributesuppress_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AttributeSuppressDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

