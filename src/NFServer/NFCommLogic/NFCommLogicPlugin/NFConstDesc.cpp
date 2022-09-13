// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomDesc.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoomDesc.cpp
//
// -------------------------------------------------------------------------

#include "NFConstDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFConstDesc, EOT_CONST_CONFIG_DESC_ID, NFShmObj)

NFConstDesc::NFConstDesc()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFConstDesc::~NFConstDesc()
{

}

int NFConstDesc::CreateInit()
{
    Initialize();
    memset(m_aiIndex, -1, sizeof(m_aiIndex));
    return 0;
}

int NFConstDesc::ResumeInit()
{
    return 0;
}

int NFConstDesc::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_ConstDesc table;
    NFResTable* pResTable = pDB->GetTable(GetFileName());
    CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

    int iRet = 0;
    iRet = pResTable->FindAllRecord(GetDBName(), &table);
    CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

    //NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

    CreateInit();

    if ((table.constdesc_list_size() < 0) || (table.constdesc_list_size() > (int)(m_astDesc.GetMaxSize())))
    {
        NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.constdesc_list_size());
        return -2;
    }

    m_astDesc.SetSize(table.constdesc_list_size());
    for (int i = 0; i < table.constdesc_list_size(); i++)
    {
        const proto_ff::ConstDesc& desc = table.constdesc_list(i);
        proto_ff_s::ConstDesc_s::read_from_pbmsg(desc, m_astDesc[i]);
		m_aiIndex[desc.id()] = i;
    }

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.constdesc_list_size());
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
    return 0;
}

int NFConstDesc::CheckWhenAllDataLoaded()
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");

    return 0;
}

const proto_ff_s::ConstDesc_s *NFConstDesc::GetDesc(proto_ff::enConstType type) const {
	CHECK_EXPR(m_aiIndex[type] >= 0 && m_aiIndex[type] < m_astDesc.GetSize(), NULL, "type [{}] not configed.", type);

	return &m_astDesc[m_aiIndex[type]];
}

std::string NFConstDesc::GetValue(proto_ff::enConstType type) const
{
	CHECK_EXPR(m_aiIndex[type] >= 0 && m_aiIndex[type] < m_astDesc.GetSize(), std::string(), "type [{}] not configed.", type);

	return m_astDesc[m_aiIndex[type]].value.GetString();
}


