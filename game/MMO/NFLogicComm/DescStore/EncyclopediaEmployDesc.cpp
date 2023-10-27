#include "EncyclopediaEmployDesc.h"
#include "AvatarChangeDesc.h"
#include "PetDisplayDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

EncyclopediaEmployDesc::EncyclopediaEmployDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EncyclopediaEmployDesc::~EncyclopediaEmployDesc()
{
}

int EncyclopediaEmployDesc::CreateInit()
{
	return 0;
}

int EncyclopediaEmployDesc::ResumeInit()
{
	return 0;
}

int EncyclopediaEmployDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "EncyclopediaEmployDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_EncyclopediaEmploy table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_encyclopediaemploy_list_size() < 0) || (table.e_encyclopediaemploy_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_encyclopediaemploy_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_encyclopediaemploy_list_size(); i++)
	{
		const proto_ff::E_EncyclopediaEmploy& desc = table.e_encyclopediaemploy_list(i);
		if (desc.has_m_employid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_employid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_employid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_employid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_employid());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_employid());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_employid(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_employid());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_employid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_employid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_encyclopediaemploy_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int EncyclopediaEmployDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		CHECK_EXPR_MSG_RESULT((pDesc->m_itemid <= 0 || PetDisplayDesc::Instance()->GetDesc(pDesc->m_itemid)) || (pDesc->m_itemid <= 0 || AvatarChangeDesc::Instance()->GetDesc(pDesc->m_itemid)), result, "can't find the itemid:{} in the  excel:pet sheet:display or  excel:avatar sheet:change", pDesc->m_itemid);
	}
	return result;
}

