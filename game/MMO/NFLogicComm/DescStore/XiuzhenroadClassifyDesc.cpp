#include "XiuzhenroadClassifyDesc.h"
#include "BoxBoxDesc.h"
#include "RechargeRechargeDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

XiuzhenroadClassifyDesc::XiuzhenroadClassifyDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenroadClassifyDesc::~XiuzhenroadClassifyDesc()
{
}

int XiuzhenroadClassifyDesc::CreateInit()
{
	return 0;
}

int XiuzhenroadClassifyDesc::ResumeInit()
{
	return 0;
}

int XiuzhenroadClassifyDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "XiuzhenroadClassifyDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_XiuzhenroadClassify table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_xiuzhenroadclassify_list_size() < 0) || (table.e_xiuzhenroadclassify_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_xiuzhenroadclassify_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_xiuzhenroadclassify_list_size(); i++)
	{
		const proto_ff::E_XiuzhenroadClassify& desc = table.e_xiuzhenroadclassify_list(i);
		if (desc.has_m_typeid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_typeid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_typeid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_typeid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_typeid());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() >= m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_typeid()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_typeid());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_typeid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_typeid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_xiuzhenroadclassify_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int XiuzhenroadClassifyDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_MSG_RESULT((pDesc->m_rechargeid <= 0 || RechargeRechargeDesc::Instance()->GetDesc(pDesc->m_rechargeid)), result, "can't find the rechargeid:{} in the  excel:recharge sheet:recharge", pDesc->m_rechargeid);
		CHECK_EXPR_MSG_RESULT((pDesc->m_giftid <= 0 || BoxBoxDesc::Instance()->GetDesc(pDesc->m_giftid)), result, "can't find the giftid:{} in the  excel:box sheet:box", pDesc->m_giftid);
	}
	return result;
}

