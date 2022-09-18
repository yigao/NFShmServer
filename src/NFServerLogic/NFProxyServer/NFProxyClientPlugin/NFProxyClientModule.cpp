// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include "NFProxyClientModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFServer/NFCommHead/NFIProxyServerModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"

NFCProxyClientModule::NFCProxyClientModule(NFIPluginManager* p):NFIProxyClientModule(p)
{
	m_proxyClientLinkId = 0;
}

NFCProxyClientModule::~NFCProxyClientModule()
{
}

bool NFCProxyClientModule::Awake()
{
    //////来自客户端的协议////////////////////////////////////////
    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig) {
        if (!m_pPluginManager->IsLoadAllServer()) {
            if (pConfig->mServerType != NF_ST_PROXY_SERVER) {
                NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->mExternalServerIp, pConfig->mExternalServerPort);
        int64_t extern_unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_PROXY_SERVER_FOR_CLIENT, externUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum,
                                                                             pConfig->mParseType, pConfig->mSecurity);
        if (extern_unlinkId >= 0) {
            /*
            注册服务器事件
            */
            m_proxyClientLinkId = (uint64_t) extern_unlinkId;
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnProxyClientSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER_FOR_CLIENT, m_proxyClientLinkId, this,
                                                             &NFCProxyClientModule::OnHandleProxyClientOtherMessage);
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mExternalServerIp, pConfig->mExternalServerPort);
        } else {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy client listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mExternalServerIp, pConfig->mExternalServerPort);
            return false;
        }
    }
	else
	{
		NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "I Can't get the Proxy Server config!");
		return false;
	}

	return true;
}

bool NFCProxyClientModule::Init()
{
    SetTimer(1, 1000);
	return true;
}

bool NFCProxyClientModule::Execute()
{
	return true;
}

bool NFCProxyClientModule::OnDynamicPlugin()
{
	FindModule<NFIMessageModule>()->CloseLinkId(m_proxyClientLinkId);
	return true;
}

void NFCProxyClientModule::OnTimer(uint32_t nTimerID)
{
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig, , "");

    std::vector<uint64_t> vec;
    auto pPlayerInfo = mPlayerLinkInfo.First();
    while(pPlayerInfo)
    {
         if (pPlayerInfo->mOnline == false) {
             if (NFTime::Now().UnixSec() - pPlayerInfo->mDisconnectTime >= PLAYER_MAX_DISCONNECT_EXIST_TIME) {
                 vec.push_back(pPlayerInfo->mPlayerId);
             }

             if (pPlayerInfo->mIsLogin)
             {
                 if (NFTime::Now().UnixSec() - pPlayerInfo->mDisconnectTime >= PLAYER_MAX_DISCONNECT_RECONNECT_TIME)
                 {
                     pPlayerInfo->mIsLogin = false;
                     NFLogError(NF_LOG_SYSTEMLOG, 0, "player disconnect 60s, islogin = false:{}", pPlayerInfo->mPlayerId);
                 }
             }
         }
        pPlayerInfo = mPlayerLinkInfo.Next();
    }

    for(int i = 0; i < (int)vec.size(); i++)
    {
        mPlayerLinkInfo.RemoveElement(vec[i]);
    }

    auto pClientLinkInfo = mClientLinkInfo.First();
    while(pClientLinkInfo)
    {
        if (pClientLinkInfo->mPlayerId <= 0 && pClientLinkInfo->mLastHeartBeatTime > 0 && NFTime::Now().UnixSec() - pClientLinkInfo->mLastHeartBeatTime >= pConfig->mHeartBeatTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check heart beat timeout........., disconnect link:{}", pClientLinkInfo->mLinkId);
            FindModule<NFIMessageModule>()->CloseLinkId(pClientLinkInfo->mLinkId);
        }

        if (pClientLinkInfo->mPlayerId > 0 && pClientLinkInfo->mLastHeartBeatTime > 0 && NFTime::Now().UnixSec() - pClientLinkInfo->mLastHeartBeatTime >= pConfig->mClientKeepAliveTimeout)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "check playerId keep alive timeout........., disconnect link:{}", pClientLinkInfo->mLinkId);
            FindModule<NFIMessageModule>()->CloseLinkId(pClientLinkInfo->mLinkId);
        }

        pClientLinkInfo = mClientLinkInfo.Next();
    }
}

/*
	处理客户端链接事件
*/
int NFCProxyClientModule::OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} linkId:{} connected proxy server success!", ip, unLinkId);

        NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
        if (pLinkInfo == nullptr)
        {
            pLinkInfo = NF_SHARE_PTR<NFProxySession>(NF_NEW NFProxySession());
            pLinkInfo->mLinkId = unLinkId;
            pLinkInfo->mIPAddr = ip;
            mClientLinkInfo.AddElement(unLinkId, pLinkInfo);
        }
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "client ip:{} link:{} disconnected proxy server!", ip, unLinkId);
		OnHandleClientDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理客户端未注册协议
*/
int NFCProxyClientModule::OnHandleProxyClientOtherMessage(uint64_t unLinkId, const NFDataPackage& packet) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");

    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);

    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo == nullptr) {
        proto_login::Proto_SCKetPlayerNotify kitMsg;
        kitMsg.set_result(0);
        FindModule<NFIMessageModule>()->Send(unLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "can't find the link, ip:{} packet:{}",
                     ip, packet.ToString());

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
        return 0;
    }

    NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->mPlayerId);
    if (pPlayerInfo == nullptr) {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "can't find the player:{} info, ip:{} packet:{}", pLinkInfo->mPlayerId, ip, packet.ToString());

        return 0;
    }

    if (!pPlayerInfo->mIsLogin) {
        NFLogWarning(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "ip:{} not login,send packet:{}, the msg will not send",
                     ip, packet.ToString());

        return 0;
    }

    if (pPlayerInfo->mLogicBusId > 0) {
        NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->mPlayerId, "recv packet = {}, transfer to logic server", packet.ToString());
        //FindModule<NFIMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mLogicBusId, nMsgId, msg, nLen,
        //                                         pPlayerInfo->mPlayerId);
    }
    else
    {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, pPlayerInfo->mPlayerId, "recv nMsgId = {}, not transfer to logic server", packet.ToString());
        proto_login::Proto_SCKetPlayerNotify kitMsg;
        kitMsg.set_result(0);
        FindModule<NFIMessageModule>()->Send(pPlayerInfo->mLinkId, proto_login::NF_SC_Msg_KitPlayer_Notify, kitMsg);

        FindModule<NFIMessageModule>()->CloseLinkId(unLinkId);
    }

    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyClientModule::OnHandleClientDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFProxySession> pLinkInfo = mClientLinkInfo.GetElement(unLinkId);
    if (pLinkInfo) {
        if (pLinkInfo->mPlayerId > 0) {
            NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(pLinkInfo->mPlayerId);
            if (pPlayerInfo) {
                pPlayerInfo->mLinkId = 0;
                pPlayerInfo->mGameId = 0;
                pPlayerInfo->mRoomId = 0;
                pPlayerInfo->mGameBusId = 0;
                pPlayerInfo->mLogicBusId = 0;
                pPlayerInfo->mOnline = false;
                pPlayerInfo->mDisconnectTime = NFTime::Now().UnixSec();

                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} link:{} disconenct.........", pLinkInfo->mPlayerId, unLinkId);

                proto_ff::NotifyPlayerDisconnect xMsg;
                xMsg.set_player_id(pPlayerInfo->mPlayerId);

                if (pPlayerInfo->mWorldBusId > 0) {
                    FindModule<NFIMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, pPlayerInfo->mWorldBusId,
                                                                   proto_ff::NF_PTW_PLAYER_DISCONNECT_MSG,
                                                                   xMsg, pLinkInfo->mPlayerId);
                }
            }
		}
		mClientLinkInfo.RemoveElement(unLinkId);
	}

	NFLogTrace(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyClientModule::OnHandleOtherServerOtherMessage(uint64_t unLinkId, const NFDataPackage& packet)
{
    /*
    auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, busId);
    if (pServerData)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, playerId, "proxy trans other server:{} msg:{} to client", pServerData->mServerInfo.server_name(), nMsgId);
        NF_SHARE_PTR<NFProxyPlayerInfo> pPlayerInfo = mPlayerLinkInfo.GetElement(playerId);
        if (pPlayerInfo)
        {
            FindModule<NFIMessageModule>()->Send(pPlayerInfo->mLinkId, nMsgId, msg, nLen, 0);
        }
        else
        {
            NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "other server msg:{} not handle", nMsgId);
        }
    }
    */

	return 0;
}