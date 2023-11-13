#include "FacadeSoullvDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

FacadeSoullvDesc::FacadeSoullvDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FacadeSoullvDesc::~FacadeSoullvDesc()
{
}

int FacadeSoullvDesc::CreateInit()
{
	return 0;
}

int FacadeSoullvDesc::ResumeInit()
{
	return 0;
}

int FacadeSoullvDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FacadeSoullvDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FacadeSoullv table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_facadesoullv_list_size() < 0) || (table.e_facadesoullv_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_facadesoullv_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_facadesoullv_list_size(); i++)
	{
		const proto_ff::E_FacadeSoullv& desc = table.e_facadesoullv_list(i);
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
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_id()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_id());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_id()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_id());
	}
	m_SoulidSoulllvComIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		{
			FacadeSoullvSoulidSoulllv data;
			data.m_soulID = pDesc->m_soulID;
			data.m_soullLv = pDesc->m_soullLv;
			if(m_SoulidSoulllvComIndexMap.size() >= m_SoulidSoulllvComIndexMap.max_size())
			{
				CHECK_EXPR_ASSERT(m_SoulidSoulllvComIndexMap.find(data) != m_SoulidSoulllvComIndexMap.end(), -1, "space not enough");
			}
			m_SoulidSoulllvComIndexMap[data] = iter->first;
		}
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_facadesoullv_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FacadeSoullvDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_FacadeSoullv_s* FacadeSoullvDesc::GetDescBySoulidSoulllv(int64_t Soulid, int64_t Soulllv)
{
	FacadeSoullvSoulidSoulllv data;
	data.m_soulID = Soulid;
	data.m_soullLv = Soulllv;
	auto iter = m_SoulidSoulllvComIndexMap.find(data);
	if(iter != m_SoulidSoulllvComIndexMap.end())
	{
		auto pDesc = GetDesc(iter->second);
		CHECK_EXPR(pDesc, nullptr, "GetDesc failed:{}", iter->second);
		return pDesc;
	}
	return nullptr;
}

