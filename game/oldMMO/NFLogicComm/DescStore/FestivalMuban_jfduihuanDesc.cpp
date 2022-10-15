#include "FestivalMuban_jfduihuanDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(FestivalMuban_jfduihuanDesc, EOT_CONST_FESTIVAL_MUBAN_JFDUIHUAN_DESC_ID, NFShmObj)

FestivalMuban_jfduihuanDesc::FestivalMuban_jfduihuanDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FestivalMuban_jfduihuanDesc::~FestivalMuban_jfduihuanDesc()
{
}

int FestivalMuban_jfduihuanDesc::CreateInit()
{
	Initialize();
	return 0;
}

int FestivalMuban_jfduihuanDesc::ResumeInit()
{
	return 0;
}

int FestivalMuban_jfduihuanDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_festivalmuban_JFduihuan table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.festivalmuban_jfduihuan_list_size() < 0) || (table.festivalmuban_jfduihuan_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.festivalmuban_jfduihuan_list_size());
		return -2;
	}

	for (int i = 0; i < table.festivalmuban_jfduihuan_list_size(); i++)
	{
		const proto_ff::festivalmuban_JFduihuan& desc = table.festivalmuban_jfduihuan_list(i);
		if (desc.has_tiaojianid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.tiaojianid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.tiaojianid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.festivalmuban_jfduihuan_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FestivalMuban_jfduihuanDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::festivalmuban_JFduihuan_s * FestivalMuban_jfduihuanDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::festivalmuban_JFduihuan_s * FestivalMuban_jfduihuanDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}
