#include "WelfareLvrewardDesc.h"
#include "BoxBoxDesc.h"
#include "VipVipDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

WelfareLvrewardDesc::WelfareLvrewardDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WelfareLvrewardDesc::~WelfareLvrewardDesc()
{
}

int WelfareLvrewardDesc::CreateInit()
{
	return 0;
}

int WelfareLvrewardDesc::ResumeInit()
{
	return 0;
}

int WelfareLvrewardDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "WelfareLvrewardDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_WelfareLvreward table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_welfarelvreward_list_size() < 0) || (table.e_welfarelvreward_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_welfarelvreward_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_welfarelvreward_list_size(); i++)
	{
		const proto_ff::E_WelfareLvreward& desc = table.e_welfarelvreward_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}

		if (m_minId == INVALID_ID)
		{
			m_minId = desc.has_m_id();
		}
		else
		{
			if (desc.has_m_id() < m_minId)
			{
				m_minId = desc.has_m_id();
			}
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

	for(int i = 0; i < (int)m_astDescIndex.size(); i++)
	{
		m_astDescIndex[i] = INVALID_ID;
	}

	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		int64_t index = (int64_t)iter->first - (int64_t)m_minId;
		if (index >= 0 && index < (int64_t)m_astDescIndex.size())
		{
			m_astDescIndex[index] = iter.m_curNode->m_self;
			CHECK_EXPR_ASSERT(iter == m_astDescMap.get_iterator(m_astDescIndex[index]), -1, "index error");
			CHECK_EXPR_ASSERT(GetDesc(iter->first) == &iter->second, -1, "GetDesc != iter->second, id:{}", iter->first);
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_welfarelvreward_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int WelfareLvrewardDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_MSG_RESULT((pDesc->m_vipReward <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_vipReward)), result, "can't find the vipReward:{} in the  excel:box sheet:box", pDesc->m_vipReward);
		CHECK_EXPR_MSG_RESULT((pDesc->m_vip <= 0 || VipVipDesc::Instance()->GetDesc(pDesc->m_vip)), result, "can't find the vip:{} in the  excel:vip sheet:vip", pDesc->m_vip);
		CHECK_EXPR_MSG_RESULT((pDesc->m_lvReward <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_lvReward)), result, "can't find the lvReward:{} in the  excel:box sheet:box", pDesc->m_lvReward);
	}
	return result;
}

