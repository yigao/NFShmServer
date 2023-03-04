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
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFWorldConfig.h"
#include "CSLogin.pb.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "ClientServerCmd.pb.h"
#include "NFWorldSessionMgr.h"
#include "NFWorldSession.h"

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

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ, xData, GetGlobalID());
    return 0;
}

int NFTransWorldGetRoleList::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch(nMsgId)
    {
        case proto_ff::LOGIC_TO_WORLD_GET_ROLE_LIST_RSP:
        {
            return OnHandleLogicGetRoleListRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransWorldGetRoleList::OnHandleLogicGetRoleListRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::LogicToWorldGetRoleListRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    uint64_t uid = xData.uid();
    uint64_t clientId = xData.client_id();
    uint32_t proxyId = xData.proxy_id();
    uint32_t bornZid = xData.born_zone_id();

    CHECK_EXPR(uid == m_uid, -1, "");
    CHECK_EXPR(clientId == m_clientId, -1, "");
    CHECK_EXPR(proxyId == m_proxyId, -1, "");
    CHECK_EXPR(bornZid == m_bornZid, -1, "");

    int err_code = xData.ret_code();

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1,
               "OnHandleLogicGetRoleListRsp, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
               uid);

    uint64_t newClientId = pPlayer->GetClientId();
    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
        NFLogError(NF_LOG_SYSTEMLOG, uid, "clientId != newClientId....uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return 0;
    }

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return 0;
    }

    if (pSession->IsDisconnect())
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession IsDisconnect, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return 0;
    }

    //再加一下状态判断 状态出错直接断开连接
    if (pSession->GetState() != EAccountState::login)
    {
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession->GetState() != EAccountState::login, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return 0;
    }

    proto_ff::ClientLoginRsp loginrsp;
    loginrsp.set_ret(proto_ff::RET_SUCCESS);
    loginrsp.set_unix_sec(NFTime::Now().UnixSec());
    loginrsp.set_unix_msec(NFTime::Now().UnixMSec());
    loginrsp.set_time_zone(NFServerTime::Instance()->CurTimeZone());
    if (err_code == 0)
    {
        pPlayer->ClearRoleInfo();

        //先判断是否注册人数已满,新号，且注册人数已超，则不让进
        if (xData.role_info_list_size() <= 0 && xData.register_num() >= pExternalConfig->MaxRegisterNum)
        {
            loginrsp.set_ret(proto_ff::RET_ACCOUNT_FULL);
        }
        else
        {
            for (int i = 0; i < (int) xData.role_info_list_size(); i++)
            {
                auto pDBProto = xData.mutable_role_info_list(i);
                NF_ASSERT(pDBProto);
                for (int j = 0; j < pDBProto->mutable_base()->mutable_facade()->growfacade_size(); j++)
                {
                    auto pAttr = pDBProto->mutable_base()->mutable_facade()->mutable_growfacade(j);
                    NF_ASSERT(pAttr);
                    if (pAttr->id() == proto_ff::GrowType_DEITY_TYPE)
                    {
                        pAttr->set_value(0);
                    }
                }

                auto pCharSimpleDB = loginrsp.add_role_lst();
                if (nullptr != pCharSimpleDB)
                {
                    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CharDBToCharSimpleDB(xData.role_info_list(i), *pCharSimpleDB);
                    auto pRoleInfo = pPlayer->CreateRoleInfo(pCharSimpleDB->cid());
                    CHECK_EXPR_ASSERT(pRoleInfo != nullptr, -1, "CreateRoleInfo Failed! cid:{}", pCharSimpleDB->cid());
                    pRoleInfo->SetRoleInfo(xData.role_info_list(i));
                }
            }
        }

        pPlayer->SetCharNum(xData.role_info_list_size());

        pSession->SetState(EAccountState::loading);
        pSession->SetStateTick(NFServerTime::Instance()->Tick());

        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "client login  account ok, playerId:{}, bornzid:{}", uid, pPlayer->GetLoginZid());
    }
    else
    {
        loginrsp.set_ret(err_code);
    }

    pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_LOGIN_RSP, loginrsp);
    SetFinished(0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransWorldGetRoleList::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0)
    {
        NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
        CHECK_EXPR(pPlayer, -1,
                   "OnTransFinished, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
                   m_uid);

        uint64_t newClientId = pPlayer->GetClientId();
        if (newClientId > 0 && m_clientId != newClientId)
        {
            //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
            //直接把旧的连接断开
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
            return 0;
        }

        NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
        if (pSession == NULL)
        {
            return 0;
        }

        if (pSession->IsDisconnect())
        {
            return 0;
        }

        proto_ff::ClientLoginRsp loginrsp;
        loginrsp.set_unix_sec(NFTime::Now().UnixSec());
        loginrsp.set_unix_msec(NFTime::Now().UnixMSec());
        loginrsp.set_time_zone(NFServerTime::Instance()->CurTimeZone());
        loginrsp.set_ret(iRunLogicRetCode);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_LOGIN_RSP, loginrsp);
    }

    return 0;
}

int NFTransWorldGetRoleList::OnTimeOut()
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1,
               "OnTransFinished, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
               m_uid);

    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
    return 0;
}