#include "AvatarFragmentDesc.h"
#include "AttributeAttributeDesc.h"
#include "ItemItemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

AvatarFragmentDesc::AvatarFragmentDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AvatarFragmentDesc::~AvatarFragmentDesc()
{
}

int AvatarFragmentDesc::CreateInit()
{
	return 0;
}

int AvatarFragmentDesc::ResumeInit()
{
	return 0;
}

int AvatarFragmentDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AvatarFragmentDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AvatarFragment table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_avatarfragment_list_size() < 0) || (table.e_avatarfragment_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_avatarfragment_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_avatarfragment_list_size(); i++)
	{
		const proto_ff::E_AvatarFragment& desc = table.e_avatarfragment_list(i);
		if (desc.has_m_fragmentid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_fragmentid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_fragmentid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_fragmentid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_fragmentid());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_fragmentid());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_fragmentid(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_fragmentid());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_fragmentid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_fragmentid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_avatarfragment_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AvatarFragmentDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		for(int j = 0; j < (int)pDesc->m_attribute.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_attribute[j].m_type <= 0 || AttributeAttributeDesc::Instance()->GetDesc(pDesc->m_attribute[j].m_type)), result, "can't find the attribute:{} in the  excel:attribute sheet:attribute", pDesc->m_attribute[j].m_type);
		}
		CHECK_EXPR_MSG_RESULT((pDesc->m_item <= 0 || ItemItemDesc::Instance()->GetDesc(pDesc->m_item)), result, "can't find the item:{} in the  excel:item sheet:item", pDesc->m_item);
	}
	return result;
}

