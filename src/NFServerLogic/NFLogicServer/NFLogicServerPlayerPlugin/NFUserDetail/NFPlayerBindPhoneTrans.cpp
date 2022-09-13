// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerBindPhoneTrans.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPlayerBindPhoneTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFPlayerBindPhoneTrans.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerBindPhoneTrans, EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID, NFTransBase)

NFPlayerBindPhoneTrans::NFPlayerBindPhoneTrans()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFPlayerBindPhoneTrans::~NFPlayerBindPhoneTrans()
{

}

int NFPlayerBindPhoneTrans::CreateInit()
{
    m_phoneNum = 0;
    m_codeType = 0;
    return 0;
}

int NFPlayerBindPhoneTrans::ResumeInit()
{
    return 0;
}

int NFPlayerBindPhoneTrans::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode)
    {
        switch (m_cmd)
        {
            case proto_login::NF_CS_MSG_PlayerPhoneAutoCodeReq:
            {
                NFUserDetail *pUserDetail = UserDetail();
                CHECK_NULL(pUserDetail);
                proto_login::Proto_SC_Player_PhoneAutoCodeRsp rspMsg;
                rspMsg.set_result(iRunLogicRetCode);
                rspMsg.set_phone_num(pUserDetail->GetMiscData()->tmp_phone_num);

                pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerPhoneAutoCodeRsp, rspMsg);

                break;
            }
            case proto_login::NF_CS_MSG_PlayerCheckPhoneCodeReq:
            {
                NFUserDetail *pUserDetail = UserDetail();
                CHECK_NULL(pUserDetail);

                proto_login::Proto_SC_Player_CheckPhoneCodeRsp rspMsg;
                rspMsg.set_result(iRunLogicRetCode);
                rspMsg.set_phone_num(pUserDetail->GetMiscData()->tmp_phone_num);

                pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerCheckPhoneCodeRsp, rspMsg);
                break;
            }
            case proto_login::NF_CS_MSG_BIND_PHONE_REQ:
            {
                NFUserDetail *pUserDetail = UserDetail();
                CHECK_NULL(pUserDetail);

                proto_login::Proto_SC_Player_BindPhoneRsp rspMsg;
                rspMsg.set_result(iRunLogicRetCode);
                pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_BIND_PHONE_RSP, rspMsg);
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

int NFPlayerBindPhoneTrans::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    int iRetCode = HandleGetBaseInfoMsgParam(pCSMsgReq);
    if (iRetCode) {
        return iRetCode;
    }

    iRetCode = ProGetBaseInfoReq();
    if (iRetCode) {
        return iRetCode;
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFPlayerBindPhoneTrans::HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFUserDetail *pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    if (nMsgId == proto_ff::NF_WebTL_PLAYER_PHONE_AUTH_CODE_RSP)
    {
        proto_ff::WebTLPhoneAuthCodeRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        CHECK_EXPR(xMsg.phone_num() == m_phoneNum, -1, "phone is not right, xMsg.phone_num:{} m_phoneNum:{}", xMsg.phone_num(), m_phoneNum);

        proto_login::Proto_SC_Player_PhoneAutoCodeRsp rspMsg;
        rspMsg.set_result(xMsg.result());
        rspMsg.set_phone_num(xMsg.phone_num());
        rspMsg.set_code_type(m_codeType);

        pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerPhoneAutoCodeRsp, rspMsg);
        SetFinished(0);
        return 0;
    }
    else if (nMsgId == proto_ff::NF_WebTL_PLAYER_PHONE_CHECK_CODE_RSP)
    {
        proto_ff::WebTLPhoneAuthCodeRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        CHECK_EXPR(xMsg.phone_num() == m_phoneNum, -1, "phone is not right, xMsg.phone_num:{} m_phoneNum:{}", xMsg.phone_num(), m_phoneNum);

        if (xMsg.result() == 0)
        {
            pUserDetail->GetMiscData()->tmp_code_success = true;
        }
        else
        {
            pUserDetail->GetMiscData()->tmp_code_success = false;
        }
        proto_login::Proto_SC_Player_CheckPhoneCodeRsp rspMsg;
        rspMsg.set_result(xMsg.result());
        rspMsg.set_phone_num(xMsg.phone_num());
        rspMsg.set_code_type(pUserDetail->GetMiscData()->tmp_code_type);

        pUserDetail->SendMsgToClient(proto_login::NF_SC_MSG_PlayerCheckPhoneCodeRsp, rspMsg);

        SetFinished(0);
        return 0;
    }

    return proto_ff::ERR_CODE_SYSTEM_ERROR;
}

int NFPlayerBindPhoneTrans::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                           uint32_t seq,
                                           uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
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
    else if (cmd == proto_ff::E_STORESVR_S2C_INSERT)
    {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER)
        {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProInsertBaseInfoRes(pRes, cmd, table_id, err_code);
        }
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFPlayerBindPhoneTrans::ProInsertBaseInfoRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        return proto_ff::ERR_CODE_SYSTEM_ERROR;
    }
    else
    {
        NFUserDetail *pUserDetail = UserDetail();
        CHECK_NULL(pUserDetail);
        pUserDetail->GetData()->phonenum = m_phoneNum;
        pUserDetail->GetData()->nickname = m_nickname.GetString();
        pUserDetail->MarkDirty();

        proto_login::Proto_SC_Player_BindPhoneRsp rspMsg;
        rspMsg.set_result(0);
        rspMsg.set_phone_num(m_phoneNum);
        rspMsg.set_nick_name(m_nickname.GetString());
        pUserDetail->SendMsgToClient(proto_login::NF_CS_MSG_BIND_PHONE_RSP, rspMsg);
        SetFinished(0);
        return 0;
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return proto_ff::ERR_CODE_SYSTEM_ERROR;
}

int NFPlayerBindPhoneTrans::ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY)
        {
            NFUserDetail *pUserDetail = UserDetail();
            CHECK_NULL(pUserDetail);

            int iRetCode = HandleGetBaseInfoRes(pUserDetail);
            if (iRetCode)
            {
                SetFinished(iRetCode);
            }
            return 0;
        }

        return proto_ff::ERR_CODE_SYSTEM_ERROR;
    }
    else
    {
        NFUserDetail *pUserDetail = UserDetail();
        CHECK_NULL(pUserDetail);

        if (m_codeType == proto_ff::PHONE_AUTO_CODE_BIND_PHONE)
        {
            return proto_ff::ERR_CODE_BIND_PHONE_ALREADY;
        }
        else if (m_codeType == proto_ff::PHONE_AUTO_CODE_CHANG_BANK_PASSWORD) {
            int iRetCode = HandleGetBaseInfoRes(pUserDetail);
            if (iRetCode) {
                SetFinished(iRetCode);
            }
            return 0;
        }
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return proto_ff::ERR_CODE_SYSTEM_ERROR;
}

int NFPlayerBindPhoneTrans::ProGetBaseInfoReq()
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(NFCommon::tostr(m_phoneNum));

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                           proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                           GetGlobalID());
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFPlayerBindPhoneTrans::HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (m_cmd)
    {
        case proto_login::NF_CS_MSG_PlayerPhoneAutoCodeReq:
        {
            iRetCode = ProPhoneAutoCodeInfoReq(dynamic_cast<const proto_login::Proto_CS_Player_PhoneAutoCodeReq *>(pCSMsgReq));
            break;
        }
        case proto_login::NF_CS_MSG_PlayerCheckPhoneCodeReq:
        {
            iRetCode = ProPhoneCheckCodeInfoReq(dynamic_cast<const proto_login::Proto_CS_Player_CheckPhoneCodeReq *>(pCSMsgReq));
            break;
        }
        case proto_login::NF_CS_MSG_BIND_PHONE_REQ:
        {
            iRetCode = ProBindPhoneReq(dynamic_cast<const proto_login::Proto_CS_Player_BindPhoneReq *>(pCSMsgReq));
            break;
        }
        default:
        {
            iRetCode = -1;
            break;
        }
    }

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFPlayerBindPhoneTrans::ProPhoneCheckCodeInfoReq(const proto_login::Proto_CS_Player_CheckPhoneCodeReq *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pCSMsgReq, -1, "pLoginReq = NULL");

    m_phoneNum = pCSMsgReq->phone_num();
    NFUserDetail *pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    if (pUserDetail->GetMiscData()->tmp_phone_num > 0)
    {
        if (pUserDetail->GetMiscData()->tmp_phone_num != pCSMsgReq->phone_num())
        {
            return proto_ff::ERR_CODE_PLAYER_DONOT_CHANGE_PHONE;
        }

        if (pUserDetail->GetMiscData()->auth_code_stamp + 5*60 < (uint64_t)NFTime::Now().UnixSec())
        {
            return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
        }
    }

    proto_ff::LTWebPhoneCheckCodeReq reqMsg;
    reqMsg.set_phone_num(m_phoneNum);
    reqMsg.set_code(pCSMsgReq->auth_code());
    reqMsg.set_code_type(pUserDetail->GetMiscData()->tmp_code_type);

    NFMessageMgr::Instance()->SendTransToWebServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTWeb_PLAYER_PHONE_CHECK_CODE_REQ, reqMsg, GetGlobalID());

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFPlayerBindPhoneTrans::ProBindPhoneReq(const proto_login::Proto_CS_Player_BindPhoneReq *pCSMsgReq)
{
    m_phoneNum = pCSMsgReq->phone_num();
    m_nickname = pCSMsgReq->nick_name();

    NFUserDetail *pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    if (pUserDetail->GetMiscData()->tmp_phone_num > 0)
    {
        if (pUserDetail->GetMiscData()->tmp_phone_num != pCSMsgReq->phone_num())
        {
            return proto_ff::ERR_CODE_PLAYER_DONOT_CHANGE_PHONE;
        }

        if (pUserDetail->GetMiscData()->auth_code_stamp + 5*60 < (uint64_t)NFTime::Now().UnixSec())
        {
            return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
        }
    }
    else
    {
        return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
    }

    if (pUserDetail->GetMiscData()->tmp_code_success)
    {
        proto_ff::tbAccountTable accountInfo;
        accountInfo.set_account(NFCommon::tostr(m_phoneNum));
        accountInfo.set_password(pCSMsgReq->password());
        accountInfo.set_phonenum(m_phoneNum);
        accountInfo.set_device_id(pCSMsgReq->device_id());
        accountInfo.set_account_type(proto_ff::E_PHONE);
        accountInfo.set_real_player_id(pUserDetail->GetUserId());

        NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                         proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                         GetGlobalID());

        pUserDetail->ClearTmpPhoneData();
        return 0;
    }
    else
    {
        pUserDetail->ClearTmpPhoneData();
        return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
    }

    return 0;
}

int NFPlayerBindPhoneTrans::ProPhoneAutoCodeInfoReq(const proto_login::Proto_CS_Player_PhoneAutoCodeReq *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pCSMsgReq, -1, "pLoginReq = NULL");

    NFUserDetail *pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    if (pCSMsgReq->code_type() == proto_ff::PHONE_AUTO_CODE_BIND_PHONE && pUserDetail->GetPhonenum() > 0)
    {
        return proto_ff::ERR_CODE_PLAYER_ALREADY_BIND_PHONE;
    }

    if (pCSMsgReq->code_type() == proto_ff::PHONE_AUTO_CODE_CHANG_BANK_PASSWORD && pUserDetail->GetPhonenum() <= 0)
    {
        return proto_ff::ERR_CODE_FIRST_BIND_PHONE;
    }

    if (pUserDetail->GetMiscData()->tmp_phone_num > 0)
    {
        if (pUserDetail->GetMiscData()->auth_code_stamp + 60 > (uint64_t)NFTime::Now().UnixSec())
        {
            return proto_ff::ERR_CODE_PLAYER_PHONE_AUTO_CODE_TOO_MUCH;
        }
    }

    pUserDetail->ClearTmpPhoneData();
    pUserDetail->GetMiscData()->tmp_phone_num = pCSMsgReq->phone_num();
    pUserDetail->GetMiscData()->tmp_code_type = pCSMsgReq->code_type();
    pUserDetail->GetMiscData()->auth_code_stamp = NFTime::Now().UnixSec();
    pUserDetail->GetMiscData()->tmp_code_success = false;

    m_phoneNum = pCSMsgReq->phone_num();
    m_codeType = pCSMsgReq->code_type();

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFPlayerBindPhoneTrans::HandleGetBaseInfoRes(NFUserDetail *pUserDetail)
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (m_cmd)
    {
        case proto_login::NF_CS_MSG_PlayerPhoneAutoCodeReq:
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

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFPlayerBindPhoneTrans::ProPhoneAutoCodeRes()
{
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::LTWebPhoneAuthCodeReq reqMsg;
    reqMsg.set_phone_num(m_phoneNum);
    reqMsg.set_code_type(m_codeType);

    NFMessageMgr::Instance()->SendTransToWebServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTWeb_PLAYER_PHONE_AUTH_CODE_REQ, reqMsg, GetGlobalID());

    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}