// -------------------------------------------------------------------------
//    @FileName         :    NFCAccountLoginModule.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFCAccountLoginModule
//
// -------------------------------------------------------------------------

#include "NFAccountLoginModule.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "NFAccountLoginMgr.h"
#include "DBProto.pb.h"
#include "proto_kernel.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFCore/NFTime.h"


NFCAccountLoginModule::NFCAccountLoginModule(NFIPluginManager *p) : NFIDynamicModule(p) {
}

NFCAccountLoginModule::~NFCAccountLoginModule() {
}

bool NFCAccountLoginModule::Awake()
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////来自客户端的协议////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_AccountLoginReq>(NF_ST_LOGIN_SERVER, this, &NFCAccountLoginModule::OnRpcServiceAccountLogin, true);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_RegisterAccountReq>(NF_ST_LOGIN_SERVER, this, &NFCAccountLoginModule::OnRpcServiceRegisterAccount, true);

    /////////来自Login Server返回的协议//////////////////////////////////////////////////
    /////来自World Server返回的协议////////////////////////////////////////
	return true;
}

bool NFCAccountLoginModule::Execute() {
    return true;
}

bool NFCAccountLoginModule::OnDynamicPlugin()
{
	return true;
}

int NFCAccountLoginModule::OnTimer(uint32_t nTimerID)
{
    return 0;
}

int NFCAccountLoginModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Proxy Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCAccountLoginModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
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

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCAccountLoginModule::OnRpcServiceAccountLogin(proto_ff::Proto_CSAccountLoginReq& request, proto_ff::Proto_SCAccountLoginRsp& respone)
{
    proto_ff::tbFishAccountTable selectobj;
    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance(m_pObjPluginManager)->FindAccount(request.account());
    if (pLogin == NULL)
    {
        selectobj.set_account(request.account());
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIN_SERVER, std::hash<std::string>()(request.account()), selectobj);
        if (iRet != 0)
        {
            if (iRet == proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
            {
                if (request.login_type() == proto_ff::E_VISITOR || request.login_type() == proto_ff::E_WECHAT)
                {
                    proto_ff::tbFishAccountTable insertObj;
                    insertObj.set_account(request.account());
                    insertObj.set_password(request.password());
                    insertObj.set_account_type(request.login_type());
                    insertObj.set_device_id(request.device_id());
                    insertObj.set_phonenum(0);

                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Ready Create Account InTo Mysql:{}", insertObj.DebugString());

                    iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_LOGIN_SERVER, std::hash<std::string>()(request.account()), insertObj);
                    if (iRet != 0)
                    {
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Failed, iRet:{}", request.account(), GetErrorStr(iRet));
                        respone.set_result(iRet);
                        return 0;
                    }

                    iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIN_SERVER, std::hash<std::string>()(request.account()), selectobj);
                    if (iRet != 0)
                    {
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Success, But Select Account Failed, iRet:{}", request.account(), GetErrorStr(iRet));
                        respone.set_result(iRet);
                        return 0;
                    }

                    pLogin = NFAccountLoginMgr::Instance(m_pObjPluginManager)->CreateAccount(selectobj.account(), selectobj.password(), selectobj.player_id(), selectobj.account_type(), selectobj.device_id(), selectobj.phonenum());
                    if (pLogin == NULL)
                    {
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFAccountLoginMgr CreateAccount:{} Failed", request.account());
                        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                        return 0;
                    }
                }
                else
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Account:{} is not exist, must first register, iRet:{}", request.account(), GetErrorStr(iRet));
                    respone.set_result(proto_ff::ERR_CODE_ACCOUNT_NOT_EXIST);
                    return 0;
                }
            }
            else {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Select Account:{} Failed, iRet:{}", request.account(), GetErrorStr(iRet));
                respone.set_result(iRet);
                return 0;
            }
        }
        else {
            pLogin = NFAccountLoginMgr::Instance(m_pObjPluginManager)->CreateAccount(selectobj.account(), selectobj.password(), selectobj.player_id(), selectobj.account_type(), selectobj.device_id(), selectobj.phonenum());
            if (pLogin == NULL)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFAccountLoginMgr CreateAccount:{} Failed", request.account());
                respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                return 0;
            }
        }
    }

    if (request.login_type() == proto_ff::E_ACCOUNT)
    {
        if (request.password() != pLogin->mPassword.ToString())
        {
            respone.set_result(proto_ff::ERR_CODE_ACCOUNT_PASSWORD_ERROR);
            return 0;
        }
    }

    pLogin->mLastLoginTime = NFTime::Now().UnixSec();

    respone.set_result(proto_ff::ERR_CODE_OK);
    respone.set_user_id(pLogin->mPlayerId);
    respone.set_login_time(pLogin->mLastLoginTime);
    respone.set_token(NFLogicCommon::GetLoginToken(pLogin->mAccount.GetString(), pLogin->mPlayerId, pLogin->mLastLoginTime, FISH_LOGIN_TOKEN));

    std::vector<NF_SHARE_PTR<NFServerData>> pServerList = FindModule<NFIMessageModule>()->GetServerByServerType(NF_ST_LOGIN_SERVER, NF_ST_PROXY_SERVER);
    for(int i = 0; i < (int)pServerList.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pServer = pServerList[i];
        if (pServer)
        {
            proto_ff::Proto_CSServerIP* pIp = respone.add_server_ip_list();
            pIp->set_ip(pServer->mServerInfo.external_server_ip());
            pIp->set_port(pServer->mServerInfo.external_server_port());
        }
    }

    return 0;
}

int NFCAccountLoginModule::OnRpcServiceRegisterAccount(proto_ff::Proto_CSRegisterAccountReq& request, proto_ff::Proto_SCRegisterAccountRsp& respone)
{
    NFAccountLogin* pLogin = NFAccountLoginMgr::Instance(m_pObjPluginManager)->FindAccount(request.account());
    if (pLogin == NULL)
    {
        proto_ff::tbFishAccountTable insertObj;
        insertObj.set_account(request.account());
        insertObj.set_password(request.password());
        insertObj.set_account_type(proto_ff::E_ACCOUNT);
        insertObj.set_device_id(request.device_id());
        insertObj.set_phonenum(0);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Ready Create Account InTo Mysql:{}", insertObj.DebugString());

        int iRet = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(NF_ST_LOGIN_SERVER, std::hash<std::string>()(request.account()), insertObj);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Failed, iRet:{}", request.account(), GetErrorStr(iRet));
            respone.set_result(iRet);
            return 0;
        }

        proto_ff::tbFishAccountTable selectobj;
        selectobj.set_account(request.account());
        iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIN_SERVER, std::hash<std::string>()(request.account()), selectobj);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Success, But Select Account Failed, iRet:{}", request.account(), GetErrorStr(iRet));
            respone.set_result(iRet);
            return 0;
        }

        pLogin = NFAccountLoginMgr::Instance(m_pObjPluginManager)->CreateAccount(selectobj.account(), selectobj.password(), selectobj.player_id(), selectobj.account_type(), selectobj.device_id(), selectobj.phonenum());
        if (pLogin == NULL)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFAccountLoginMgr CreateAccount:{} Failed", request.account());
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
            return 0;
        }
    }
    else {
        respone.set_result(proto_ff::ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_RESITER);
        return 0;
    }

    pLogin->mLastLoginTime = NFTime::Now().UnixSec();

    respone.set_result(proto_ff::ERR_CODE_OK);
    respone.set_user_id(pLogin->mPlayerId);
    respone.set_login_time(pLogin->mLastLoginTime);
    respone.set_token(NFLogicCommon::GetLoginToken(pLogin->mAccount.GetString(), pLogin->mPlayerId, pLogin->mLastLoginTime, FISH_LOGIN_TOKEN));

    std::vector<NF_SHARE_PTR<NFServerData>> pServerList = FindModule<NFIMessageModule>()->GetServerByServerType(NF_ST_LOGIN_SERVER, NF_ST_PROXY_SERVER);
    for(int i = 0; i < (int)pServerList.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pServer = pServerList[i];
        if (pServer)
        {
            proto_ff::Proto_CSServerIP* pIp = respone.add_server_ip_list();
            pIp->set_ip(pServer->mServerInfo.external_server_ip());
            pIp->set_port(pServer->mServerInfo.external_server_port());
        }
    }

    return 0;
}