// -------------------------------------------------------------------------
//    @FileName         :    NFNameDesc.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFNameDesc.cpp
//
// -------------------------------------------------------------------------

#include "NFNameDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFCore/NFRandom.hpp"

IMPLEMENT_IDCREATE_WITHTYPE(NFNameDesc, EOT_NAME_CONFIG_DESC_ID, NFShmObj)

NFNameDesc::NFNameDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFNameDesc::~NFNameDesc()
{

}

int NFNameDesc::CreateInit()
{
    Initialize();
    return 0;
}

int NFNameDesc::ResumeInit()
{
    return 0;
}

int NFNameDesc::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFNameDesc::Load() strFileName = {}", GetFileName());

    proto_ff::Sheet_NameDesc table;
    NFResTable* pResTable = pDB->GetTable(GetFileName());
    CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

    int iRet = 0;
    iRet = pResTable->FindAllRecord(GetDBName(), &table);
    CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

    //NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

    CreateInit();

    if ((table.namedesc_list_size() < 0) || (table.namedesc_list_size() > (int)(m_astDesc.GetMaxSize())))
    {
        NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.namedesc_list_size());
        return -2;
    }

    m_astDesc.SetSize(m_astDesc.GetMaxSize());
    for (int i = 0; i < (int)table.namedesc_list_size(); i++)
    {
        const proto_ff::NameDesc& desc = table.namedesc_list(i);
        CHECK_EXPR((int64_t)desc.id() >= 0 && (int64_t)desc.id() < (int64_t)m_astDesc.GetSize(), -1, "dest id:{} than the array max index:{}", desc.id(), m_astDesc.GetSize());
        m_astDesc[desc.id()].read_from_pbmsg(desc);
    }

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.namedesc_list_size());
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
    return 0;
}

int NFNameDesc::CheckWhenAllDataLoaded()
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");

    return 0;
}


const proto_ff_s::NameDesc_s *NFNameDesc::GetDesc(int id) const {
    CHECK_EXPR(id >= 0 && id < m_astDesc.GetSize(), NULL, "id:{} than the array max index", id, m_astDesc.GetSize());
    return &m_astDesc[id];
}

proto_ff_s::NameDesc_s *NFNameDesc::GetDesc(int id) {
    CHECK_EXPR(id >= 0 && id < m_astDesc.GetSize(), NULL, "id:{} than the array max index", id, m_astDesc.GetSize());
    return &m_astDesc[id];
}
