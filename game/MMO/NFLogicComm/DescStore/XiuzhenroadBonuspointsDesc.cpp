#include "XiuzhenroadBonuspointsDesc.h"
#include "ItemItemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

XiuzhenroadBonuspointsDesc::XiuzhenroadBonuspointsDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenroadBonuspointsDesc::~XiuzhenroadBonuspointsDesc()
{
}

int XiuzhenroadBonuspointsDesc::CreateInit()
{
	return 0;
}

int XiuzhenroadBonuspointsDesc::ResumeInit()
{
	return 0;
}

int XiuzhenroadBonuspointsDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "XiuzhenroadBonuspointsDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_XiuzhenroadBonuspoints table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_xiuzhenroadbonuspoints_list_size() < 0) || (table.e_xiuzhenroadbonuspoints_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_xiuzhenroadbonuspoints_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_xiuzhenroadbonuspoints_list_size(); i++)
	{
		const proto_ff::E_XiuzhenroadBonuspoints& desc = table.e_xiuzhenroadbonuspoints_list(i);
		if (desc.has_m_totalrewardsid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_totalrewardsid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_totalrewardsid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_totalrewardsid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_totalrewardsid());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_totalrewardsid());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_totalrewardsid(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_totalrewardsid());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_totalrewardsid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_totalrewardsid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_xiuzhenroadbonuspoints_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int XiuzhenroadBonuspointsDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		for(int j = 0; j < (int)pDesc->m_totalitems.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_totalitems[j].m_id <= 0 || ItemItemDesc::Instance()->GetDesc(pDesc->m_totalitems[j].m_id)), result, "can't find the totalitems:{} in the  excel:item sheet:item", pDesc->m_totalitems[j].m_id);
		}
	}
	return result;
}

