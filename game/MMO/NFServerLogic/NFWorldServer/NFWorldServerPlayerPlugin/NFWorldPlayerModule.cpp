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
#include "NFLogicCommon/NFSqlDefine.h"
#include "DescStoreEx/MapDescEx.h"
#include "NFWorldRole.h"
#include "NFWorldRoleMgr.h"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"


NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    FindModule<NFIWorldServerModule>()->SetCheckStoreServer(true);
    ////////////////game room register//////////////////////////////
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                              &NFCWorldPlayerModule::OnRpcServicePlayerLogin, true);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_CREATE_ROLE_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                    &NFCWorldPlayerModule::OnRpcServiceCreateRole, true);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_ENTER_GAME_RSP>(NF_ST_WORLD_SERVER, this,
                                                                                    &NFCWorldPlayerModule::OnRpcServiceEnterGame, true);

    /////////////////////////////////server msg, player disconnect logout////////////////////////////////////////////

    //////////player enter game////////////////////////////////////

    RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_DESC_STORE_LOAD, "WorldServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);
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

int NFCWorldPlayerModule::OnRpcServicePlayerLogin(proto_ff::ClientLoginReq &request, proto_ff::ClientLoginRsp &respone, uint64_t proxyId, uint64_t clientId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    uint64_t uid = request.uid();
    uint32_t loginzid = request.zid();
    uint32_t chanid = request.channel_id();

    respone.set_unix_sec(NFServerTime::Instance()->UnixSec());
    respone.set_unix_msec(NFServerTime::Instance()->UnixMSec());
    respone.set_time_zone(NFServerTime::Instance()->CurTimeZone());

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

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
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
    std::vector<proto_ff::RoleDBData> vecResult;
    std::vector<std::string> vecFields;
    vecFields.push_back("base");
    vecFields.push_back("cid");
    vecFields.push_back("uid");
    vecFields.push_back("zid");

    std::vector<storesvr_sqldata::storesvr_vk> vk_list;
    storesvr_sqldata::storesvr_vk vk_uid;
    vk_uid.set_column_name("uid");
    vk_uid.set_column_value(NFCommon::tostr(uid));
    vk_uid.set_cmp_operator(storesvr_sqldata::storesvr_cmp_operator::E_CMPOP_EQUAL);
    vk_uid.set_logic_operator(storesvr_sqldata::storesvr_logic_operator::E_LOGICOP_AND);
    vk_list.push_back(vk_uid);

    storesvr_sqldata::storesvr_vk vk_zid;
    vk_zid.set_column_name("zid");
    vk_zid.set_column_value(NFCommon::tostr(loginzid));
    vk_zid.set_cmp_operator(storesvr_sqldata::storesvr_cmp_operator::E_CMPOP_EQUAL);
    vk_zid.set_logic_operator(storesvr_sqldata::storesvr_logic_operator::E_LOGICOP_NONE);
    vk_list.push_back(vk_zid);

    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectService(NF_ST_WORLD_SERVER, uid, dbData, vecResult, vecFields, vk_list);
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

    //先判断是否注册人数已满,新号，且注册人数已超，则不让进
/*    if (vecResult.size() <= 0)
    {
        respone.set_ret(proto_ff::RET_ACCOUNT_FULL);
    }*/

    for (int i = 0; i < (int) vecResult.size(); i++)
    {
        proto_ff::RoleDBBaseData *pDBProto = vecResult[i].mutable_base();
        for (uint32_t i = 0; i < (uint32_t) pDBProto->mutable_facade()->growfacade_size(); ++i)
        {
            proto_ff::Attr64 *proto = pDBProto->mutable_facade()->mutable_growfacade(i);
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

        if (pAccountInfo->GetRoleNum() < MAX_ROLE_NUM)
        {
            pAccountInfo->AddRoleNum(vecResult[i].cid());
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::SetLoginRoleProto(::proto_ff::LoginRoleProto &outproto, uint64_t cid, const proto_ff::RoleDBBaseData &dbproto)
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

int NFCWorldPlayerModule::OnRpcServiceCreateRole(proto_ff::ClientCreateRoleReq &request, proto_ff::ClientCreateRoleRsp &respone, uint64_t uid, uint64_t param2)
{
    CHECK_EXPR(uid > 0, -1, "uid:{}", uid);
    NFWorldAccount *pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    if (pAccountInfo == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "Can't find the world account:{}, create role faile!", uid);
        respone.set_result(proto_ff::RET_LOGIN_CHARACTER_NOT_ACCOUNT);
        return 0;
    }

    if (pAccountInfo->GetRoleNum() >= MAX_ROLE_NUM)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "account:{} role num >= MAX_ROLE_NUM:{}, create role faile!", uid, MAX_ROLE_NUM);
        respone.set_result(proto_ff::RET_LOGIN_CHARACTER_NUM_LIMIT);
        return 0;
    }

    int32_t name_len = (int32_t) request.name().length();
    if (name_len < proto_ff::CHARACTER_NAME_MIN_LENGTH || name_len >= proto_ff::CHARACTER_NAME_MAX_LENGTH)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "role name length error...uid:{},name_len:{}, create role failed!", uid, name_len);
        respone.set_result(proto_ff::RET_LOGIN_CHARACTER_NAME_LEN_ERROR);
        return 0;
    }

    auto pBornCfg = MapDescEx::Instance()->GetBornCfg(request.prof());
    if (nullptr == pBornCfg)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "can't find the prof's born cfg...uid:{},prof:{}, create role failed!", uid, request.prof());
        respone.set_result(proto_ff::RET_CONFIG_ERROR);
        return 0;
    }

    const NFPoint3<float> *pBornPos = MapDescEx::Instance()->RandBornPoint(pBornCfg->m_mapID);
    if (nullptr == pBornPos)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "can't find the prof's born map:{} cfg...uid:{},prof:{}, create role failed!", pBornCfg->m_mapID, uid, request.prof());
        respone.set_result(proto_ff::RET_CONFIG_ERROR);
        return 0;
    }

    NFServerConfig *pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pServerConfig);

    uint32_t zid = pServerConfig->GetZoneId();
    uint64_t newCid = FindModule<NFIKernelModule>()->Get53UUID();

    proto_ff::RoleDBData dbData;
    dbData.set_cid(newCid);
    dbData.set_uid(uid);
    dbData.set_zid(zid);

    //
    auto protobase = dbData.mutable_base();
    protobase->set_name(request.name());
    protobase->set_prof(request.prof());
    protobase->set_level(pBornCfg->m_bornLevel);
    protobase->set_exp(0);
    protobase->set_hp(0);
    protobase->set_fight(0);
    protobase->set_vip_level(0);
    protobase->set_createtime(NFServerTime::Instance()->UnixSec());
    protobase->set_logintime(0);
    protobase->set_logouttime(0);

    protobase->mutable_facade()->set_color(request.color());
    protobase->mutable_facade()->set_prof(request.prof());

    protobase->set_enter_scene_id(pBornCfg->m_mapID);
    protobase->set_enter_map_id(pBornCfg->m_mapID);
    protobase->set_enterposx(pBornPos->x);
    protobase->set_enterposy(pBornPos->y);
    protobase->set_enterposz(pBornPos->z);

    protobase->set_lastsceneid(pBornCfg->m_mapID);
    protobase->set_lastmapid(pBornCfg->m_mapID);
    protobase->set_lastposx(pBornPos->x);
    protobase->set_lastposy(pBornPos->x);
    protobase->set_lastposz(pBornPos->x);

    proto_ff::RoleDBName dbName;
    dbName.set_name(request.name());

    int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_WORLD_SERVER, DB_NAME_MOD, dbName);
    if (iRet == proto_ff::RET_SUCCESS)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} name:{} exist, create role failed!", uid, request.name());
        respone.set_result(proto_ff::RET_LOGIN_CHARACTER_NAME_EXISTS);
        return 0;
    }
    else if (iRet != proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "GetRpcSelectObjService RoleDBName failed, uid:{} name:{}, create role failed!", uid, request.name());
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }
    else
    {
        iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_WORLD_SERVER, DB_NAME_MOD, dbName);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, uid, "GetRpcInsertObjService RoleDBName failed, uid:{} name:{}, create role failed!", uid, request.name());
            respone.set_result(proto_ff::RET_FAIL);
            return 0;
        }
    }

    iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_WORLD_SERVER, uid, dbData);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcInsertObjService RoleDBData Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    proto_ff::RoleDBData newDBData;
    newDBData.set_cid(newCid);
    iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_WORLD_SERVER, uid, newDBData);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcSelectObjService RoleDBData Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    CHECK_EXPR(newDBData.cid() == newCid, proto_ff::RET_FAIL, "GetRpcSelectObjService newDBData cid error");
    CHECK_EXPR(newDBData.uid() == uid, proto_ff::RET_FAIL, "GetRpcSelectObjService newDBData uid error");

    proto_ff::RoleDBSnsDetail snsDetail;
    snsDetail.set_cid(newCid);
    iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_WORLD_SERVER, uid, snsDetail);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcInsertObjService RoleDBSnsDetail Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    proto_ff::RoleDBData newSnsDetail;
    newSnsDetail.set_cid(newCid);
    iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_WORLD_SERVER, uid, newSnsDetail);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} GetRpcSelectObjService RoleDBSnsDetail Failed, iRet:{}, create role failed!", uid, GetErrorStr(iRet));
        respone.set_result(proto_ff::RET_FAIL);
        return 0;
    }

    /**
     * @brief 异步之后，重新获取指针
     */
    pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    CHECK_NULL(pAccountInfo);

    pAccountInfo->AddRoleNum(newCid);

    respone.set_result(proto_ff::RET_SUCCESS);
    SetLoginRoleProto(*respone.mutable_info(), newDBData);

    NFLogInfo(NF_LOG_SYSTEMLOG, uid, "account:{} create role:{} success", uid, newCid);

    return 0;
}

int NFCWorldPlayerModule::SetLoginRoleProto(proto_ff::LoginRoleProto &outproto, const proto_ff::RoleDBData &dbproto)
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

int NFCWorldPlayerModule::OnRpcServiceEnterGame(proto_ff::ClientEnterGameReq& request, proto_ff::ClientEnterGameInternalRsp& respone, uint64_t uid, uint64_t param2)
{
    uint64_t cid = request.cid();
    NFWorldAccount *pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    if (pAccountInfo == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "Can't find the world account:{}, role:{} enter game faile!", uid, cid);
        respone.set_ret_code(proto_ff::RET_LOGIN_CHARACTER_NOT_ACCOUNT);
        return 0;
    }

    if (!pAccountInfo->IsExistCid(cid))
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "account:{} has not role:{}, enter game faile!", uid, cid);
        respone.set_ret_code(proto_ff::RET_LOGIN_CHARACTER_NUM_LIMIT);
        return 0;
    }

    NFWorldRole* pRole = NFWorldRoleMgr::Instance(m_pObjPluginManager)->GetRole(cid);
    if (pRole == NULL)
    {
        pRole = NFWorldRoleMgr::Instance(m_pObjPluginManager)->CreateRole(cid);
        if (pRole == NULL)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} role:{}, then role num than the max num, enter game faile!", uid, cid);
            respone.set_ret_code(proto_ff::RET_LOGIN_CHARACTER_NUM_LIMIT);
            return 0;
        }
        pRole->SetUid(uid);
    }

    if (pRole->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, cid);
        if (pLogicServer == NULL)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} role:{}, can't find the logic server, enter game faile!", uid, cid);
            respone.set_ret_code(proto_ff::RET_FAIL);
            return 0;
        }

        pRole->SetLogicId(pLogicServer->mServerInfo.bus_id());
    }
    
    /**
     * 客户端需要，特殊处理
     */
    proto_ff::ClientEnterGameRsp rspMsg;
    rspMsg.set_ret(proto_ff::RET_SUCCESS);
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pAccountInfo->GetProxyId(), proto_ff::CLIENT_ENTER_GAME_RSP, rspMsg, uid);
    
    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pServerConfig);
    
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::CLIENT_ENTER_GAME_RSP>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pRole->GetLogicId(), request, respone, pServerConfig->GetBusId(), pAccountInfo->GetProxyId());
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "uid:{} role:{}, GetRpcService<proto_ff::CLIENT_ENTER_GAME_REQ> err:{} , enter game faile!", uid, cid, GetErrorStr(iRet));
        respone.set_ret_code(proto_ff::RET_FAIL);
        return 0;
    }

    /**
     * @brief 异步后，重新获取指针
     */
    pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    CHECK_NULL(pAccountInfo);
    pRole = NFWorldRoleMgr::Instance(m_pObjPluginManager)->GetRole(cid);
    CHECK_NULL(pRole);
    
    if (respone.ret_code() == proto_ff::RET_SUCCESS)
    {
        pRole->SetGameId(respone.game_id());
        pRole->SetSnsId(respone.sns_id());
        pRole->SetLogicId(respone.logic_id());
        pRole->SetIsDisconnect(false);
        pRole->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);
        NFLogError(NF_LOG_SYSTEMLOG, cid, "Player Enter Game Success, uid:{} cid:{}", uid, cid);
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "Player Enter Game Failed, uid:{} cid:{}", uid, cid);
    }
    
    return 0;
}