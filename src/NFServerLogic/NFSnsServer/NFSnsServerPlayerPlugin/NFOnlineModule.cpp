// -------------------------------------------------------------------------
//    @FileName         :    NFCOnlineModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCOnlineModule
//
// -------------------------------------------------------------------------

#include "NFOnlineModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"

#include "NFUserSimple/NFSnsUserSimpleUtil.h"
#include "NFUserSimple/NFSnsUserSimple.h"
#include "NFOnlineUser/NFOnlineUserMgr.h"
#include "NFOnlineUser/NFOnlineUser.h"
#include "NFOnlineUser/NFTransSnsUserOnline.h"
#include "NFUserSimple/NFSnsUserSimpleMgr.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"


NFCOnlineModule::NFCOnlineModule(NFIPluginManager* p) :NFIDynamicModule(p)
{
}

NFCOnlineModule::~NFCOnlineModule()
{
}

bool NFCOnlineModule::Awake()
{
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_PLAYER_LOGIN_REQ, this, &NFCOnlineModule::OnHandlePlayerLogin);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_PLAYER_LOGOUT_REQ, this, &NFCOnlineModule::OnHandlePlayerLogout);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_PLAYER_DISCONNECT_MSG, this, &NFCOnlineModule::OnHandlePlayerDisConnect);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_PLAYER_RECONNECT_MSG, this, &NFCOnlineModule::OnHandlePlayerReconnect);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_QUERY_USER_REQ, this, &NFCOnlineModule::OnHandleQueryUser);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_SNS_ROUTER_CMD_TO_SUIT_LOGIC, this, &NFCOnlineModule::OnHandleRouteToSuitLogicServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTSns_CHANGE_FACE_NOTIFY, this, &NFCOnlineModule::OnHandleChangeFace);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTSns_CHANGE_NICKNAME_NOTIFY, this, &NFCOnlineModule::OnHandleChangeNickName);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTS_PLAYER_VIPLVEL_CHANGE_NOTIFY, this, &NFCOnlineModule::OnHandleChangeVipLevel);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_LTSns_CHANGE_USERID_NOTIFY, this,
                                                 &NFCOnlineModule::OnHandleChangeUserId);


    Subscribe(proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

bool NFCOnlineModule::Init()
{
	return true;
}

bool NFCOnlineModule::Execute()
{
	return true;
}

bool NFCOnlineModule::OnDynamicPlugin()
{
	return true;
}

int NFCOnlineModule::OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTSNotifyPlayerReconnectReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFTransSnsUserOnline* pTrans = (NFTransSnsUserOnline*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_USER_ONLINE);
    CHECK_NULL(pTrans);
    pTrans->UserReconnect(xMsg);
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::Proto_LogicToSnsLoginReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFTransSnsUserOnline* pTrans = (NFTransSnsUserOnline*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_USER_ONLINE);
    CHECK_NULL(pTrans);
    pTrans->UserLogin(xMsg);

	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCOnlineModule::OnPlayerLogin(NFSnsUserSimple* pSimple, NFOnlineUser* pUser)
{
    return 0;
}

int NFCOnlineModule::OnNewPlayer(NFSnsUserSimple* pSimple, NFOnlineUser* pUser)
{
    return 0;
}

int NFCOnlineModule::OnPlayerLogout(NFSnsUserSimple* pSimple, NFOnlineUser* pUser)
{
    return 0;
}

int NFCOnlineModule::OnHandlePlayerLogout(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::Proto_LogicToSnsLogoutReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

	proto_ff::Proto_SnsToLogicLogoutRsp rspMsg;
	rspMsg.set_result(0);
	rspMsg.set_player_id(xMsg.player_id());
	NFSnsUserSimple* pUser = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(xMsg.player_id(), false);
	CHECK_NULL(pUser);

	pUser->UserLogout();
	pUser->SaveToDB(false);

	NFOnlineUser* pOnline = NFOnlineUserMgr::GetInstance()->Find(xMsg.player_id());
	if (pOnline)
	{
        OnPlayerLogout(pUser, pOnline);

        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, pOnline->GetLogicId(), proto_ff::NF_STL_PLAYER_LOGOUT_RSP, rspMsg);

		NFOnlineUserMgr::GetInstance()->Delete(xMsg.player_id());
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCOnlineModule::OnHandleChangeFace(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTSnsChangeFaceNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

    NFOnlineUser* pOnline = NFOnlineUserMgr::GetInstance()->Find(xMsg.user_id());
    CHECK_NULL(pOnline);

    NFSnsUserSimple* pUser = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(xMsg.user_id(), false);
    CHECK_NULL(pUser);

    pUser->GetSimpleData()->face = xMsg.face_id();
    pUser->MarkDirty();

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleChangeVipLevel(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTSnsChangeVipLevelNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

    NFTransSnsUserOnline* pTrans = (NFTransSnsUserOnline*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_USER_ONLINE);
    CHECK_NULL(pTrans);
    pTrans->UserModifyVipLevel(xMsg);

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleChangeNickName(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTSnsChangeNickNameNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

    NFTransSnsUserOnline* pTrans = (NFTransSnsUserOnline*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_USER_ONLINE);
    CHECK_NULL(pTrans);
    pTrans->UserModifyName(xMsg);

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleChangeUserId(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTSnsChangeUserIdNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

    NFTransSnsUserOnline* pTrans = (NFTransSnsUserOnline*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_USER_ONLINE);
    CHECK_NULL(pTrans);
    pTrans->UserModifyUserId(xMsg);

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleQueryUser(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_LTSQueryUserReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

    tagQueryRole query;
    query.Reset();
    for(int i = 0; i < (int)xMsg.query_user_id_size(); i++)
    {
        query.Add(xMsg.query_user_id(i));
    }
    query.userId = xMsg.user_id();

    NFTransSnsBase* pTrans = (NFTransSnsBase*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_SNS_BASE);
    CHECK_EXPR(pTrans, -1, "Create Msg Trans Failed! UsedItem:{}", NFTransSnsBase::GetUsedCount());
    pTrans->Init(req_trans_id);
    pTrans->SetNotify();
    int iRetCode = pTrans->QueryRole(query);
    if (iRetCode)
    {
        pTrans->SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFCOnlineModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE)
        {
        }
        else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            NFSnsUserSimpleMgr::Instance()->Init();
        }
    }
    return 0;
}

int NFCOnlineModule::OnHandleRouteToSuitLogicServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFOnlineUser* pUser = NFOnlineUserMgr::GetInstance()->Find(xMsg.mutable_disp_info()->user_id());
    if (pUser)
    {
        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, pUser->GetLogicId(), xMsg.msg_id(), xMsg.msg_data().data(), xMsg.msg_data().length());
    }

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}