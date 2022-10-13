// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include <ClientServerCmd.pb.h>
#include <Com.pb.h>
#include <ComDefine.pb.h>
#include <ClientServer.pb.h>
#include <ServerClient.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFCore/NFServerIDUtil.h>
#include <NFComm/NFCore/NFTime.h>
#include <NFLogicCommon/NFLogicCommon.h>
#include <NFComm/NFCore/NFCommon.h>
#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <ServerInternalCmd.pb.h>
#include <NFComm/NFCore/NFServerTime.h>
#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"
#include "NFWorldConfig.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, NF_MODULE_CLIENT, proto_ff::CLIENT_TO_CENTER_LOGIN, this,
                                                       &NFCWorldPlayerModule::OnHandleClientCenterLogin);
    //////////check proxy msg///////////////////////
    FindModule<NFIWorldServerModule>()->AddProxyMsgCheckCallBack(this, &NFCWorldPlayerModule::OnCheckWorldServerMsg);

    return true;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

/**
 * @brief 处理登录协议
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCWorldPlayerModule::OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginGateReq clogin;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, clogin);

    uint64_t clientId = packet.nParam1;
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    //验证版本号，如果版本号不对，不让进入
    CHECK_EXPR(clogin.version() == pConfig->ClientVersion, -1, "xMsg.version():{} != pConfig->ClientVersion:{}", clogin.version(),
               pConfig->ClientVersion);

    uint32_t uid = clogin.uid();

    uint32_t proxyId = (uint32_t) packet.nSrcId;

    /*
    因前端登录协议写入c#了，为了不重新出app包，前后端用  ClientLoginGateReq 协议中的 token字段格式为：MD5字符串|出生区服ID
    后面如果有校验 token的需要的话,可以通过分隔符来实现
    */
    const string &strParam = clogin.token();
    if (pExternalConfig->TokenTimeCheck)
    {
        uint64_t SecTime = NFTime::Now().UnixMSec();
        CHECK_EXPR((SecTime - clogin.logintimestamp()) <= MAX_CENTER_LOGIN_TIME_SEC, -1, "");
    }

    //
    std::vector<std::string> vecCheck;
    vecCheck.clear();
    NFStringUtility::Split(strParam, "|", &vecCheck);
    CHECK_EXPR(vecCheck.size() == 2, -1, "uid:{}, clientid:{}, paramsize:{}, param:{}", uid, clientId,
               (int32_t) vecCheck.size(),
               strParam.c_str());

    std::string &clientToken = vecCheck.at(0);
    int32_t bornZid = NFCommon::strto<int32_t>(vecCheck.at(1));

    //校验Token
    string srvToken = NFLogicCommon::MakeToken(uid, clogin.logintimestamp());
    CHECK_EXPR(srvToken == clientToken, -1, "srvToken:{} != clientToken:{}", srvToken, clientToken);

    //校验 bornZid
    CHECK_EXPR(bornZid > 0, -1, "bornZid <= 0...uid:{}, clientid:{}, param:{}", uid, clientId,
               strParam.c_str());

/*    if (!g_GetCenterService()->IsValidMergeZid(bornZid))
    {
        LogErrFmtPrint("[center] CenterAccountMgr::LoginGateReq...invalid mergezid...uid:%u,clientid:%u,param:%s", uid, clientId, strParam.c_str());
        goto Exit0;
    } */

    uint64_t tick = NFServerTime::Instance()->Tick();
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(uid);
    if (pPlayer == NULL)
    {
        pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(uid);
        CHECK_EXPR(pPlayer, -1, "NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(uid:{}) Failed", uid);
    }

    if (pPlayer->GetProxyId() > 0)
    {
        uint64_t oldClientId = pPlayer->GetClientId();
        uint32_t oldProxyId = pPlayer->GetProxyId();
        uint32_t oldStatus = pPlayer->GetStatus();

        if (oldProxyId == proxyId && oldClientId == clientId)
        {
            //如果是同一个连接在不断的请求发该协议 那么进行过滤
            if (clientId == oldClientId)
            {
                //NFLogError(NF_LOG_SYSTEMLOG, uid, "but same player send same cmd...clientid:{}, oldclientid:{}, uid:{}, cid:{}, logicid:{}, state:{}, bornZid:{}", clientId, oldClientId, pPlayer->GetPlayerId(), pPlayer->GetplayCid, oldUid->logicId, oldUid->state,oldUid->bronZid);
                return 0;
            }
        }

        //如果旧的游戏角色不处于断线状态 那么需要将旧角色的客户端session断开
        if (oldStatus != PLAYER_STATE_DISCONNECT)
        {
            //强制断开之前的客户端session
            int retCode = GateChangeLogic(pPlayer, proto_ff::NotifyGateChangeLogic_cType_LEAVE_LOGIC, 0, true, proto_ff::LOGOUT_FLAG_REPLACE);
            CHECK_EXPR(retCode != 0, -1, "GateChangeLogic Failed!");
        }

        //掉线重登或者被挤, 通知逻辑服退出
        //如果旧角色处于进入游戏 游戏中 切换场景中 断线中 四种状态那么需要通知旧角色从逻辑服退出 并且需要将oldUid作移除操作
        if (oldStatus == PLAYER_STATE_ENTER ||
            oldStatus == PLAYER_STATE_GAMING ||
            oldStatus == PLAYER_STATE_DISCONNECT ||
            oldStatus == PLAYER_STATE_LOGOUT ||
            oldStatus == PLAYER_STATE_SWITCH)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(),
                       "same account login,notify logic kick player logout.. uid:{}, kick_player_cid:{}, logic_id:{},  clientid:{}, oldclientid:{},state:{}, bornZid:{}",
                       pPlayer->GetPlayerId(), pPlayer->GetPlayCid(), pPlayer->GetLogicId(), clientId, oldClientId, pPlayer->GetStatus(), pPlayer->GetBornZid());

            NotifyLogicLeave(pPlayer, pPlayer->GetLogicId(), proto_ff::LOGOUT_TYPE_KICK_OUT);

            pPlayer->SetStatus(PLAYER_STATE_LOGOUT);
            //防止逻辑服没有回来中心服做账号回收
            pPlayer->SetStatusTimeStamp(tick);
            //将在离线的角色clientId放到离线列表中
            //m_logoutUidMap[uid] = oldUid->clientId;
        }
        else if (oldStatus == PLAYER_STATE_LOGIN
                 || oldStatus == PLAYER_STATE_LOADCHARLIS
                 || oldStatus == PLAYER_STATE_QUEUE)
        {
/*            //如果旧账号处于 登录或者向DB请求角色列表或者排队状态，直接删除m_cidMap中旧账号的记录
            m_clientIdMap.erase(oldUid->clientId);
            m_uidMap.erase(uid);
            //如果是排队状态，需要从排队列表移除
            if (oldUid->state == UID_STATE_QUEUE)
            {
                LoginQueue queueInfo;
                queueInfo.uid = uid;
                UID_QUEUE::iterator iterQueue = std::find(m_vUIDQueue.begin(), m_vUIDQueue.end(), queueInfo);
                if (iterQueue != m_vUIDQueue.end())
                {
                    m_vUIDQueue.erase(iterQueue);
                }
            }*/
        }
    }

    //以上情况都需要将m_uidMap先做下移除操作 最算之前没有旧的账号也可以先做下移除操作
    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->DeleteClientIdByPlayerId(uid);

    pPlayer->SetTokenTimeStamp(tick);
    pPlayer->SetStatus(PLAYER_STATE_LOGIN);
    pPlayer->SetToken(srvToken);
    pPlayer->SetPlayerId(clogin.uid());
    pPlayer->SetClientId(clientId);
    pPlayer->SetStatusTimeStamp(tick);
    pPlayer->SetLogicId(0);
    pPlayer->SetPlayCid(0);
    pPlayer->SetProxyId(proxyId);
    pPlayer->SetChannelId(clogin.channelid());
    pPlayer->SetBornZid(bornZid);

    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->InsertClientByPlayerId(uid, clientId);

    return 0;
}

/**
 * @brief 检查服务器消息，是否应该处理
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCWorldPlayerModule::OnCheckWorldServerMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }
    return 0;
}

/**
 * @brief 世界服通知网关改变逻辑服
 * @param pPlayer
 * @param ctype
 * @param logicId 逻辑服Id
 * @param force
 * @param flag
 * @return
 */
int NFCWorldPlayerModule::GateChangeLogic(NFWorldPlayer *pPlayer, proto_ff::NotifyGateChangeLogic_cType ctype, uint32_t logicId, bool force,
                                          proto_ff::LOGOUT_FLAG flag)
{
    CHECK_NULL(pPlayer);

    //已经通知过网关关闭连接了
    if (pPlayer->IsNotifyCloseProxy())
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(),
                     "notice gate change logic or disale..type={}, clientid={}, flag:{}, force:{}, uid:{}, state:{}, playercid:{}, old_logicid:{}, new_logicid:{}",
                     ctype, pPlayer->GetClientId(), flag, (int32_t) force, pPlayer->GetPlayerId(), pPlayer->GetStatus(), pPlayer->GetPlayCid(),
                     pPlayer->GetLogicId(), logicId);
        return 0;
    }

    //通知客户端强制断线
    //路由管理器移除对应的标识
    proto_ff::NotifyGateChangeLogic notify;
    notify.set_ctype(ctype);
    notify.set_clientid(pPlayer->GetClientId());
    notify.set_cid(pPlayer->GetPlayCid());
    notify.set_uid(pPlayer->GetPlayerId());

    if (force)
    {
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->EraseCid(pPlayer->GetPlayCid());
        pPlayer->SetIsNotifyCloseProxy(true);
        notify.set_forceleave(true);
        notify.set_leaveflag(flag);
    }

    if (logicId > 0)
        notify.set_logicid(logicId);

    NFLogTrace(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerId(),
               "notice gate change logic or disale..type={}, clientid={}, flag:{}, force:{}, uid:{}, state:{}, playercid:{}, old_logicid:{}, new_logicid:{}",
               ctype, pPlayer->GetClientId(), flag, (int32_t) force, pPlayer->GetPlayerId(), pPlayer->GetStatus(), pPlayer->GetPlayCid(),
               pPlayer->GetLogicId(), logicId);

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, pPlayer->GetProxyId(), proto_ff::WORLD_NOTIFY_PROXY_CHANGE_LOGIC,
                                                               notify, pPlayer->GetPlayerId());
    return 0;
}

/**
 * @brief
 * @param pPlayer
 * @param logicId
 * @param type
 * @return
 */
int NFCWorldPlayerModule::NotifyLogicLeave(NFWorldPlayer* pPlayer, uint32_t logicId, proto_ff::LOGOUT_TYPE type /*= proto_ff::LOGOUT_TYPE_NONE*/)
{
    CHECK_NULL(pPlayer);

    return 0;
}


