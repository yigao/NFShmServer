#include "AchievementAchievementDesc.h"
#include "ItemItemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

AchievementAchievementDesc::AchievementAchievementDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AchievementAchievementDesc::~AchievementAchievementDesc()
{
}

int AchievementAchievementDesc::CreateInit()
{
	return 0;
}

int AchievementAchievementDesc::ResumeInit()
{
	return 0;
}

int AchievementAchievementDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AchievementAchievementDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AchievementAchievement table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_achievementachievement_list_size() < 0) || (table.e_achievementachievement_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_achievementachievement_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_achievementachievement_list_size(); i++)
	{
		const proto_ff::E_AchievementAchievement& desc = table.e_achievementachievement_list(i);
		if (desc.has_m_achievementid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_achievementid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_achievementid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_achievementid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_achievementid());
			}
			continue;
		}
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_achievementid());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_achievementid(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_achievementid());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_achievementid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_achievementid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_achievementachievement_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AchievementAchievementDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		for(int j = 0; j < (int)pDesc->m_itemreward.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT((pDesc->m_itemreward[j].m_id <= 0 || ItemItemDesc::Instance()->GetDesc(pDesc->m_itemreward[j].m_id)), result, "can't find the itemreward:{} in the  excel:item sheet:item", pDesc->m_itemreward[j].m_id);
		}
	}
	return result;
}

