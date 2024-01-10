LoginPlayerModule = LoginPlayerModule or {}

function LoginPlayerModule.Init()
    LuaNFrame.AddRpcService(NF_ST_LOGIN_SERVER,  proto_ff.NF_CS_MSG_AccountLoginReq, proto_ff.Proto_CSAccountLoginReq, proto_ff.Proto_SCAccountLoginRsp, "LoginPlayerModule.OnRpcServiceAccountLogin")
end

function LoginPlayerModule.Execute()

end

function LoginPlayerModule.Shut()

end

function LoginPlayerModule.OnRpcServiceAccountLogin(request, respone)
    local selectObj = proto_ff.tbFishAccountTable.New();
    selectObj.account = request.account
    local iRet = LuaNFrame.GetRpcSelectObjService(NF_ST_LOGIN_SERVER, 0, selectObj)
    if iRet ~= 0 then
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcSelectObjService Failed")
    end
    return iRet
end