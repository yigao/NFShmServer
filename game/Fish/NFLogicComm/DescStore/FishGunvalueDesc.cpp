#include "FishGunvalueDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(FishGunvalueDesc, EOT_CONST_FISH_GUNVALUE_DESC_ID, NFShmObj)

FishGunvalueDesc::FishGunvalueDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FishGunvalueDesc::~FishGunvalueDesc()
{
}

int FishGunvalueDesc::CreateInit()
{
	return 0;
}

int FishGunvalueDesc::ResumeInit()
{
	return 0;
}

int FishGunvalueDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishGunvalueDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FishGunvalue table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_fishgunvalue_list_size() < 0) || (table.e_fishgunvalue_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_fishgunvalue_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_fishgunvalue_list_size(); i++)
	{
		const proto_ff::E_FishGunvalue& desc = table.e_fishgunvalue_list(i);
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
		uint64_t hashKey = desc.m_id();
		if (hashKey < NF_MAX_DESC_STORE_INDEX_SIZE)
		{
			if (m_astDescIndex[hashKey] != -1)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist repeated key:{}", GetFileName(), hashKey);
				m_astDescIndex[hashKey] = -1;
			}
			else
			{
				m_astDescIndex[hashKey] = curIndex;
			}
		}
		else
		{
			//NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc store:{} exist key:{} than the max index:{}", GetFileName(), hashKey, NF_MAX_DESC_STORE_INDEX_SIZE);
		}
		CHECK_EXPR_ASSERT(GetDesc(hashKey) == pDesc, -1, "GetDesc != pDesc, id:{}", hashKey);
	}
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		if(m_GameidRoomidGunidComIndexMap.full())
		{
			CHECK_EXPR_ASSERT(m_GameidRoomidGunidComIndexMap.find(pDesc->m_gameid) != m_GameidRoomidGunidComIndexMap.end(), -1, "space not enough");
		}
		m_GameidRoomidGunidComIndexMap[pDesc->m_gameid];
		auto iter_0 = m_GameidRoomidGunidComIndexMap.find(pDesc->m_gameid);
		if(iter_0 != m_GameidRoomidGunidComIndexMap.end())
		{
			std::string error = "gameId:" + NFCommon::tostr(pDesc->m_gameid);
			error += ", roomId:" + NFCommon::tostr(pDesc->m_roomid);
			if(iter_0->second.full())
			{
				CHECK_EXPR_ASSERT(iter_0->second.find(pDesc->m_roomid) != iter_0->second.end(), -1, "space not enough");
			}
			iter_0->second[pDesc->m_roomid];
			auto iter_1 = iter_0->second.find(pDesc->m_roomid);
			if(iter_1 != iter_0->second.end())
			{
				error += ", gunId:" + NFCommon::tostr(pDesc->m_gunid);
				if(iter_1->second.full())
				{
					CHECK_EXPR_ASSERT(iter_1->second.find(pDesc->m_gunid) != iter_1->second.end(), -1, "space not enough");
				}
				CHECK_EXPR_ASSERT(iter_1->second.find(pDesc->m_gunid) == iter_1->second.end(), -1, "index: gunId repeated:{}", error);
				iter_1->second[pDesc->m_gunid] = i;
			}
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_fishgunvalue_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FishGunvalueDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_FishGunvalue_s * FishGunvalueDesc::GetDesc(int64_t id) const
{
	if (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)
	{
		int index = m_astDescIndex[id];
		if (index >= 0)
		{
			CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
			return &m_astDesc[index];
		}
	}

	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		int index = iter->second;
		CHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, "the index:{} of the id:{} exist error, than the m_astDesc max index:{}", index, id, m_astDesc.size());
		return &m_astDesc[index];
	}

	return NULL;
}

proto_ff_s::E_FishGunvalue_s * FishGunvalueDesc::GetDesc(int64_t id)
{
	return const_cast<proto_ff_s::E_FishGunvalue_s *>((static_cast<const FishGunvalueDesc*>(this))->GetDesc(id));
}

int FishGunvalueDesc::GetDescIndex(int id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		return iter->second;
	}

	return -1;
}

const proto_ff_s::E_FishGunvalue_s * FishGunvalueDesc::GetDescByIndex(int index) const
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

proto_ff_s::E_FishGunvalue_s * FishGunvalueDesc::GetDescByIndex(int index)
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

const proto_ff_s::E_FishGunvalue_s* FishGunvalueDesc::GetDescByGameidRoomidGunid(int64_t Gameid, int64_t Roomid, int64_t Gunid)
{
	auto iter = m_GameidRoomidGunidComIndexMap.find(Gameid);
	if(iter != m_GameidRoomidGunidComIndexMap.end())
	{
		auto iter_1 = iter->second.find(Roomid);
		if (iter_1 != iter->second.end())
		{
			auto iter_2 = iter_1->second.find(Gunid);
			if (iter_2 != iter_1->second.end())
			{
				return GetDescByIndex(iter_2->second);
			}
		}
	}
	return nullptr;
}

