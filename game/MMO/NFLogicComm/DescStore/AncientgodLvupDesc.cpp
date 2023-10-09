#include "AncientgodLvupDesc.h"
#include "AncientgodAncientgodDesc.h"
#include "AttributeAttributeDesc.h"
#include "ItemItemDesc.h"
#include "MallMallDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(AncientgodLvupDesc, EOT_CONST_ANCIENTGOD_LVUP_DESC_ID, NFShmObj)

AncientgodLvupDesc::AncientgodLvupDesc():NFIDescStore()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AncientgodLvupDesc::~AncientgodLvupDesc()
{
}

int AncientgodLvupDesc::CreateInit()
{
	return Initialize();
}

int AncientgodLvupDesc::ResumeInit()
{
	return 0;
}

int AncientgodLvupDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "AncientgodLvupDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_AncientgodLvup table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_ancientgodlvup_list_size() < 0) || (table.e_ancientgodlvup_list_size() > (int)(m_astDesc.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_ancientgodlvup_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_ancientgodlvup_list_size(); i++)
	{
		const proto_ff::E_AncientgodLvup& desc = table.e_ancientgodlvup_list(i);
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

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_ancientgodlvup_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int AncientgodLvupDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(int i = 0; i < (int)m_astDesc.size(); i++)
	{
		auto pDesc = &m_astDesc[i];
		for(int j = 0; j < (int)pDesc->m_attribute.size(); j++)
		{
			CHECK_EXPR_MSG_RESULT(AttributeAttributeDesc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_attribute[j].m_type), result, "can't find the attribute:{} in the  excel:attribute sheet:attribute", pDesc->m_attribute[j].m_type);
		}
		CHECK_EXPR_MSG_RESULT(MallMallDesc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_mallid), result, "can't find the mallid:{} in the  excel:mall sheet:mall", pDesc->m_mallid);
		CHECK_EXPR_MSG_RESULT(ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_itemid), result, "can't find the itemid:{} in the  excel:item sheet:item", pDesc->m_itemid);
		CHECK_EXPR_MSG_RESULT(AncientgodAncientgodDesc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_ancientid), result, "can't find the ancientid:{} in the  excel:ancientgod sheet:ancientgod", pDesc->m_ancientid);
	}
	return result;
}

const proto_ff_s::E_AncientgodLvup_s * AncientgodLvupDesc::GetDesc(int64_t id) const
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

proto_ff_s::E_AncientgodLvup_s * AncientgodLvupDesc::GetDesc(int64_t id)
{
	return const_cast<proto_ff_s::E_AncientgodLvup_s *>((static_cast<const AncientgodLvupDesc*>(this))->GetDesc(id));
}

int AncientgodLvupDesc::GetDescIndex(int id) const
{
	auto iter = m_astDescMap.find(id);
	if (iter != m_astDescMap.end())
	{
		return iter->second;
	}

	return -1;
}

const proto_ff_s::E_AncientgodLvup_s * AncientgodLvupDesc::GetDescByIndex(int index) const
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

proto_ff_s::E_AncientgodLvup_s * AncientgodLvupDesc::GetDescByIndex(int index)
{
	CHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, "the index:{} exist error, than the m_astDesc max index:{}", index, m_astDesc.size());
	return &m_astDesc[index];
}

