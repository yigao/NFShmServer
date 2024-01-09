LoginPlayerModule = LoginPlayerModule or {}

function LoginPlayerModule.Init()
    LuaNFrame.AddRpcService(NF_ST_LOGIN_SERVER,  proto_ff.NF_CS_MSG_AccountLoginReq, proto_ff.Proto_CSAccountLoginReq, proto_ff.Proto_SCAccountLoginRsp, "LoginPlayerModule.OnRpcServiceAccountLogin")
end

function LoginPlayerModule.Execute()

end

function LoginPlayerModule.Shut()

end

function LoginPlayerModule.OnRpcServiceAccountLogin(request, respone)
    if request ~= nil then
        LuaNFrame.PrintProto(request)
    end

    if respone ~= nil then
        LuaNFrame.PrintProto(respone)
    end
end