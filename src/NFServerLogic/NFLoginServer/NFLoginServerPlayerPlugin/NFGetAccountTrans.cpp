// -------------------------------------------------------------------------
//    @FileName         :    NFGetAccountTrans.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGetAccountTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFGetAccountTrans.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFAccountLoginMgr.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFServerIpMgr.h"
#include "NFPhoneAutoCodeMgr.h"
#include "NFLoginEventDisp.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGetAccountTrans, EOT_TRANS_GET_ACCOUNT, NFTransBase)

NFGetAccountTrans::NFGetAccountTrans() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGetAccountTrans::~NFGetAccountTrans() {

}

int NFGetAccountTrans::CreateInit() {
    mProxyBusId = 0;
    mClientLinkId = 0;
	mLoginType = 0;
	mCmd = 0;
    mCreateAccount = false;
    return 0;
}

int NFGetAccountTrans::ResumeInit() {
    return 0;
}

int NFGetAccountTrans::Init(uint32_t busId, uint64_t clientLinkId, uint32_t cmd) {
    NFTransBase::Init();
    mProxyBusId = busId;
    mClientLinkId = clientLinkId;
	mCmd = cmd;
    return 0;
}

int NFGetAccountTrans::ProGetAccountInfoRes()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    CHECK_NULL(pLogin);

    if (pLogin->mPassword.GetString() != mPassword.GetString())
    {
        return proto_ff::ERR_CODE_ACCOUNT_PASSWORD_ERROR;
    }

    if (pLogin->mPhoneNum > 0)
    {
        NFPhoneAutoCode* pPhone = NFPhoneAutoCodeMgr::Instance()->FindPhone(pLogin->mPhoneNum);
        if (pPhone && pPhone->m_codeType == proto_ff::PHONE_AUTO_CODE_CHANGE_DEVICE)
        {
            if (pPhone->m_checkSuccess == false)
            {
                NFPhoneAutoCodeMgr::Instance()->DeletePhone(pLogin->mPhoneNum);
                return proto_ff::ERR_CODE_PHONE_AUTO_CODE_ERROR;
            }

            NFPhoneAutoCodeMgr::Instance()->DeletePhone(pLogin->mPhoneNum);

            pLogin->mDeviceId = mDeviecId;

            proto_ff::tbAccountTable accountInfo;
            accountInfo.set_account(pLogin->mAccount.GetString());
            accountInfo.set_device_id(mDeviecId.GetString());

            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                             proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                             0, 0, NFHash::hash<std::string>()(pLogin->mAccount.GetString()));

            proto_ff::LTLPlayerDeviceChangeNotify deviceNotify;
            deviceNotify.set_user_id(pLogin->mPlayerId);
            deviceNotify.set_device_id(mDeviecId.GetString());

            NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY, deviceNotify);
        }
    }

    if (pLogin->mDeviceId.GetString() != mDeviecId.GetString())
    {
        if (pLogin->mDeviceId.GetString().empty() || pLogin->mDeviceId.GetString() == "NULL")
        {
            proto_ff::tbAccountTable accountInfo;
            accountInfo.set_account(pLogin->mAccount.GetString());
            accountInfo.set_device_id(mDeviecId.GetString());

            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                             proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                             0, 0, NFHash::hash<std::string>()(pLogin->mAccount.GetString()));

            pLogin->mDeviceId = mDeviecId;

            proto_ff::LTLPlayerDeviceChangeNotify deviceNotify;
            deviceNotify.set_user_id(pLogin->mPlayerId);
            deviceNotify.set_device_id(mDeviecId.GetString());

            NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTL_PLAYER_DEVICE_CHANGE_NOTIFY, deviceNotify);
        }
        else
        {
            if (pLogin->mPhoneNum > 0)
            {
                proto_login::Proto_SC_LoginServer_NotifyPhoneCheck gcMsg;
                gcMsg.set_result(0);
                gcMsg.set_phone_num(pLogin->mPhoneNum);
                NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                               proto_login::NF_SC_MSG_LoginServer_NotifyPhoneCheck,
                                                               gcMsg,
                                                               mClientLinkId);

                SetFinished(0);
                return 0;
            }
            else if (mLoginType == proto_ff::E_VISITOR)
            {
                return proto_ff::ERR_CODE_VISITOR_LOGIN_DEVICE_ERROR;
            }
        }
    }

    pLogin->mLastLoginTime = NFTime::Now().UnixSec();
    NFLoginEventDisp::AccountLogin(pLogin);

    proto_login::Proto_SCAccountLoginRsp gcMsg;
    gcMsg.set_result(0);
    gcMsg.set_user_id(pLogin->mPlayerId);
    gcMsg.set_login_time(pLogin->mLastLoginTime);
    gcMsg.set_token(NFCommLogic::GetLoginToken(pLogin->mAccount.GetString(), pLogin->mPlayerId, pLogin->mLastLoginTime, LOGIN_TOKEN));

    std::vector<NF_SHARE_PTR<NFServerData>> pServerList = NFMessageMgr::Instance()->GetServerByServerType(NF_ST_LOGIN_SERVER, NF_ST_PROXY_SERVER);
    for(int i = 0; i < (int)pServerList.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pServer = pServerList[i];
        if (pServer)
        {
            proto_login::Proto_CSServerIP* pIp = gcMsg.add_server_ip_list();
            pIp->set_ip(pServer->mServerInfo.external_server_ip());
            pIp->set_port(pServer->mServerInfo.external_server_port());
        }
    }

    NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                         proto_login::NF_SC_MSG_AccountLoginRsp,
                                                         gcMsg,
                                                         mClientLinkId);

    SetFinished(0);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::ProChangePasswordRes()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    CHECK_NULL(pLogin);

    if (pLogin->mPassword.GetString() == mPassword.GetString())
    {
        return proto_ff::ERR_CODE_PASSWORD_NOT_CHANGE;
    }

    pLogin->mPassword = mPassword;

    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(pLogin->mAccount.GetString());
    accountInfo.set_password(mPassword.GetString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                     GetGlobalID(), 0, NFHash::hash<std::string>()(pLogin->mAccount.GetString()));

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::HandleGetBaseInfoRes(NFAccountLogin *pUserLogin)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_AccountLoginReq:
        {
            iRetCode = ProGetAccountInfoRes();
            break;
        }
        case proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ:
        {
            iRetCode = ProChangePasswordRes();
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

int NFGetAccountTrans::HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    switch (mCmd)
    {
        case proto_login::NF_CS_MSG_AccountLoginReq:
        {
            iRetCode = ProGetAccountInfoReq(dynamic_cast<const proto_login::Proto_CSAccountLoginReq *>(pCSMsgReq));
            break;
        }
        case proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ:
        {
            iRetCode = ProGetAccountInfoReq(dynamic_cast<const proto_login::Proto_CS_ChangePasswordReq *>(pCSMsgReq));
            break;
        }
        default:
        {
            iRetCode = proto_ff::ERR_CODE_SYSTEM_ERROR;
            break;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFGetAccountTrans::ProGetBaseInfoReq()
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(mAccount.GetString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                           proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                           GetGlobalID(), 0, NFHash::hash<std::string>()(mAccount.GetString()));
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    int iRetCode = HandleGetBaseInfoMsgParam(pCSMsgReq);
    if (iRetCode) {
        return iRetCode;
    }

    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    if (pLogin)
    {
        iRetCode = HandleGetBaseInfoRes(pLogin);
        if (iRetCode)
        {
            return iRetCode;
        }
    }
    else
    {
        iRetCode = ProGetBaseInfoReq();
        if (iRetCode) {
            return iRetCode;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::ProGetAccountInfoReq(const proto_login::Proto_CS_ChangePasswordReq *pLoginReq)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

    mAccount = pLoginReq->account();
    mPassword = pLoginReq->new_password();
    mDeviecId = pLoginReq->device_id();

    mLoginType = proto_ff::E_PHONE;

    uint64_t phoneNum = NFCommon::strto<uint64_t>(mAccount.GetString());
    NFPhoneAutoCode* pPhone = NFPhoneAutoCodeMgr::Instance()->FindPhone(phoneNum);
    if (pPhone && pPhone->m_codeType == proto_ff::PHONE_AUTO_CODE_CHANGE_PASSWORD)
    {
        if (pPhone->m_checkSuccess == false)
        {
            NFPhoneAutoCodeMgr::Instance()->DeletePhone(phoneNum);
            return proto_ff::ERR_CODE_PHONE_AUTO_CODE_ERROR;
        }

        NFPhoneAutoCodeMgr::Instance()->DeletePhone(phoneNum);
        return 0;
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return proto_ff::ERR_CODE_PHONE_AUTO_CODE_TIMEOUT;
}

int NFGetAccountTrans::ProGetAccountInfoReq(const proto_login::Proto_CSAccountLoginReq *pLoginReq)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(pLoginReq, -1, "pLoginReq = NULL");

	mAccount = pLoginReq->account();
	mPassword = pLoginReq->password();
	mLoginType = pLoginReq->login_type();
	mDeviecId = pLoginReq->device_id();

	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFGetAccountTrans::CreateAccountReq() {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	if (mLoginType == proto_ff::E_VISITOR || mLoginType == proto_ff::E_WECHAT)
	{
		SetState(CREATE_ACCOUNT);
		proto_ff::tbAccountTable accountInfo;
		accountInfo.set_account(mAccount.GetString());
		accountInfo.set_password(mPassword.GetString());
		accountInfo.set_account_type(mLoginType);
		accountInfo.set_device_id(mDeviecId.GetString());
		accountInfo.set_phonenum(0);

		NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Ready Create Account InTo Mysql:{}", accountInfo.DebugString());

		NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
			proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
			GetGlobalID(), 0, NFHash::hash<std::string>()(mAccount.GetString()));

	}
	else
	{
        return proto_ff::ERR_CODE_ACCOUNT_NOT_EXIST;
	}

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

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

    if (mCmd != proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ)
    {
        if (mAccount.GetString() != accountInfo.account() || mPassword.GetString() != accountInfo.password() ||
            accountInfo.player_id() <= 0) {
            NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Account:{} Password:{} is not right", mAccount.Get(), mPassword.Get());
            return proto_ff::ERR_CODE_ACCOUNT_PASSWORD_ERROR;
        }
    }

    if (accountInfo.real_player_id() > 0)
    {
        accountInfo.set_player_id(accountInfo.real_player_id());
    }

    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->CreateAccount(accountInfo.account(), accountInfo.password(), accountInfo.player_id(), accountInfo.account_type(), accountInfo.device_id(), accountInfo.phonenum());
    CHECK_NULL(pLogin);

    if (mCreateAccount)
    {
        proto_ff::Proto_LTWRegisterUserReq req;
        req.set_user_id(pLogin->mPlayerId);
        if (mLoginType == proto_ff::E_PHONE)
        {
            req.set_phone_num(NFCommon::strto<uint64_t>(mAccount.GetString()));
        }

        req.mutable_ext_data()->set_device_id(mDeviecId.GetString());
        NFMessageMgr::Instance()->SendTransToWorldServer(NF_ST_LOGIN_SERVER, proto_ff::NF_LTW_REGISTER_USER_TO_WORLD_REQ, req, GetGlobalID());
    }
    else {
        int iRetCode = HandleGetBaseInfoRes(pLogin);
        if (iRetCode) {
            return iRetCode;
        }
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    if (nMsgId == proto_ff::NF_LTL_REGISTER_USER_TO_LOGIN_RSP)
    {
        proto_ff::Proto_LTLRegisterUserRsp xMsg;
        CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);

        NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
        CHECK_NULL(pLogin);

        int iRetCode = HandleGetBaseInfoRes(pLogin);
        if (iRetCode) {
            return iRetCode;
        }
    }

    SetFinished(0);
    return 0;
}

int NFGetAccountTrans::ProBaseChangePassowrdRes(const storesvr_sqldata::storesvr_modobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Account Chang Password Failed, Account:{} Password:{}", mAccount.Get(), mPassword.Get());
        return proto_ff::ERR_CODE_SYSTEM_DATABASE_ERROR;
    }

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Account Change Password Success In Mysql, Account:{} Password:{}", mAccount.Get(), mPassword.Get());


    proto_login::Proto_SC_ChangePasswordRsp rspMsg;
    rspMsg.set_result(0);
    NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                         proto_login::NF_SC_MSG_CHANGE_PASSWORD_RESP,
                                                         rspMsg,
                                                         mClientLinkId);

    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance()->FindAccount(mAccount.GetString());
    if (!pLogin)
    {
        SetFinished(0);
        NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
        return 0;
    }

    pLogin->mDeviceId = mDeviecId;
    proto_ff::tbAccountTable accountInfo;
    accountInfo.set_account(pLogin->mAccount.GetString());
    accountInfo.set_device_id(mDeviecId.GetString());

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIN_SERVER,
                                                     proto_ff::E_STORESVR_C2S_MODIFYOBJ, proto_ff::E_TABLE_ACCOUNT_PLAYER, NF_DEFAULT_MYSQL_DB_NAME, "tbAccountTable", accountInfo,
                                                     0, 0, NFHash::hash<std::string>()(pLogin->mAccount.GetString()));


    SetFinished(0);

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGetAccountTrans::ProBaseCreateRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code != 0)
    {
        NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Create Account Failed In Mysql, Account:{} Password:{}", mAccount.Get(), mPassword.Get());
        return proto_ff::ERR_CODE_SYSTEM_DATABASE_ERROR;
    }

    mCreateAccount = true;


    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Create Account Success In Mysql, Account:{} Password:{}", mAccount.Get(), mPassword.Get());

    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return ProGetBaseInfoReq();
}

int NFGetAccountTrans::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                      uint32_t seq,
                                      uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ) {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER) {
            const storesvr_sqldata::storesvr_selobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProGetBaseInfoRes(pRes, cmd, table_id, err_code);
        }
    }
    else if (cmd == proto_ff::E_STORESVR_S2C_INSERT) {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER) {
            const storesvr_sqldata::storesvr_ins_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_ins_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProBaseCreateRes(pRes, cmd, table_id, err_code);
        }
    }
    else if(cmd == proto_ff::E_STORESVR_S2C_MODIFYOBJ)
    {
        if (table_id == proto_ff::E_TABLE_ACCOUNT_PLAYER) {
            const storesvr_sqldata::storesvr_modobj_res *pRes = dynamic_cast<const storesvr_sqldata::storesvr_modobj_res *>(pSSMsgRes);
            CHECK_EXPR(pRes, -1, "pRes == NULL");

            iRetCode = ProBaseChangePassowrdRes(pRes, cmd, table_id, err_code);
        }
    }
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

bool NFGetAccountTrans::IsTimeOut() {
    if (NFTime::Now().UnixSec() >= m_dwKeepAliveTime + 300) {
        NFLogError(NF_LOG_USER_MAIL_PLUGIN, 0, "This Trans TimeOut Type:{} Info:{}", GetClassType(), GetDebugInfo());
        OnTimeOut();
        return true;
    }

    return false;
}

int NFGetAccountTrans::OnTimeOut() {
    NFLogError(NF_LOG_USER_MAIL_PLUGIN, 0, "NFGetAccountTrans timeout account:{}", mAccount.GetString());
    return 0;
}

int NFGetAccountTrans::OnTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode != 0) {
        if (mCmd == proto_login::NF_CS_MSG_AccountLoginReq)
        {
            proto_login::Proto_SCAccountLoginRsp gcMsg;
            gcMsg.set_result(iRunLogicRetCode);

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                                 proto_login::NF_SC_MSG_AccountLoginRsp,
                                                                 gcMsg,
                                                                 mClientLinkId);
        }
        else if (mCmd == proto_login::NF_CS_MSG_CHANGE_PASSWORD_REQ)
        {
            proto_login::Proto_SC_ChangePasswordRsp gcMsg;
            gcMsg.set_result(iRunLogicRetCode);

            NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_LOGIN_SERVER, mProxyBusId,
                                                                 proto_login::NF_SC_MSG_CHANGE_PASSWORD_RESP,
                                                                 gcMsg,
                                                                 mClientLinkId);
        }
    }

    return 0;
}
