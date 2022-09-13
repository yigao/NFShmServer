// -------------------------------------------------------------------------
//    @FileName         :    NFBindPhoneTrans.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFBindPhoneTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFBindPhoneTrans.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFAccountLoginMgr.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFServerIpMgr.h"
#include "NFPhoneAutoCodeMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBindPhoneTrans, EOT_TRANS_REGISTER_ACCOUNT_BIND_PHONE, NFTransBase)

NFBindPhoneTrans::NFBindPhoneTrans()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFBindPhoneTrans::~NFBindPhoneTrans()
{

}

int NFBindPhoneTrans::CreateInit()
{
    m_phoneNum = 0;
    mProxyBusId = 0;
    mClientLinkId = 0;
    mCmd = 0;
    return 0;
}

int NFBindPhoneTrans::ResumeInit()
{
    return 0;
}

int NFBindPhoneTrans::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode)
    {
        switch (mCmd)
        {
            case proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq:
            {
                proto_login::Proto_SC_LoginServer_PhoneAutoCodeRsp rspMsg;
                rspMsg.set_result(iRunLogicRetCode);
                rspMsg.set_phone_num(m_phoneNum);

                NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                               proto_login::NF_SC_MSG_LoginServer_PhoneAutoCodeRsp,
                                                               rspMsg,
                                                               mClientLinkId);
                break;
            }
            case proto_login::NF_CS_MSG_LoginServer_CheckPhoneCodeReq:
            {
                proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp rspMsg;
                rspMsg.set_result(iRunLogicRetCode);
                rspMsg.set_phone_num(m_phoneNum);

                NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                               proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp,
                                                               rspMsg,
                                                               mClientLinkId);
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return 0;
}

int NFBindPhoneTrans::Init(uint32_t busId, uint64_t clientLinkId, uint32_t cmd)
{
    NFTransBase::Init();
    mProxyBusId = busId;
    mClientLinkId = clientLinkId;
    mCmd = cmd;
    return 0;
}

int NFBindPhoneTrans::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    int iRetCode = HandleGetBaseInfoMsgParam(pCSMsgReq);
    if (iRetCode) {
        return iRetCode;
    }

    iRetCode = ProGetBaseInfoReq();
    if (iRetCode) {
        return iRetCode;
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFBindPhoneTrans::HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    if (nMsgId == proto_ff::NF_WebTL_PHONE_AUTH_CODE_RSP)
    {
        proto_ff::WebTLPhoneAuthCodeRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
        CHECK_EXPR(pLogin, -1, "pLogin == NULL");
        CHECK_EXPR(xMsg.phone_num() == m_phoneNum, -1, "phone is not right, xMsg.phone_num:{} m_phoneNum:{}", xMsg.phone_num(), m_phoneNum);

        proto_login::Proto_SC_LoginServer_PhoneAutoCodeRsp rspMsg;
        rspMsg.set_result(xMsg.result());
        rspMsg.set_phone_num(xMsg.phone_num());
        rspMsg.set_code_type(pLogin->m_codeType);

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                             proto_login::NF_SC_MSG_LoginServer_PhoneAutoCodeRsp,
                                                             rspMsg,
                                                             mClientLinkId);

        SetFinished(0);
        return 0;
    }
    else if (nMsgId == proto_ff::NF_WebTL_PHONE_CHECK_CODE_RSP)
    {
        proto_ff::WebTLPhoneAuthCodeRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        CHECK_EXPR(xMsg.phone_num() == m_phoneNum, -1, "phone is not right, xMsg.phone_num:{} m_phoneNum:{}", xMsg.phone_num(), m_phoneNum);

        NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
        if (pLogin)
        {
            if (xMsg.result() == 0)
            {
                pLogin->m_checkSuccess = true;
            }
            else
            {
                pLogin->m_checkSuccess = false;
            }
            proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp rspMsg;
            rspMsg.set_result(xMsg.result());
            rspMsg.set_phone_num(xMsg.phone_num());
            rspMsg.set_code_type(pLogin->m_codeType);

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                           proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp,
                                                           rspMsg,
                                                           mClientLinkId);
        }
        else
        {
            proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp rspMsg;
            rspMsg.set_result(proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT);
            rspMsg.set_phone_num(xMsg.phone_num());

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                           proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp,
                                                           rspMsg,
                                                           mClientLinkId);
        }



        SetFinished(0);
        return 0;
    }

    return proto_ff::ERR_CODE_SYSTEM_ERROR;
}

int NFBindPhoneTrans::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                      uint32_t seq,
                                      uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ)
    {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER)
        {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProGetBaseInfoRes(pRes, cmd, table_id, err_code);
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFBindPhoneTrans::ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY)
        {
            NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
            if (pLogin)
            {
                int iRetCode = HandleGetBaseInfoRes(pLogin);
                if (iRetCode)
                {
                    SetFinished(iRetCode);
                }
            }
            else
            {
                return proto_ff::ERR_CODE_SYSTEM_ERROR;
            }
            return 0;
        }

        return proto_ff::ERR_CODE_SYSTEM_ERROR;
    }
    else
    {
        NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
        if (pLogin)
        {
            if (pLogin->m_codeType == proto_ff::PHONE_AUTO_CODE_REGISTER)
            {
                return proto_ff::ERR_CODE_BIND_PHONE_ALREADY;
            }
            else if (pLogin->m_codeType == proto_ff::PHONE_AUTO_CODE_CHANGE_PASSWORD || pLogin->m_codeType == proto_ff::PHONE_AUTO_CODE_CHANGE_DEVICE) {
                int iRetCode = HandleGetBaseInfoRes(pLogin);
                if (iRetCode) {
                    SetFinished(iRetCode);
                }
                return 0;
            }
        }
        else
        {
            return proto_ff::ERR_CODE_SYSTEM_ERROR;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return proto_ff::ERR_CODE_SYSTEM_ERROR;
}

int NFBindPhoneTrans::ProGetBaseInfoReq()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(NFCommon::tostr(m_phoneNum));

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                           proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                           GetGlobalID(), 0, m_phoneNum);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFBindPhoneTrans::HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq:
        {
            iRetCode = ProPhoneAutoCodeInfoReq(dynamic_cast<const proto_login::Proto_CS_LoginServer_PhoneAutoCodeReq *>(pCSMsgReq));
            break;
        }
        case proto_login::NF_CS_MSG_LoginServer_CheckPhoneCodeReq:
        {
            iRetCode = ProPhoneCheckCodeInfoReq(dynamic_cast<const proto_login::Proto_CS_LoginServer_CheckPhoneCodeReq *>(pCSMsgReq));
            break;
        }
        default:
        {
            iRetCode = -1;
            break;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFBindPhoneTrans::ProPhoneCheckCodeInfoReq(const proto_login::Proto_CS_LoginServer_CheckPhoneCodeReq *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pCSMsgReq, -1, "pLoginReq = NULL");

    m_phoneNum = pCSMsgReq->phone_num();

    NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
    if (pLogin == NULL)
    {
        return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
    }

    pLogin->m_lastTime = NFTime::Now().UnixSec();

    proto_ff::LTWebPhoneCheckCodeReq reqMsg;
    reqMsg.set_phone_num(m_phoneNum);
    reqMsg.set_code(pCSMsgReq->auth_code());
    reqMsg.set_code_type(pLogin->m_codeType);

    NFMessageMgr::Instance()->SendTransToWebServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTWeb_PHONE_CHECK_CODE_REQ, reqMsg, GetGlobalID());

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFBindPhoneTrans::ProPhoneAutoCodeInfoReq(const proto_login::Proto_CS_LoginServer_PhoneAutoCodeReq *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pCSMsgReq, -1, "pLoginReq = NULL");

    m_phoneNum = pCSMsgReq->phone_num();

    NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
    if (pLogin == NULL)
    {
        pLogin = NFPhoneAutoCodeMgr::Instance()->CreatePhone(m_phoneNum);
        CHECK_NULL(pLogin);
    }

    pLogin->m_codeType = pCSMsgReq->code_type();

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFBindPhoneTrans::HandleGetBaseInfoRes(NFPhoneAutoCode *pUserLogin)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq:
        {
            iRetCode = ProPhoneAutoCodeRes();
            break;
        }
        default:
        {
            iRetCode = -1;
            break;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFBindPhoneTrans::ProPhoneAutoCodeRes()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    NFPhoneAutoCode* pLogin = NFPhoneAutoCodeMgr::Instance()->FindPhone(m_phoneNum);
    CHECK_NULL(pLogin);

    pLogin->m_lastTime = NFTime::Now().UnixSec();

    proto_ff::LTWebPhoneAuthCodeReq reqMsg;
    reqMsg.set_phone_num(m_phoneNum);
    reqMsg.set_code_type(pLogin->m_codeType);

    NFMessageMgr::Instance()->SendTransToWebServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTWeb_PHONE_AUTH_CODE_REQ, reqMsg, GetGlobalID());

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}