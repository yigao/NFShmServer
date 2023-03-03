// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldSendGetRoleList.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldSendGetRoleList
//
// -------------------------------------------------------------------------

#include "NFTransWorldGetRoleList.h"
#include "ServerInternal2.pb.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "ServerInternalCmd2.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransWorldGetRoleList, EOT_NFTransWorldSendGetRoleList_ID, NFTransBase)

NFTransWorldGetRoleList::NFTransWorldGetRoleList()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransWorldGetRoleList::~NFTransWorldGetRoleList()
{
}

int NFTransWorldGetRoleList::CreateInit()
{
    m_uid = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_bornZid = 0;
    return 0;
}

int NFTransWorldGetRoleList::ResumeInit()
{
    return 0;
}

int NFTransWorldGetRoleList::Init(uint64_t uid, uint32_t proxyId, uint64_t clientId, uint32_t bornZid)
{
    m_uid = uid;
    m_proxyId = proxyId;
    m_clientId = clientId;
    m_bornZid = bornZid;
    return 0;
}

int NFTransWorldGetRoleList::SendGetRoleList()
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_NULL(pPlayer);

    proto_ff::WorldToLogicGetRoleList xData;
    xData.set_uid(m_uid);
    xData.set_born_zone_id(m_bornZid);
    xData.set_proxy_id(m_proxyId);
    xData.set_client_id(m_clientId);


    pPlayer->SendMsgToLogicServer(proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ, xData);
    return 0;
}