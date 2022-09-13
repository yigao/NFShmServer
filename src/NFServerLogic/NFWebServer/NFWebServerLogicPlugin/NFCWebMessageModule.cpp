// -------------------------------------------------------------------------
//    @FileName         :    NFCWebMessageModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCWebMessageModule.cpp
//
// -------------------------------------------------------------------------

#include "NFCWebMessageModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFHmacSha.h"
#include "NFComm/NFCore/NFBase64.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFMessageDefine/proto_svr_web.pb.h"
#include <stdio.h>

NFCWebMessageModule::NFCWebMessageModule(NFIPluginManager* p):NFIDynamicModule(p)
{
}

NFCWebMessageModule::~NFCWebMessageModule()
{
}

bool NFCWebMessageModule::Awake() {

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_LTWeb_PHONE_AUTH_CODE_REQ, this,
                                                       &NFCWebMessageModule::OnHandleRegisterAccountPhoneAutoCodeReq);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_LTWeb_PHONE_CHECK_CODE_REQ, this,
                                                 &NFCWebMessageModule::OnHandleAccountPhoneCheckCodeReq);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_LTWeb_PLAYER_PHONE_AUTH_CODE_REQ, this,
                                                 &NFCWebMessageModule::OnHandlePlayerPhoneAutoCodeReq);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_LTWeb_PLAYER_PHONE_CHECK_CODE_REQ, this,
                                                 &NFCWebMessageModule::OnHandlePlayerPhoneCheckCodeReq);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_SEVER_TO_WEB_SERVER_RSP_NOTIFY, this,
                                                 &NFCWebMessageModule::OnHandleWebServerRspNotify);
    return true;
}

int NFCWebMessageModule::OnHandleRegisterAccountPhoneAutoCodeReq(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::LTWebPhoneAuthCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, loginLinkId, msg, nLen, xMsg);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WEB_SERVER);
    CHECK_NULL(pConfig);

    uint32_t loginBusId = GetServerIndexFromUnlinkId(loginLinkId);
    std::string event;
    if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_REGISTER)
    {
        event = "register";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANGE_PASSWORD)
    {
        event = "changepassword";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANGE_DEVICE)
    {
        event = "changedevice";
    }

    std::string url = pConfig->mWwwUrl + "/index.php/api/sms/send?mobile=" + NFCommon::tostr(xMsg.phone_num()) + "&event=" + event;
    FindModule<NFIMessageModule>()->HttpGet(NF_ST_WEB_SERVER, url, [this, url, reqBusId, loginBusId, xMsg](int code, const std::string& resp){
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, ret code:{} errmsg:{}", url, code, resp);
        int ret = 0;
        proto_ff::WebTLPhoneAuthCodeRsp rspMsg;
        if (code == 200)
        {
            proto_ff::WebPhoneCodeRetMsg httpMsg;
            NFProtobufCommon::JsonToProtoMessage(resp, &httpMsg);
            if (httpMsg.code() == 1)
            {
                ret = 0;
            }
            else if (httpMsg.code() == 0)
            {
                if (httpMsg.msg() == "发送频繁")
                {
                    ret = proto_ff::ERR_CODE_PHONE_SEND_TOO_MUCH;
                }
                else if (httpMsg.msg() == "手机号不正确")
                {
                    ret = proto_ff::ERR_CODE_PHONE_NOT_RIGHT;
                }
                else
                {
                    ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
                }
            }
            else
            {
                ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
            }
            rspMsg.set_msg(httpMsg.msg());
        }
        else
        {
            ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
        }


        rspMsg.set_result(ret);
        rspMsg.set_phone_num(xMsg.phone_num());
        NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_WEB_SERVER, loginBusId, proto_ff::NF_WebTL_PHONE_AUTH_CODE_RSP, rspMsg, 0, reqBusId);
    });
    return 0;
}

int NFCWebMessageModule::OnHandleAccountPhoneCheckCodeReq(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::LTWebPhoneCheckCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, loginLinkId, msg, nLen, xMsg);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WEB_SERVER);
    CHECK_NULL(pConfig);

    uint32_t loginBusId = GetServerIndexFromUnlinkId(loginLinkId);
    std::string event;
    if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_REGISTER)
    {
        event = "register";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANGE_PASSWORD)
    {
        event = "changepassword";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANGE_DEVICE)
    {
        event = "changedevice";
    }

    std::string url = pConfig->mWwwUrl + "/index.php/api/sms/check?mobile=" + NFCommon::tostr(xMsg.phone_num()) + "&event=" + event + "&captcha=" + NFCommon::tostr(xMsg.code());
    FindModule<NFIMessageModule>()->HttpGet(NF_ST_WEB_SERVER, url, [this, url, reqBusId, loginBusId, xMsg](int code, const std::string& resp){
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, ret code:{} errmsg:{}", url, code, resp);
        int ret = 0;
        proto_ff::WebTLPhoneCheckCodeRsp rspMsg;
        if (code == 200)
        {
            proto_ff::WebPhoneCodeRetMsg httpMsg;
            NFProtobufCommon::JsonToProtoMessage(resp, &httpMsg);
            if (httpMsg.code() == 1)
            {
                ret = 0;
            }
            else if (httpMsg.code() == 0)
            {
                if (httpMsg.msg() == "发送频繁")
                {
                    ret = proto_ff::ERR_CODE_PHONE_SEND_TOO_MUCH;
                }
                else if (httpMsg.msg() == "验证码不正确")
                {
                    ret = proto_ff::ERR_CODE_PHONE_AUTO_CODE_ERROR;
                }
                else
                {
                    ret = proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
                }
            }
            else
            {
                ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
            }
            rspMsg.set_msg(httpMsg.msg());
        }
        else
        {
            ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
        }

        rspMsg.set_result(ret);
        rspMsg.set_phone_num(xMsg.phone_num());
        NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_WEB_SERVER, loginBusId, proto_ff::NF_WebTL_PHONE_CHECK_CODE_RSP, rspMsg, 0, reqBusId);
    });
    return 0;
}

bool NFCWebMessageModule::Init() {
    
    return true;
}

bool NFCWebMessageModule::Execute() {
    return true;
}

void NFCWebMessageModule::OnTimer(uint32_t nTimerID)
{
}

int NFCWebMessageModule::OnHandlePlayerPhoneAutoCodeReq(uint64_t unLinkId, uint64_t logicLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::LTWebPhoneAuthCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, logicLinkId, msg, nLen, xMsg);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WEB_SERVER);
    CHECK_NULL(pConfig);

    uint32_t logicBusId = GetServerIndexFromUnlinkId(logicLinkId);
    std::string event;
    if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_BIND_PHONE)
    {
        event = "bindphone";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANG_BANK_PASSWORD)
    {
        event = "changebankpassword";
    }

    std::string url = pConfig->mWwwUrl + "/index.php/api/sms/send?mobile=" + NFCommon::tostr(xMsg.phone_num()) + "&event=" + event;
    FindModule<NFIMessageModule>()->HttpGet(NF_ST_WEB_SERVER, url, [this, url, reqBusId, logicBusId, xMsg](int code, const std::string& resp){
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, ret code:{} errmsg:{}", url, code, resp);
        int ret = 0;
        proto_ff::WebTLPhoneAuthCodeRsp rspMsg;
        if (code == 200)
        {
            proto_ff::WebPhoneCodeRetMsg httpMsg;
            NFProtobufCommon::JsonToProtoMessage(resp, &httpMsg);
            if (httpMsg.code() == 1)
            {
                ret = 0;
            }
            else if (httpMsg.code() == 0)
            {
                if (httpMsg.msg() == "发送频繁")
                {
                    ret = proto_ff::ERR_CODE_PHONE_SEND_TOO_MUCH;
                }
                else if (httpMsg.msg() == "手机号不正确")
                {
                    ret = proto_ff::ERR_CODE_PHONE_NOT_RIGHT;
                }
                else
                {
                    ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
                }
            }
            else
            {
                ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
            }
            rspMsg.set_msg(httpMsg.msg());
        }
        else
        {
            ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
        }


        rspMsg.set_result(ret);
        rspMsg.set_phone_num(xMsg.phone_num());
        NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_WEB_SERVER, logicBusId, proto_ff::NF_WebTL_PLAYER_PHONE_AUTH_CODE_RSP, rspMsg, 0, reqBusId);
    });
    return 0;
}

int NFCWebMessageModule::OnHandlePlayerPhoneCheckCodeReq(uint64_t unLinkId, uint64_t logicLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::LTWebPhoneCheckCodeReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, logicLinkId, msg, nLen, xMsg);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WEB_SERVER);
    CHECK_NULL(pConfig);

    uint32_t logicBusId = GetServerIndexFromUnlinkId(logicLinkId);
    std::string event;
    if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_BIND_PHONE)
    {
        event = "bindphone";
    }
    else if (xMsg.code_type() == proto_ff::PHONE_AUTO_CODE_CHANG_BANK_PASSWORD)
    {
        event = "changebankpassword";
    }

    std::string url = pConfig->mWwwUrl + "/index.php/api/sms/check?mobile=" + NFCommon::tostr(xMsg.phone_num()) + "&event=" + event + "&captcha=" + NFCommon::tostr(xMsg.code());
    FindModule<NFIMessageModule>()->HttpGet(NF_ST_WEB_SERVER, url, [this, url, reqBusId, logicBusId, xMsg](int code, const std::string& resp){
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "HttpGet url:{}, ret code:{} errmsg:{}", url, code, resp);
        int ret = 0;
        proto_ff::WebTLPhoneCheckCodeRsp rspMsg;
        if (code == 200)
        {
            proto_ff::WebPhoneCodeRetMsg httpMsg;
            NFProtobufCommon::JsonToProtoMessage(resp, &httpMsg);
            if (httpMsg.code() == 1)
            {
                ret = 0;
            }
            else if (httpMsg.code() == 0)
            {
                if (httpMsg.msg() == "发送频繁")
                {
                    ret = proto_ff::ERR_CODE_PHONE_SEND_TOO_MUCH;
                }
                else if (httpMsg.msg() == "验证码不正确")
                {
                    ret = proto_ff::ERR_CODE_PHONE_AUTO_CODE_ERROR;
                }
                else
                {
                    ret = proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
                }
            }
            else
            {
                ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
            }
            rspMsg.set_msg(httpMsg.msg());
        }
        else
        {
            ret = proto_ff::ERR_CODE_SYSTEM_ERROR;
        }

        rspMsg.set_result(ret);
        rspMsg.set_phone_num(xMsg.phone_num());
        NFMessageMgr::Instance()->SendTransToLoginServer(NF_ST_WEB_SERVER, logicBusId, proto_ff::NF_WebTL_PLAYER_PHONE_CHECK_CODE_RSP, rspMsg, 0, reqBusId);
    });
    return 0;
}

int NFCWebMessageModule::OnHandleWebServerRspNotify(uint64_t unLinkId, uint64_t linkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::Proto_STWebMsgRspNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, linkId, msg, nLen, xMsg);

    proto_ff::Proto_Web_CommonRspNotify rspNotify;
    rspNotify.set_result(xMsg.result());
    rspNotify.set_msg(xMsg.err_msg());

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(rspNotify, &json);

    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_WEB_SERVER, xMsg.request_id(), json, NFWebStatus::WEB_OK);
    return 0;
}