// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetailModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFUserDetailModule.cpp
//
// -------------------------------------------------------------------------
#include "NFUserDetailModule.h"
#include "NFUserDetail/NFTransGetUserDetail.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFUserDetail/NFUserDetail.h"
#include "NFUserDetail/NFUserDetailMgr.h"
#include "NFUserDetail/NFTransGetEventLog.h"
#include "NFUserDetail/NFPlayerBindPhoneTrans.h"
#include "NFLogicCommon/NFICommLogicModule.h"


NFCUserDetailModule::NFCUserDetailModule(NFIPluginManager *p) : NFIUserDetailModule(p) {

}

NFCUserDetailModule::~NFCUserDetailModule() {

}

bool NFCUserDetailModule::Awake() {
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_WTL_PLAYER_LOGIN_REQ, this,
                                                       &NFCUserDetailModule::OnHandlePlayerLogin);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_WTL_PLAYER_RECONNECT_MSG, this,
                                                       &NFCUserDetailModule::OnHandlePlayerReconnect);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_WTL_PLAYER_DISCONNECT_MSG, this,
                                                       &NFCUserDetailModule::OnHandlePlayerDisConnect);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::E_CS_ERROR, this,
                                                       &NFCUserDetailModule::OnHandlePlayerError);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_login::NF_CS_MSG_ChangeFaceReq, this,
                                                       &NFCUserDetailModule::OnHandlePlayerChangeFace);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_WTL_REGISTER_USER_TO_LOGIC_REQ, this,
                                                       &NFCUserDetailModule::OnHandleRegisterUser);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY, this,
                                                 &NFCUserDetailModule::OnHandlePlayerChangeDevice);

	//sns server
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_STL_PLAYER_LOGIN_RSP, this,
		&NFCUserDetailModule::OnHandleSnsLoginRsp);

	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_STL_PLAYER_LOGOUT_RSP, this,
		&NFCUserDetailModule::OnHandleSnsLogoutRsp);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_UNICASTMSG_EVENTLOG_NOTIFY, this,
                                                       &NFCUserDetailModule::OnHandleEventLogNotify);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_login::NF_CS_MSG_PlayerPhoneAutoCodeReq, this,
                                                 &NFCUserDetailModule::OnHandlePlayerPhoneAutoCodeReq);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_login::NF_CS_MSG_PlayerCheckPhoneCodeReq, this,
                                                 &NFCUserDetailModule::OnHandlePlayerCheckPhoneCodeReq);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_login::NF_CS_MSG_BIND_PHONE_REQ, this,
                                                 &NFCUserDetailModule::OnHandlePlayerBindPhoneReq);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_login::NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_REQ, this,
                                                 &NFCUserDetailModule::OnHandlePlayerPhoneChangeBandPasswordReq);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIC_SERVER, proto_ff::NF_SNSTLOGIC_CHANGE_AGENT_NOTIFY, this,
                                                 &NFCUserDetailModule::OnHandlePlayerChangeAgentNotify);

    return true;
}

bool NFCUserDetailModule::Init() {
    SetTimer(1, 10000, 1);
    return true;
}

bool NFCUserDetailModule::Execute() {
    return true;
}

void NFCUserDetailModule::OnTimer(uint32_t nTimerID) {

}

int NFCUserDetailModule::OnHandlePlayerChangeDevice(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::LTLPlayerDeviceChangeNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFTransGetUserDetail* pTrans = dynamic_cast<NFTransGetUserDetail *>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_USER_DETAIL));
    CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");
    pTrans->Init(xMsg.user_id(), nMsgId);
    pTrans->HandleCSMsgReq(&xMsg);

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandleRegisterUser(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_WTLRegisterUserReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFTransGetUserDetail* pTrans = dynamic_cast<NFTransGetUserDetail *>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_USER_DETAIL));
    CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");
    pTrans->Init(xMsg.user_id(), nMsgId);
    pTrans->HandleCSMsgReq(&xMsg);

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg,
                                             uint32_t nLen) {

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_WorldToLogicLoginReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFTransGetUserDetail* pTrans = dynamic_cast<NFTransGetUserDetail *>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_USER_DETAIL));
    CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");
    pTrans->Init(xMsg.user_id(), nMsgId);
    pTrans->HandleCSMsgReq(&xMsg);

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg,
                                                 uint32_t nLen) {

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::WTLNotifyPlayerReconnectReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

	NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.player_id());
	if (pUserDetail) {
		pUserDetail->m_userData.game_id = xMsg.game_id();
		pUserDetail->m_userData.room_id = xMsg.room_id();
		pUserDetail->m_gameBusId = xMsg.game_bus_id();
		pUserDetail->m_proxyBusId = xMsg.proxy_bus_id();

        NFUserDetailMgr::GetInstance()->UserReconnect(pUserDetail);

        proto_ff::LTWNotifyPlayerReconnectRsp rspMsg;
        rspMsg.set_player_id(pUserDetail->GetUserId());
        rspMsg.set_result(0);
        FindModule<NFIMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_RECONNECT_MSG_RSP, rspMsg);
	}
	else
    {
        proto_ff::LTWNotifyPlayerReconnectRsp rspMsg;
        rspMsg.set_player_id(xMsg.player_id());
        rspMsg.set_result(-1);
        FindModule<NFIMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_RECONNECT_MSG_RSP, rspMsg);
    }

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg,
                                                  uint32_t nLen) {
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::NotifyPlayerDisconnect xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, xMsg.player_id(), "userid:{} disconnect..............", xMsg.player_id());

	NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.player_id());
	if (pUserDetail) {
        NFUserDetailMgr::GetInstance()->UserDisConnect(pUserDetail);
	}
	else
    {
        FindModule<NFIMessageModule>()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTS_PLAYER_DISCONNECT_MSG, xMsg);
    }

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerError(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_CSErrorRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.user_id());
    if (pUserDetail) {
        pUserDetail->SendMsgToClient(nMsgId, xMsg);
    }
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerChangeAgentNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_NotifyChangeAgent xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);
    uint32_t fromBusId = GetServerIndexFromUnlinkId(value);

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.user_id());
    if (pUserDetail) {
        pUserDetail->m_userData.agent_id = xMsg.agent_id();
        pUserDetail->MarkDirty();
        pUserDetail->SaveToDB(TRANS_SAVEROLEDETAIL_NORMAL, true);
    }
    else {
        NFTransGetUserDetail* pTrans = dynamic_cast<NFTransGetUserDetail *>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_USER_DETAIL));
        CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");
        pTrans->Init(xMsg.user_id(), nMsgId, fromBusId);
        pTrans->HandleCSMsgReq(&xMsg);
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandleSnsLoginRsp(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::Proto_SnsToLogicLoginRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);
	NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.player_id());
	CHECK_EXPR(pUserDetail, -1, "OnHandleSnsLoginRsp Error, User Data Not Exist:{}", xMsg.player_id());

	CHECK_EXPR(xMsg.result() == 0, -1, "Sns Server Login Failed, playerId:{}", xMsg.player_id());

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCUserDetailModule::OnHandleSnsLogoutRsp(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::Proto_SnsToLogicLogoutRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);
	CHECK_EXPR(xMsg.result() == 0, -1, "Sns Server Logout Failed, playerId:{}", xMsg.player_id());

	NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCUserDetailModule::OnHandlePlayerChangeFace(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CSChangeFaceReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(playerId);
    CHECK_EXPR(pUserDetail, -1, "OnHandlePlayerChangeFace Error, User Data Not Exist:{}", playerId);
    std::string newFaceId = NFCommon::tostr(xMsg.face_id());
    proto_login::Proto_SCChangeFaceRsp rspMsg;

    std::string init_jetton = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_JETTON);
    std::string init_face_vec = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_INIT_FACE);
    std::vector<std::string> vecFace;
    NFStringUtility::Split(init_face_vec, ",", &vecFace);

    bool find = false;
    for(int i = 0; i < (int)vecFace.size(); i++)
    {
        NFStringUtility::Trim(vecFace[i]);
        if (vecFace[i] == newFaceId)
        {
            find = true;
            break;
        }
    }

    if (find)
    {
        pUserDetail->SetFaceId(xMsg.face_id());
        pUserDetail->MarkDirty();
        rspMsg.set_result(0);
    }
    else
    {
        rspMsg.set_result(proto_ff::ERR_CODE_FACE_NOT_EXIST);
    }


    rspMsg.set_face_id(pUserDetail->GetFaceId());
    pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_ChangeFaceRsp, rspMsg);

    proto_ff::LTSnsChangeFaceNotify notify;
    notify.set_user_id(pUserDetail->GetUserId());
    notify.set_face_id(pUserDetail->GetFaceId());
    pUserDetail->SendMsgToSnsServer(proto_ff::NF_LTSns_CHANGE_FACE_NOTIFY, notify);
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandleEventLogNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::SSEventLogNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(xMsg.user_id());
    CHECK_EXPR(pUserDetail, -1, "OnHandleSnsLoginRsp Error, User Data Not Exist:{}", xMsg.user_id());

    NFTransGetEventLog* pTrans = (NFTransGetEventLog*)NFShmMgr::Instance()->CreateTrans(EOT_TRANS_GET_EVENT_LOG_ID);
    CHECK_EXPR(pTrans, -1, "Create Msg Trans Failed! UsedItem:{}", NFTransGetEventLog::GetUsedCount());

    pTrans->Init(pUserDetail, 0, 0);
    pTrans->GetEventLog(xMsg.user_id(), xMsg.eventlog_id());

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerPhoneAutoCodeReq(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_Player_PhoneAutoCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(playerId);
    CHECK_EXPR(pUserDetail, -1, "Proto_CS_Player_PhoneAutoCodeReq Error, User Data Not Exist:{}", playerId);

    NFPlayerBindPhoneTrans *pTrans = dynamic_cast<NFPlayerBindPhoneTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID));
    if (pTrans) {
        pTrans->Init(pUserDetail, nMsgId);
        pTrans->ProcessCSMsgReq(&xMsg);
    }
    else
    {
        proto_login::Proto_SC_Player_PhoneAutoCodeRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerPhoneAutoCodeRsp, rspMsg);
    }


    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerCheckPhoneCodeReq(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_Player_CheckPhoneCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(playerId);
    CHECK_EXPR(pUserDetail, -1, "Proto_CS_Player_CheckPhoneCodeReq Error, User Data Not Exist:{}", playerId);

    NFPlayerBindPhoneTrans *pTrans = dynamic_cast<NFPlayerBindPhoneTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID));
    if (pTrans) {
        pTrans->Init(pUserDetail, nMsgId);
        int iRet = pTrans->HandleGetBaseInfoMsgParam(&xMsg);
        if (iRet)
        {
            pTrans->SetFinished(iRet);
        }
    }
    else
    {
        proto_login::Proto_SC_Player_CheckPhoneCodeRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerCheckPhoneCodeRsp, rspMsg);
    }


    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerBindPhoneReq(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_Player_BindPhoneReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(playerId);
    CHECK_EXPR(pUserDetail, -1, "Proto_CS_Player_CheckPhoneCodeReq Error, User Data Not Exist:{}", playerId);

    NFPlayerBindPhoneTrans *pTrans = dynamic_cast<NFPlayerBindPhoneTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID));
    if (pTrans) {
        pTrans->Init(pUserDetail, nMsgId);
        int iRet = pTrans->HandleGetBaseInfoMsgParam(&xMsg);
        if (iRet)
        {
            pTrans->SetFinished(iRet);
        }
    }
    else
    {
        proto_login::Proto_SC_Player_BindPhoneRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_BIND_PHONE_RSP, rspMsg);
    }


    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCUserDetailModule::OnHandlePlayerPhoneChangeBandPasswordReq(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    proto_login::Proto_CS_PhoneChangeBandPasswordReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
    NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(playerId);
    CHECK_EXPR(pUserDetail, -1, "Proto_CS_Player_CheckPhoneCodeReq Error, User Data Not Exist:{}", playerId);

    if (xMsg.new_password().empty())
    {
        proto_login::Proto_SC_PhoneChangeBandPasswordRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_MSG_PARAM_ERROR);
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_RSP, rspMsg);
        return 0;
    }

    if (xMsg.new_password() == pUserDetail->GetData()->bank_password.GetString())
    {
        proto_login::Proto_SC_PhoneChangeBandPasswordRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_PASSWORD_NOT_CHANGE);
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_RSP, rspMsg);
        return 0;
    }

    if (pUserDetail->GetMiscData()->tmp_phone_num > 0
        && pUserDetail->GetMiscData()->tmp_phone_num == xMsg.phone_num()
        && pUserDetail->GetMiscData()->auth_code_stamp + 5*60 > (uint64_t)NFTime::Now().UnixSec()
        && pUserDetail->GetMiscData()->tmp_code_success)
    {
        pUserDetail->GetData()->bank_password = xMsg.new_password();
        pUserDetail->MarkDirty();

        proto_login::Proto_SC_PhoneChangeBandPasswordRsp rspMsg;
        rspMsg.set_result(0);
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_RSP, rspMsg);
    }
    else
    {
        proto_login::Proto_SC_PhoneChangeBandPasswordRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT);
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_RSP, rspMsg);
    }

    pUserDetail->ClearTmpPhoneData();
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}