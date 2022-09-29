#include "FestivalBigyanhuacostDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(FestivalBigyanhuacostDesc, EOT_CONST_FESTIVAL_BIGYANHUACOST_DESC_ID, NFShmObj)

FestivalBigyanhuacostDesc::FestivalBigyanhuacostDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalBigyanhuacostDesc::~FestivalBigyanhuacostDesc()
{
}

int FestivalBigyanhuacostDesc::CreateInit()
{
	Initialize();
	return 0;
}

int FestivalBigyanhuacostDesc::ResumeInit()
{
	return 0;
}

int FestivalBigyanhuacostDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_festivalbigyanhuacost table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.festivalbigyanhuacost_list_size() < 0) || (table.festivalbigyanhuacost_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.festivalbigyanhuacost_list_size());
		return -2;
	}

	for (int i = 0; i < table.festivalbigyanhuacost_list_size(); i++)
	{
		const proto_ff::festivalbigyanhuacost& desc = table.festivalbigyanhuacost_list(i);
		if (desc.has_times() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.times());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.times());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.festivalbigyanhuacost_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FestivalBigyanhuacostDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::festivalbigyanhuacost_s * FestivalBigyanhuacostDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::festivalbigyanhuacost_s * FestivalBigyanhuacostDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

