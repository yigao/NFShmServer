// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerModule.h"
#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "NFWorldAccount.h"
#include "NFWorldAccountMgr.h"
#include "NFLogicCommon/NFAccountDefine.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"


NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{

    ////////////////game room register//////////////////////////////
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCWorldPlayerModule::OnRpcServicePlayerLogin, true);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_CREATE_ROLE_REQ>(NF_ST_WORLD_SERVER, this,
                                                                              &NFCWorldPlayerModule::OnRpcServiceCreateRole, true);

    /////////////////////////////////server msg, player disconnect logout////////////////////////////////////////////

    //////////player enter game////////////////////////////////////


    return true;
}

int NFCWorldPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    return 0;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCWorldPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCWorldPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCWorldPlayerModule::OnRpcServicePlayerLogin(proto_ff::ClientLoginReq& request, proto_ff::ClientLoginRsp& respone, uint64_t proxyId, uint64_t clientId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    uint64_t uid = request.uid();
    uint32_t loginzid = request.zid();
    uint32_t chanid = request.channel_id();

    NFWorldAccount *pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    if (pAccountInfo == nullptr)
    {
        pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->CreateAccount(uid);
        if (pAccountInfo == NULL)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            NFLogError(NF_LOG_SYSTEMLOG, uid, "CreatePlayer Failed! the account full,  user id:{} Login Failed!", uid);
            return 0;
        }
    }

    uint64_t oldClientId = pAccountInfo->GetClientId();

    NFWorldSession *pOldSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(oldClientId);
    if (pOldSession != NULL)
    {
        if (oldClientId == clientId)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            return 0;
        }

        NFLogError(NF_LOG_SYSTEMLOG, uid, "same account login, tick old client, uid:{} cid:{} old proxy id:{} old client id:{}", pAccountInfo->GetUid(), pAccountInfo->GetCid(), pAccountInfo->GetProxyId(), pAccountInfo->GetClientId());

        int ret = NotifyGateLeave(pOldSession->GetProxyId(), pOldSession->GetClientId(), proto_ff::LOGOUT_REPLACE);
        //rpc check
        pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
        CHECK_NULL(pAccountInfo);
        if (ret != 0)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            return 0;
        }

        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pOldSession);

        //删除 uid和 clientid的映射
        pAccountInfo->SetProxyId(0);
        pAccountInfo->SetClientId(0);

        //handle the role
    }

    NFWorldSession* pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession == nullptr)
    {
        pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->CreateSession(clientId);
        if (pSession == nullptr)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSession failed, the link is full");
            return 0;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CreateSession Success, proxyId:{} clientId:{}", proxyId, clientId);
    }

    pSession->SetProxyId(proxyId);
    pSession->SetClientId(clientId);
    pSession->SetUid(uid);

    pAccountInfo->SetProxyId(proxyId);
    pAccountInfo->SetClientId(clientId);
    pAccountInfo->SetCid(0);
    pAccountInfo->SetIsDisconnect(false);
    pAccountInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);
    pAccountInfo->SetChanId(chanid);
    pAccountInfo->SetBornZid(loginzid);

    proto_ff::RoleDBData dbData;
    dbData.set_uid(uid);
    std::vector<proto_ff::RoleDBData> vecResult;
    std::vector<std::string> vecFields;
    vecFields.push_back("base");
    vecFields.push_back("cid");
    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectService(NF_ST_WORLD_SERVER, uid, dbData, vecResult, vecFields);
    pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    CHECK_NULL(pSession);
    pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    CHECK_NULL(pAccountInfo);
    if (iRet != 0)
    {
        respone.set_ret(proto_ff::RET_FAIL);
        return 0;
    }

    if (pAccountInfo->GetClientId() != clientId)
    {
        return 0;
    }

    respone.set_ret(proto_ff::RET_SUCCESS);
    respone.set_unix_sec(NFServerTime::Instance()->UnixSec());
    respone.set_unix_msec(NFServerTime::Instance()->UnixMSec());
    respone.set_time_zone(NFServerTime::Instance()->CurTimeZone());
    //先判断是否注册人数已满,新号，且注册人数已超，则不让进
/*    if (vecResult.size() <= 0)
    {
        respone.set_ret(proto_ff::RET_ACCOUNT_FULL);
    }*/

    for(int i = 0; i < (int)vecResult.size(); i++)
    {
        proto_ff::RoleDBBaseData* pDBProto = vecResult[i].mutable_base();
        for (uint32_t i = 0; i < (uint32_t)pDBProto->mutable_facade()->growfacade_size(); ++i)
        {
            proto_ff::Attr64* proto = pDBProto->mutable_facade()->mutable_growfacade(i);
            if (proto_ff::GrowType_DEITY_TYPE == proto->id())
            {
                proto->set_value(0);
            }
        }

        auto pRoleProto = respone.add_role_lst();
        if (nullptr != pRoleProto)
        {
            SetLoginRoleProto(*pRoleProto, vecResult[i].cid(), *pDBProto);
        }
    }

    pAccountInfo->SetRoleNum(vecResult.size());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::SetLoginRoleProto(::proto_ff::LoginRoleProto& outproto, uint64_t cid, const proto_ff::RoleDBBaseData& dbproto)
{
    outproto.set_cid(cid);
    outproto.set_name(dbproto.name());
    outproto.set_prof(dbproto.prof());
    outproto.set_level(dbproto.level());
    outproto.set_fight(dbproto.fight());
    outproto.set_createtime(dbproto.createtime());
    outproto.mutable_facade()->CopyFrom(dbproto.facade());
    return 0;
}

int NFCWorldPlayerModule::NotifyGateLeave(uint32_t proxyId, uint64_t clientId, proto_ff::LOGOUT_TYPE leaveFlag)
{
    proto_ff::NotifyGateLeaveGame2 notify;
    notify.set_clientid(clientId);
    notify.set_leave_flag(leaveFlag);
    proto_ff::EmptyMessage respone;
    return FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NOTIFY_GATE_LEAVE_GAME>(NF_ST_WORLD_SERVER, NF_ST_PROXY_SERVER, proxyId, notify, respone);
}

int NFCWorldPlayerModule::OnRpcServiceCreateRole(proto_ff::ClientCreateRoleReq& request, proto_ff::ClientCreateRoleRsp& respone, uint64_t uid, uint64_t param2)
{
    NFWorldAccount *pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    if (pAccountInfo == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "Can't find the world account:{}, create role faile!", uid);
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    if (pAccountInfo->GetRoleNum() >= MAX_ROLE_NUM)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "account:{} role num >= MAX_ROLE_NUM:{}, create role faile!", uid, MAX_ROLE_NUM);
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    int32_t name_len = (int32_t)request.name().length();
    if (name_len < proto_ff::CHARACTER_NAME_MIN_LENGTH || name_len >= proto_ff::CHARACTER_NAME_MAX_LENGTH)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "role name length error...uid:{},name_len:{}, create role failed!", uid, name_len);
        respone.set_result(proto_ff::RET_LOGIN_CHARACTER_NAME_LEN_ERROR);
        return 0;
    }

    NFServerConfig *pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pServerConfig);

    uint32_t zid = pServerConfig->GetZoneId();
    uint64_t newCid = FindModule<NFIKernelModule>()->Get64UUID();

    proto_ff::RoleDBData dbData;
    dbData.set_cid(newCid);
    dbData.set_uid(uid);
    dbData.set_zid(zid);

    //
    auto protobase = dbData.mutable_base();
    protobase->set_name(request.name());
    protobase->set_prof(request.prof());
    protobase->set_level(1);
    protobase->set_exp(0);
    protobase->set_hp(0);
    protobase->set_fight(0);
    protobase->set_vip_level(0);
    protobase->set_createtime(NFServerTime::Instance()->UnixSec());
    protobase->set_logintime(0);
    protobase->set_logouttime(0);

    protobase->mutable_facade()->set_color(request.color());
    protobase->mutable_facade()->set_prof(request.prof());

/*    protobase->set_enter_scene_id(pcfg->mapID);
    protobase->set_enter_map_id(pcfg->mapID);
    protobase->set_enterposx(pposcfg->x);
    protobase->set_enterposy(pposcfg->y);
    protobase->set_enterposz(pposcfg->z);

    protobase->set_lastsceneid(pcfg->mapID);
    protobase->set_lastmapid(pcfg->mapID);
    protobase->set_lastposx(pposcfg->x);
    protobase->set_lastposy(pposcfg->y);
    protobase->set_lastposz(pposcfg->z);*/

    int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_WORLD_SERVER, uid, dbData);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcInsertObjService Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    proto_ff::RoleDBData newDBData;
    newDBData.set_cid(newCid);
    iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_WORLD_SERVER, uid, newDBData);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcSelectObjService Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    CHECK_EXPR(newDBData.cid() == newCid, proto_ff::RET_FAIL, "GetRpcSelectObjService newDBData cid error");
    CHECK_EXPR(newDBData.uid() == uid, proto_ff::RET_FAIL, "GetRpcSelectObjService newDBData uid error");

    pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    CHECK_NULL(pAccountInfo);

    pAccountInfo->SetRoleNum(pAccountInfo->GetRoleNum()+1);
    pAccountInfo->SetCid(newCid);

    respone.set_result(proto_ff::RET_SUCCESS);
    SetLoginRoleProto(*respone.mutable_info(), newDBData);

    NFLogInfo(NF_LOG_SYSTEMLOG, uid, "account:{} create role:{} success", uid, newCid);

    return 0;
}

int NFCWorldPlayerModule::SetLoginRoleProto(proto_ff::LoginRoleProto& outproto, const proto_ff::RoleDBData& dbproto)
{
    outproto.set_cid(dbproto.cid());
    outproto.set_name(dbproto.base().name());
    outproto.set_prof(dbproto.base().prof());
    outproto.set_level(dbproto.base().level());
    outproto.set_fight(dbproto.base().fight());
    outproto.set_createtime(dbproto.base().createtime());
    *outproto.mutable_facade() = dbproto.base().facade();

    return 0;
}