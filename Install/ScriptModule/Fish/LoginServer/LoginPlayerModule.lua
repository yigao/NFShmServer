LoginPlayerModule = LoginPlayerModule or {}

function LoginPlayerModule.Init()
    LuaNFrame.AddRpcService(NF_ST_LOGIN_SERVER,  proto_ff.NF_CS_MSG_AccountLoginReq, proto_ff.Proto_CSAccountLoginReq, proto_ff.Proto_SCAccountLoginRsp, "LoginPlayerModule.OnRpcServiceAccountLogin")
    LuaNFrame.AddTimer("NFAccountLogin.Tick", 1)
end

function LoginPlayerModule.Execute()

end

function LoginPlayerModule.Shut()

end

function LoginPlayerModule.OnRpcServiceAccountLogin(request, respone)
    local selectobj = proto_ff.tbFishAccountTable.New();
    local pLogin = NFAccountLogin.FindAccount(request.account)
	if (pLogin == nil) then
        selectobj.account = request.account
        local iRet = LuaNFrame.GetRpcSelectObjService(NF_ST_LOGIN_SERVER, 0, selectobj)
        if iRet ~= 0 or iRet == nil then
            if iRet == proto_ff.ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY then
                if (request.login_type == proto_ff.E_VISITOR or request.login_type == proto_ff.E_ACCOUNT or request.login_type == proto_ff.E_WECHAT) then
                    local insertObj = proto_ff.tbFishAccountTable.New()
                    insertObj.account = request.account
                    insertObj.password = request.password
                    insertObj.account_type = request.login_type
                    insertObj.device_id = request.device_id
                    insertObj.phonenum = 0
    
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Ready Create Account InTo Mysql:{}", insertObj:DebugString());
    
                    iRet = LuaNFrame.GetRpcInsertObjService(NF_ST_LOGIN_SERVER,0, selectobj);
                    if (iRet ~= 0) then
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Failed, iRet:{}", request.account, GetErrorStr(iRet));
                        respone.result = iRet;
                        return 0;
                    end
    
                    iRet = LuaNFrame.GetRpcSelectObjService(NF_ST_LOGIN_SERVER, 0, selectobj);
                    if (iRet ~= 0) then
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Insert Account:{} Success, But Select Account Failed, iRet:{}", request.account, GetErrorStr(iRet))
                        respone.result = iRet
                        return 0
                    end
    
                    pLogin = NFAccountLogin.CreateAccount(selectobj.account, selectobj.password,
                                                                                             selectobj.player_id, selectobj.account_type,
                                                                                             selectobj.device_id, selectobj.phonenum);
                    if (pLogin == nil) then
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFAccountLoginMgr CreateAccount:{} Failed", request.account);
                        respone.result = proto_ff.ERR_CODE_SYSTEM_ERROR
                        return 0
                    end
                else
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Account:{} is not exist, must first register, iRet:{}", request.account, GetErrorStr(iRet));
                    respone.result = proto_ff.ERR_CODE_ACCOUNT_NOT_EXIST
                    return 0
                end
            else
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Select Account:{} Failed, iRet:{}", request.account, GetErrorStr(iRet));
				respone.result = iRet
				return 0
            end
        else
            pLogin = NFAccountLogin.CreateAccount(selectobj.account, selectobj.password, selectobj.player_id,
																					 selectobj.account_type, selectobj.device_id,
																					 selectobj.phonenum);
			if (pLogin == nil) then
				NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFAccountLoginMgr CreateAccount:{} Failed", request.account);
				respone.result = proto_ff.ERR_CODE_SYSTEM_ERROR;
				return 0
            end
        end
    end


	if request.login_type == proto_ff.E_ACCOUNT then
		if request.password ~= pLogin.mPassword then
			respone.result = proto_ff.ERR_CODE_ACCOUNT_PASSWORD_ERROR
			return 0
        end
    end

    pLogin.mLastLoginTime = LuaNFrame.GetSecTime();

	respone.result = proto_ff.ERR_CODE_OK;
	respone.user_id = pLogin.mPlayerId;
	respone.login_time = pLogin.mLastLoginTime;
	respone.token = LoginCommon.GetLoginToken(pLogin.mAccount, pLogin.mPlayerId, pLogin.mLastLoginTime)

	local serverList = LuaNFrame.GetServerByServerType(NF_ST_LOGIN_SERVER, NF_ST_PROXY_SERVER);
    respone.server_ip_list = respone.server_ip_list or {}
	for i, server in ipairs(serverList) do
        local ipPort = proto_ff.Proto_CSServerIP.New()
        ipPort.ip = server:GetExternalServerIp();
        ipPort.port = server:GetExternalServerPort();
        table.insert(respone.server_ip_list, ipPort)
    end

    return 0
end