#include "AncientgodAdvanceDesc.h"
#include "AncientgodAncientgodDesc.h"
#include "AttributeAttributeDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

AncientgodAdvanceDesc::AncientgodAdvanceDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AncientgodAdvanceDesc::~AncientgodAdvanceDesc()
{
}

int AncientgodAdvanceDesc::CreateInit()
{
	return 0;
}

int AncientgodAdvanceDesc::ResumeInit()
{
	return 0;
}

int AncientgodAdvanceDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AncientgodAdvanceDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AncientgodAdvance table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_ancientgodadvance_list_size() < 0) || (table.e_ancientgodadvance_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_ancientgodadvance_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_ancientgodadvance_list_size(); i++)
	{
		const proto_ff::E_AncientgodAdvance& desc = table.e_ancientgodadvance_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_id()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_id());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_id());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_id());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_id()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_id()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_id());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_ancientgodadvance_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AncientgodAdvanceDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		for(int j = 0; j < (int)pDesc->m_attribute.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_attribute[j].m_type <= 0 || AttributeAttributeDesc::Instance()->GetDesc(pDesc->m_attribute[j].m_type)), result, "can't find the attribute:{} in the  excel:attribute sheet:attribute", pDesc->m_attribute[j].m_type);
		}
		CHECK_EXPR_MSG_RESULT((pDesc->m_ancientID <= 0 || AncientgodAncientgodDesc::Instance()->GetDesc(pDesc->m_ancientID)), result, "can't find the ancientID:{} in the  excel:ancientgod sheet:ancientgod", pDesc->m_ancientID);
	}
	return result;
}

