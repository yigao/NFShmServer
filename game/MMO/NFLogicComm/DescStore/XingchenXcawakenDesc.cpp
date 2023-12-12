#include "XingchenXcawakenDesc.h"
#include "ItemItemDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

XingchenXcawakenDesc::XingchenXcawakenDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XingchenXcawakenDesc::~XingchenXcawakenDesc()
{
}

int XingchenXcawakenDesc::CreateInit()
{
	return 0;
}

int XingchenXcawakenDesc::ResumeInit()
{
	return 0;
}

int XingchenXcawakenDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "XingchenXcawakenDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_XingchenXcawaken table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_xingchenxcawaken_list_size() < 0) || (table.e_xingchenxcawaken_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_xingchenxcawaken_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_xingchenxcawaken_list_size(); i++)
	{
		const proto_ff::E_XingchenXcawaken& desc = table.e_xingchenxcawaken_list(i);
		if (desc.has_m_positionnum() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}

		if (m_minId == INVALID_ID)
		{
			m_minId = desc.has_m_positionnum();
		}
		else
		{
			if (desc.has_m_positionnum() < m_minId)
			{
				m_minId = desc.has_m_positionnum();
			}
		}

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_positionnum()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_positionnum());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_positionnum());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_positionnum());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_positionnum()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_positionnum());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_positionnum()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_positionnum());
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
	m_PositionidAwaken_qualityComIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		{
			XingchenXcawakenPositionidAwaken_quality data;
			data.m_PositionID = pDesc->m_PositionID;
			data.m_awaken_quality = pDesc->m_awaken_quality;
			if(m_PositionidAwaken_qualityComIndexMap.size() >= m_PositionidAwaken_qualityComIndexMap.max_size())
			{
				CHECK_EXPR_ASSERT(m_PositionidAwaken_qualityComIndexMap.find(data) != m_PositionidAwaken_qualityComIndexMap.end(), -1, "space not enough");
			}
			m_PositionidAwaken_qualityComIndexMap[data] = iter->first;
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_xingchenxcawaken_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int XingchenXcawakenDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_MSG_RESULT((pDesc->m_awaken_item <= 0 || ItemItemDesc::Instance()->GetDesc(pDesc->m_awaken_item)), result, "can't find the awaken_item:{} in the  excel:item sheet:item", pDesc->m_awaken_item);
	}
	return result;
}

const proto_ff_s::E_XingchenXcawaken_s* XingchenXcawakenDesc::GetDescByPositionidAwaken_quality(int64_t Positionid, int64_t Awaken_quality)
{
	XingchenXcawakenPositionidAwaken_quality data;
	data.m_PositionID = Positionid;
	data.m_awaken_quality = Awaken_quality;
	auto iter = m_PositionidAwaken_qualityComIndexMap.find(data);
	if(iter != m_PositionidAwaken_qualityComIndexMap.end())
	{
		auto pDesc = GetDesc(iter->second);
		CHECK_EXPR(pDesc, nullptr, "GetDesc failed:{}", iter->second);
		return pDesc;
	}
	return nullptr;
}

