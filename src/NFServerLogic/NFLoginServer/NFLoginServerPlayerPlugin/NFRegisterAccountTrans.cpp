// -------------------------------------------------------------------------
//    @FileName         :    NFRegisterAccountTrans.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRegisterAccountTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFRegisterAccountTrans.h"
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
#include "NFComm/NFMessageDefine/proto_svr_behavior.pb.h"
#include "NFLoginEventDisp.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRegisterAccountTrans, EOT_TRANS_REGISTER_ACCOUNT, NFGetAccountTrans)


NFRegisterAccountTrans::NFRegisterAccountTrans()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFRegisterAccountTrans::~NFRegisterAccountTrans()
{

}

int NFRegisterAccountTrans::CreateInit()
{
    mCheckAccount = false;
    memset(&m_data, 0, sizeof(m_data));
    return 0;
}

int NFRegisterAccountTrans::ResumeInit()
{
    return 0;
}

int NFRegisterAccountTrans::HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_RegisterAccountReq:
        {
            iRetCode = ProRigisterAccountInfoReq(dynamic_cast<const proto_login::Proto_CSRegisterAccountReq *>(pCSMsgReq));
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

int NFRegisterAccountTrans::ProRigisterAccountInfoReq(const proto_login::Proto_CSRegisterAccountReq *pRegisterReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pRegisterReq, -1, "pLoginReq = NULL");

    mAccount = pRegisterReq->account();
    mPassword = pRegisterReq->password();
    mLoginType = proto_ff::E_PHONE;
    mDeviecId = pRegisterReq->device_id();

    uint64_t phoneNum = NFCommon::strto<uint64_t>(mAccount.GetString());
    NFPhoneAutoCode* pPhone = NFPhoneAutoCodeMgr::Instance()->FindPhone(phoneNum);
    if (pPhone && pPhone->m_codeType == proto_ff::PHONE_AUTO_CODE_REGISTER)
    {
        if (pPhone->m_checkSuccess == false)
        {
            return proto_ff::ERR_CODE_PHONE_AUTO_CODE_ERROR;
        }

        NFPhoneAutoCodeMgr::Instance()->DeletePhone(phoneNum);
    }
    else
    {
        return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
    }

    mNickName.Copy(pRegisterReq->nick_name());
    const ::proto_login::Proto_UserLoginExternalData& extData = pRegisterReq->ext_data();
    m_data.aread_id = extData.aread_id();
    m_data.agent_id = extData.agent_id();
    m_data.channel_id = extData.channel_id();
    m_data.referral_code = extData.referral_code();
    m_data.platform_os.Copy(extData.platform_os());
    m_data.country.Copy(extData.country());
    m_data.province.Copy(extData.province());
    m_data.city.Copy(extData.city());
    m_data.phone_mode.Copy(extData.phone_mode());
    m_data.device_id.Copy(pRegisterReq->device_id());

    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    if (pLogin)
    {
        return proto_ff::ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_RESITER;
    }

    mCheckAccount = true;

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


int NFRegisterAccountTrans::HandleGetBaseInfoRes(NFAccountLogin *pUserLogin)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_RegisterAccountReq:
        {
            iRetCode = ProRegisterAccountRes();
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

int NFRegisterAccountTrans::ProRegisterAccountRes()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    CHECK_NULL(pLogin);

    if (pLogin->mPassword.GetString() != mPassword.GetString())
    {
        return proto_ff::ERR_CODE_ACCOUNT_PASSWORD_ERROR;
    }

    pLogin->mLastLoginTime = NFTime::Now().UnixSec();
    NFLoginEventDisp::AccountRegister(pLogin);

    proto_ff::Proto_LTWRegisterUserReq req;
    req.set_user_id(pLogin->mPlayerId);
    req.set_nick_name(mNickName.GetString());
    if (mLoginType == proto_ff::E_PHONE)
    {
        req.set_phone_num(NFCommon::strto<uint64_t>(mAccount.GetString()));
    }
    proto_ff_s::LoginCommonData_s::write_to_pbmsg(m_data, *req.mutable_ext_data());
    NFMessageMgr::Instance()->SendTransToWorldServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTW_REGISTER_USER_TO_WORLD_REQ, req, GetGlobalID());

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRegisterAccountTrans::HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    if (nMsgId == proto_ff::NF_LTL_REGISTER_USER_TO_LOGIN_RSP)
    {
        proto_ff::Proto_LTLRegisterUserRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
        CHECK_NULL(pLogin);

        proto_login::Proto_SCRegisterAccountRsp gcMsg;
        gcMsg.set_result(0);
        gcMsg.set_user_id(pLogin->mPlayerId);
        gcMsg.set_login_time(pLogin->mLastLoginTime);
        gcMsg.set_token(NFCommLogic::GetLoginToken(pLogin->mAccount.GetString(), pLogin->mPlayerId, pLogin->mLastLoginTime, LOGIN_TOKEN));

        std::vector<NF_SHARE_PTR<proto_ff::ServerInfoReport>> pServerList = NFServerIpMgr::Instance()->GetServerList();
        for(int i = 0; i < (int)pServerList.size(); i++)
        {
            NF_SHARE_PTR<proto_ff::ServerInfoReport> pServer = pServerList[i];
            if (pServer)
            {
                proto_login::Proto_CSServerIP* pIp = gcMsg.add_server_ip_list();
                pIp->set_ip(pServer->external_server_ip());
                pIp->set_port(pServer->external_server_port());
            }
        }

        NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                             proto_login::NF_SC_MSG_RegisterAccountRsp,
                                                             gcMsg,
                                                             mClientLinkId);
    }
    else
    {
        return -1;
    }

    SetFinished(0);
    return 0;
}

int NFRegisterAccountTrans::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0) {
        if (mCmd == proto_login::NF_CS_MSG_RegisterAccountReq)
        {
            proto_login::Proto_SCRegisterAccountRsp gcMsg;
            gcMsg.set_result(iRunLogicRetCode);

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                                 proto_login::NF_SC_MSG_RegisterAccountRsp,
                                                                 gcMsg,
                                                                 mClientLinkId);
        }
    }

    return 0;
}

int NFRegisterAccountTrans::ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res *pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    if (mCmd == proto_login::NF_CS_MSG_RegisterAccountReq)
    {
        if (mCheckAccount)
        {
            if (err_code == 0)
            {
                return proto_ff::ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_RESITER;
            }

            mCheckAccount = false;
        }
    }

    if (err_code != 0)
    {
        if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY)
        {
            NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Account:{} not exist in db", mAccount.Get());
            return CreateAccountReq();
        }

        return -1;
    }

    proto_ff::tbAccountTable accountInfo;
    accountInfo.ParseFromString(pSelRsp->sel_record());

    if (mAccount.GetString() != accountInfo.account() || mPassword.GetString() != accountInfo.password() ||
        accountInfo.player_id() <= 0) {
        NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Account:{} Password:{} is not right", mAccount.Get(), mPassword.Get());
        return proto_ff::ERR_CODE_ACCOUNT_PASSWORD_ERROR;
    }

    if (accountInfo.real_player_id() > 0)
    {
        accountInfo.set_player_id(accountInfo.real_player_id());
    }

    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->CreateAccount(accountInfo.account(), accountInfo.password(), accountInfo.player_id(), accountInfo.account_type(), accountInfo.device_id(), accountInfo.phonenum());
    CHECK_NULL(pLogin);

    int iRetCode = HandleGetBaseInfoRes(pLogin);
    if (iRetCode) {
        return iRetCode;
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRegisterAccountTrans::CreateAccountReq() {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    if (mLoginType == proto_ff::E_VISITOR)
    {
        return -1;
    }

    SetState(CREATE_ACCOUNT);
    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(mAccount.GetString());
    accountInfo.set_password(mPassword.GetString());
    accountInfo.set_account_type(mLoginType);
    accountInfo.set_device_id(mDeviecId.GetString());
    if (mLoginType == proto_ff::E_PHONE)
    {
        accountInfo.set_phonenum(NFCommon::strto<uint64_t>(mAccount.GetString()));
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", accountInfo.DebugString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                           proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                           GetGlobalID(), 0, NFHash::hash<std::string>()(mAccount.GetString()));

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
