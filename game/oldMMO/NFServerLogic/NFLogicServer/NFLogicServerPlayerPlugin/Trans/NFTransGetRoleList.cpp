// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleList.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleList
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <NFComm/NFPluginModule/NFIConfigModule.h>
#include <NFComm/NFCore/NFCommon.h>
#include <ClientServer.pb.h>
#include <ServerInternal.pb.h>
#include "NFTransGetRoleList.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFICommLogicModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetRoleList, EOT_TRANS_LOGIC_GET_ROLE_LIST, NFTransBase)

NFTransGetRoleList::NFTransGetRoleList(NFIPluginManager* pPluginManager):NFTransPlayerBase(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFTransGetRoleList::~NFTransGetRoleList()
{
}

int NFTransGetRoleList::CreateInit()
{
    SetState(EN_TGRL_INIT);
    m_bornZid = 0;
    m_proxyId = 0;
    m_clientId = 0;
    return 0;
}

int NFTransGetRoleList::ResumeInit()
{
    return 0;
}

int NFTransGetRoleList::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    const proto_ff::WorldToLogicGetRoleList* pLogin = dynamic_cast<const proto_ff::WorldToLogicGetRoleList*>(pCSMsgReq);
    CHECK_EXPR(pLogin, -1, "dynamic_cast<proto_ff::ClientLoginGateReq*>(pCSMsgReq) Failed");

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER) Failed");

    m_bornZid = pLogin->born_zone_id();
    m_proxyId = pLogin->proxy_id();
    m_clientId = pLogin->client_id();

    std::vector<storesvr_sqldata::storesvr_vk> vk_list;
    storesvr_sqldata::storesvr_vk cmd1;
    cmd1.set_column_name("playerId");
    cmd1.set_column_value(NFCommon::tostr(m_playerId));
    cmd1.set_column_type(storesvr_sqldata::E_COLUMNTYPE_NUM);
    cmd1.set_cmp_operator(storesvr_sqldata::E_CMPOP_EQUAL);
    cmd1.set_logic_operator(storesvr_sqldata::E_LOGICOP_AND);
    vk_list.push_back(cmd1);

    storesvr_sqldata::storesvr_vk cmd2;
    cmd2.set_column_name("bornZoneId");
    cmd2.set_column_value(NFCommon::tostr(m_bornZid));
    cmd2.set_column_type(storesvr_sqldata::E_COLUMNTYPE_NUM);
    cmd2.set_cmp_operator(storesvr_sqldata::E_CMPOP_EQUAL);
    vk_list.push_back(cmd2);

    FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                 proto_ff::E_STORESVR_C2S_SELECT, 0, pServerConfig->DefaultDBName,
                                                                 "tbRoleInfo", vk_list, "",
                                                                 GetGlobalID(), 0, m_playerId);
    return 0;
}

int NFTransGetRoleList::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                   uint32_t seq, uint32_t err_code)
{
    if (cmd == proto_ff::E_STORESVR_S2C_SELECT)
    {
        const storesvr_sqldata::storesvr_sel_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_sel_res *>(pSSMsgRes);
        CHECK_EXPR(pRes, -1, "pRes == NULL");
        CHECK_EXPR(pRes->is_lastbatch(), -1, "pRes->is_lastbatch() error");
        if (pRes->row_count() == 0)
        {

        }
        else {

        }
    }
    return 0;
}