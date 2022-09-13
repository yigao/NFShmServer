// -------------------------------------------------------------------------
//    @FileName         :    NFAccountLoginModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFAccountLoginModule
//
// -------------------------------------------------------------------------

#include "NFAccountLoginModule.h"

#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFAccountLoginMgr.h"
#include "NFGetAccountTrans.h"
#include "NFRegisterAccountTrans.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFIMysqlModule.h"
#include "NFServerIpMgr.h"
#include "NFBindPhoneTrans.h"
#include "NFPhoneAutoCodeMgr.h"


NFCAccountLoginModule::NFCAccountLoginModule(NFIPluginManager *p) : NFIAccountLoginModule(p) {
}

NFCAccountLoginModule::~NFCAccountLoginModule() {
}

bool NFCAccountLoginModule::Awake()
{
	///////////////////////////客户端协议//////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_login::NF_CS_MSG_AccountLoginReq, this, &NFCAccountLoginModule::OnHandleAccountLoginFromClient);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_login::NF_CS_MSG_RegisterAccountReq, this, &NFCAccountLoginModule::OnHandleAccountRegisterFromClient);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_ff::NF_WTL_LOAD_SERVER_TO_LOGIN_RSP, this, &NFCAccountLoginModule::OnHandleLoadServerFromWorldServer);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq, this,
                                                       &NFCAccountLoginModule::OnHandlePhoneAutoCodeFromClient);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_login::NF_CS_MSG_LoginServer_CheckPhoneCodeReq, this,
                                                       &NFCAccountLoginModule::OnHandleCheckPhoneCodeFromClient);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ, this,
                                                       &NFCAccountLoginModule::OnHandleChangePasswordFromClient);

	return true;
}

bool NFCAccountLoginModule::Execute() {
    return true;
}

bool NFCAccountLoginModule::OnDynamicPlugin()
{
	return true;
}

void NFCAccountLoginModule::OnTimer(uint32_t nTimerID)
{

}

int NFCAccountLoginModule::OnHandleLoadServerFromWorldServer(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, value, msg, nLen, xMsg);

    for(int i = 0; i < (int)xMsg.server_list_size(); i++)
    {
        NFServerIpMgr::Instance()->AddServer(xMsg.server_list(i));
    }
    return 0;
}

int NFCAccountLoginModule::OnHandleCheckPhoneCodeFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t proxyBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_login::Proto_CS_LoginServer_CheckPhoneCodeReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, clientLinkId, msg, nLen, cgMsg);

    NFBindPhoneTrans *pTrans = dynamic_cast<NFBindPhoneTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_REGISTER_ACCOUNT_BIND_PHONE));
    if (pTrans) {
        pTrans->Init(proxyBusId, clientLinkId, nMsgId);
        int iRet = pTrans->HandleGetBaseInfoMsgParam(&cgMsg);
        if (iRet)
        {
            pTrans->SetFinished(iRet);
        }
    }
    else
    {
        proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, proxyBusId,
                                                       proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp,
                                                       rspMsg,
                                                       clientLinkId);
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAccountLoginModule::OnHandlePhoneAutoCodeFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t proxyBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_login::Proto_CS_LoginServer_PhoneAutoCodeReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, clientLinkId, msg, nLen, cgMsg);

    NFBindPhoneTrans *pTrans = dynamic_cast<NFBindPhoneTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_REGISTER_ACCOUNT_BIND_PHONE));
    if (pTrans) {
        pTrans->Init(proxyBusId, clientLinkId, nMsgId);
        pTrans->ProcessCSMsgReq(&cgMsg);
    }
    else
    {
        proto_login::Proto_SC_LoginServer_PhoneAutoCodeRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, proxyBusId,
                                                       proto_login::NF_SC_MSG_LoginServer_PhoneAutoCodeRsp,
                                                       rspMsg,
                                                       clientLinkId);
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAccountLoginModule::OnHandleAccountRegisterFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t proxyBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_login::Proto_CSRegisterAccountReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, clientLinkId, msg, nLen, cgMsg);

    NFRegisterAccountTrans *pTrans = dynamic_cast<NFRegisterAccountTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_REGISTER_ACCOUNT));
    if (pTrans) {
        pTrans->Init(proxyBusId, clientLinkId, nMsgId);
        pTrans->ProcessCSMsgReq(&cgMsg);
    }
    else
    {
        proto_login::Proto_SCRegisterAccountRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, proxyBusId,
                                                       proto_login::NF_SC_MSG_RegisterAccountRsp,
                                                       gcMsg,
                                                       clientLinkId);
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAccountLoginModule::OnHandleChangePasswordFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t proxyBusId, uint32_t nMsgId, const char* msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_login::Proto_CS_ChangePasswordReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, clientLinkId, msg, nLen, cgMsg);

    NFGetAccountTrans *pTrans = dynamic_cast<NFGetAccountTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_GET_ACCOUNT));
    if (pTrans) {
        pTrans->Init(proxyBusId, clientLinkId, nMsgId);
        pTrans->ProcessCSMsgReq(&cgMsg);
    }
    else
    {
        proto_login::Proto_SC_ChangePasswordRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, proxyBusId,
                                                       proto_login::NF_SC_MSG_CHANGE_PASSWORD_RESP,
                                                       gcMsg,
                                                       clientLinkId);
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAccountLoginModule::OnHandleAccountLoginFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t proxyBusId, uint32_t nMsgId, const char* msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_login::Proto_CSAccountLoginReq cgMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, clientLinkId, msg, nLen, cgMsg);

    NFGetAccountTrans *pTrans = dynamic_cast<NFGetAccountTrans *>(NFShmMgr::Instance()->CreateTrans(
            EOT_TRANS_GET_ACCOUNT));
    if (pTrans) {
        pTrans->Init(proxyBusId, clientLinkId, nMsgId);
        pTrans->ProcessCSMsgReq(&cgMsg);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFGetAccountTrans space not enough!");
        proto_login::Proto_SCAccountLoginRsp gcMsg;
        gcMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, proxyBusId,
                                                       proto_login::NF_SC_MSG_AccountLoginRsp,
                                                       gcMsg,
                                                       clientLinkId);
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}