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

	if ((table.e_fishroom_list_size() < 0) || (table.e_fishroom_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_fishroom_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_fishroom_list_size(); i++)
	{
		const proto_ff::E_FishRoom& desc = table.e_fishroom_list(i);
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
		m_astDesc.push_back();
		auto pDesc = &m_astDesc.back();
		int curIndex = m_astDesc.size() - 1;
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDesc Index Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		auto iter = m_astDescMap.emplace_hint(desc.m_id(), curIndex);
		CHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, "m_astDescMap.Insert Failed desc.id:{}, key maybe exist", desc.m_id());
		CHECK_EXPR_ASSERT(GetDesc(desc.m_id()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_id());
	}
	m_GameidIndexMap.clear();
	m_GameidRoomidComIndexMap.clear();
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		if(m_GameidIndexMap.size() >= m_GameidIndexMap.max_size())
		{
			CHECK_EXPR_ASSERT(m_GameidIndexMap.find(pDesc->m_gameid) != m_GameidIndexMap.end(), -1, "index:gameId key:{}, space not enough", pDesc->m_gameid);
		}
		m_GameidIndexMap[pDesc->m_gameid].push_back(i);
		{
			FishRoomGameidRoomid data;
			data.m_gameId = pDesc->m_gameid;
			data.m_roomId = pDesc->m_roomid;
			if(m_GameidRoomidComIndexMap.size() >= m_GameidRoomidComIndexMap.max_size())
			{
				CHECK_EXPR_ASSERT(m_GameidRoomidComIndexMap.find(data) != m_GameidRoomidComIndexMap.end(), -1, "space not enough");
			}
			m_GameidRoomidComIndexMap[data] = i;
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
			auto pDesc = GetDescByIndex(iter->second[i]);
			CHECK_EXPR_CONTINUE(pDesc, "key:{} GetDescByIndex error:{}", Gameid, iter->second[i]);
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
		auto pDesc = GetDescByIndex(iter->second);
		CHECK_EXPR(pDesc, nullptr, "GetDescByIndex failed:{}", iter->second);
		return pDesc;
	}
	return nullptr;
}

