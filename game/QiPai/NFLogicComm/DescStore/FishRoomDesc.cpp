#include "FishRoomDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

FishRoomDesc::FishRoomDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FishRoomDesc::~FishRoomDesc()
{
}

int FishRoomDesc::CreateInit()
{
	return 0;
}

int FishRoomDesc::ResumeInit()
{
	return 0;
}

int FishRoomDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishRoomDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FishRoom table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_fishroom_list_size() < 0) || (table.e_fishroom_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_fishroom_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_fishroom_list_size(); i++)
	{
		const proto_ff::E_FishRoom& desc = table.e_fishroom_list(i);
		if (desc.has_m_id() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}

		if (m_minId == INVALID_ID)
		{
			m_minId = desc.m_id();
		}
		else
		{
			if (desc.m_id() < m_minId)
			{
				m_minId = desc.m_id();
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
	m_GameidIndexMap.clear();
	m_GameidRoomidComIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		if(m_GameidIndexMap.size() >= m_GameidIndexMap.max_size())
		{
			CHECK_EXPR_ASSERT(m_GameidIndexMap.find(pDesc->m_gameId) != m_GameidIndexMap.end(), -1, "index:gameId key:{}, space not enough", pDesc->m_gameId);
		}
		m_GameidIndexMap[pDesc->m_gameId].push_back(iter->first);
		{
			FishRoomGameidRoomid data;
			data.m_gameId = pDesc->m_gameId;
			data.m_roomId = pDesc->m_roomId;
			if(m_GameidRoomidComIndexMap.size() >= m_GameidRoomidComIndexMap.max_size())
			{
				CHECK_EXPR_ASSERT(m_GameidRoomidComIndexMap.find(data) != m_GameidRoomidComIndexMap.end(), -1, "space not enough");
			}
			m_GameidRoomidComIndexMap[data] = iter->first;
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_fishroom_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FishRoomDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

std::vector<const proto_ff_s::E_FishRoom_s*> FishRoomDesc::GetDescByGameid(int64_t Gameid) const
{
	std::vector<const proto_ff_s::E_FishRoom_s*> m_vec;
	auto iter = m_GameidIndexMap.find(Gameid);
	if(iter != m_GameidIndexMap.end())
	{
		for(int i = 0; i < (int)iter->second.size(); i++)
		{
			auto pDesc = GetDesc(iter->second[i]);
			CHECK_EXPR_CONTINUE(pDesc, "key:{} GetDesc error:{}", Gameid, iter->second[i]);
			m_vec.push_back(pDesc);
		}
	}
	return m_vec;
}

const proto_ff_s::E_FishRoom_s* FishRoomDesc::GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid)
{
	FishRoomGameidRoomid data;
	data.m_gameId = Gameid;
	data.m_roomId = Roomid;
	auto iter = m_GameidRoomidComIndexMap.find(data);
	if(iter != m_GameidRoomidComIndexMap.end())
	{
		auto pDesc = GetDesc(iter->second);
		CHECK_EXPR(pDesc, nullptr, "GetDesc failed:{}", iter->second);
		return pDesc;
	}
	return nullptr;
}

