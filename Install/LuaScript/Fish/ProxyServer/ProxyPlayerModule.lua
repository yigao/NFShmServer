ProxyPlayerModule = ProxyPlayerModule or {}

function ProxyPlayerModule.Init()
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  proto_ff.NF_CS_Msg_HeartBeat_REQ)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  proto_ff.NF_SC_Msg_HeartBeat_RSP)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  proto_ff.NF_SERVER_TO_SERVER_HEART_BEAT)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  proto_ff.NF_SERVER_TO_SERVER_HEART_BEAT_RSP)

    local proxyClientLinkId = LuaNFrame.GetClientLinkId(NF_ST_PROXY_SERVER)
    if proxyClientLinkId > 0 then
        LuaNFrame.AddEventCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId,  "ProxyPlayerModule.OnProxyClientSocketEvent")
        LuaNFrame.AddOtherCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId,  "ProxyPlayerModule.OnHandleProxyClientOtherMessage")
    end

    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_CS_MSG_AccountLoginReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_CS_MSG_RegisterAccountReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_CS_MSG_UserLoginReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_CS_Msg_HeartBeat_REQ, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_SERVER_TO_SERVER_HEART_BEAT, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  proto_ff.NF_CS_Msg_ReConnect_REQ, "ProxyPlayerModule.OnHandleClientMessage", true)
end

function ProxyPlayerModule.OnProxyClientSocketEvent(nEvent,  unLinkId)
    local ip = LuaNFrame.GetLinkIp(unLinkId)
    local port = LuaNFrame.GetPort(unLinkId)

    if nEvent == eMsgType_CONNECTED then
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} linkId:{} connected proxy server success!", ip, port, unLinkId)

        local pLinkInfo = NFProxySession.GetSession(unLinkId)
        if (pLinkInfo == nil) then
            pLinkInfo = NFProxySession.Create(unLinkId)
            pLinkInfo:SetLinkId(unLinkId)
            pLinkInfo:SetIpAddr(ip)
            pLinkInfo:SetPort(port)
            pLinkInfo:SetLastActiveTime(LuaNFrame.GetSecTime())
        end

    elseif nEvent == eMsgType_DISCONNECTED then
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "client ip:{} port:{} link:{} disconnected proxy server!", ip, port, unLinkId);
    end
end

function ProxyPlayerModule.OnHandleProxyClientOtherMessage(unLinkId, packet)
    local ip = LuaNFrame.GetLinkIp(unLinkId);

end

function ProxyPlayerModule.Execute()

end

function ProxyPlayerModule.Shut()

end

function ProxyPlayerModule.OnHandleClientMessage(msgId, packet, param1, param2)
    if (msgId == proto_ff.NF_SERVER_TO_SERVER_HEART_BEAT) then
        LuaNFrame.SendMsgByLinkId(packet:GetObjectLinkId(), proto_ff.NF_SERVER_TO_SERVER_HEART_BEAT_RSP,  "");
    elseif (msgId == proto_ff.NF_CS_Msg_HeartBeat_REQ) then
        ProxyPlayerModule.OnHandleClientHeartBeat(msgId, packet, param1, param2);
    elseif (msgId == proto_ff.NF_CS_MSG_AccountLoginReq) then
        ProxyPlayerModule.OnHandleAccountLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == proto_ff.NF_CS_MSG_RegisterAccountReq) then
        ProxyPlayerModule.OnHandleRegisterLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == proto_ff.NF_CS_MSG_UserLoginReq) then
        ProxyPlayerModule.OnHandlePlayerLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == proto_ff.NF_CS_Msg_ReConnect_REQ) then
        ProxyPlayerModule.OnHandlePlayerReconnectFromClient(msgId, packet, param1, param2);
    else
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", msgId, packet:ToString());
    end
    return 0;
end

function ProxyPlayerModule.OnHandleClientHeartBeat(msgId, packet, param1, param2)
end

function ProxyPlayerModule.OnHandleAccountLoginFromClient(msgId, packet, param1, param2)
    local cgMsg = proto_ff.Proto_CSAccountLoginReq.New(packet)
    local unLinkId = packet:GetObjectLinkId()
    local pLinkInfo = NFProxySession.GetSession(unLinkId);
    if (pLinkInfo == nil) then
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pLinkInfo == nil")
    end

    local pServerData = LuaNFrame.GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, cgMsg.account);
    if pServerData ~= nil then
        local loginId = pServerData:GetBusId()
        NFLogError(NF_LOG_SYSTEMLOG, 0, "loginId:{}", loginId)

        local respone = proto_ff.Proto_SCAccountLoginRsp.New()
        respone.result = proto_ff.ERR_CODE_SYSTEM_ERROR
        local iRet = LuaNFrame.GetRpcService(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER,  loginId, proto_ff.NF_CS_MSG_AccountLoginReq, cgMsg, respone);
        if (iRet ~= 0) then
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
            respone.result = proto_ff.ERR_CODE_SYSTEM_ERROR
            LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_AccountLoginRsp, respone);
            return 0;
        end

        pLinkInfo = NFProxySession.GetSession(unLinkId);
        if (pLinkInfo == nil) then
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "clientLinkId:{} not exist, client maybe disconnect!", unLinkId);
            return 0;
        end

        LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_AccountLoginRsp, respone);
    else
        respone.result = proto_ff.ERR_CODE_SYSTEM_ERROR
        LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_AccountLoginRsp, respone);

        NFLogError(NF_LOG_SYSTEMLOG, 0, "Get Login Server Bus Id Failed");
        ProxyPlayerModule.KickPlayer(unLinkId, 0);
    end
end

function ProxyPlayerModule.OnHandleRegisterLoginFromClient(msgId, packet, param1, param2)
    local cgMsg = proto_ff.Proto_CSRegisterAccountReq.New(packet);
    local unLinkId = packet:GetObjectLinkId()
    local pLinkInfo = NFProxySession.GetSession(unLinkId);
    if pLinkInfo == nil then
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pLinkInfo == nil")
        return
    end

    local ip = LuaNFrame.GetLinkIp(unLinkId);

    local pServerData = LuaNFrame.GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, cgMsg.account);
    if pServerData ~= nil then
        local loginId = pServerData:GetBusId()
        local respone = proto_ff.Proto_SCRegisterAccountRsp.New()
        local iRet = LuaNFrame.GetRpcService(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, loginId, proto_ff.NF_CS_MSG_RegisterAccountReq, cgMsg, respone)
        
        if (iRet ~= 0) then
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
            return 0;
        end

        pLinkInfo = NFProxySession.GetSession(unLinkId);
        if (pLinkInfo == nullptr) then
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "clientLinkId:{} not exist, client maybe disconnect!", unLinkId)
            return 0
        end

        LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_RegisterAccountRsp, respone)
    else
        ProxyPlayerModule.KickPlayer(unLinkId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Get Login Server Bus Id Failed");
    end
    return 0
end

function ProxyPlayerModule.OnHandlePlayerLoginFromClient(msgId, packet, param1, param2)
    local cgMsg = proto_ff.Proto_CSUserLoginReq.New(packet);
    local rspMsg = proto_ff.Proto_SCUserLoginRsp.New()

    local unLinkId = packet:GetObjectLinkId()
    local now = LuaNFrame.GetSecTime()
    if now - cgMsg.login_time >= 30 then
        rspMsg.result = proto_ff.ERR_CODE_TOKEN_TIMEOUT
        LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_UserLoginRsp, rspMsg)

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "account user:{} token timeout", cgMsg.account, cgMsg.user_id)
        return 0;
    end

    local token = LoginCommon.GetLoginToken(cgMsg.account, cgMsg.user_id, cgMsg.login_time)
    if cgMsg.token ~= token then
        rspMsg.result = proto_ff.ERR_CODE_TOKEN_ERROR
        LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_MSG_UserLoginRsp, rspMsg)
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "account user:{} token:{} error, real token:{}", cgMsg.account, cgMsg.user_id, cgMsg.token, token);
        return 0;
    end

    local pLinkInfo = NFProxySession.GetSession(unLinkId);
    if pLinkInfo == nil then
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "clientLinkId:{} not exist, client maybe disconnect!", unLinkId)
        return
    end

    local pPlayerInfo = NFProxyPlayerInfo.GetPlayerInfo(cgMsg.user_id)
    if pPlayerInfo == nil then
        pPlayerInfo = NFProxyPlayerInfo.Create(cgMsg.user_id)
        pPlayerInfo:SetLinkId(unLinkId);
        pPlayerInfo:SetIpAddr(pLinkInfo:GetIpAddr());
        pPlayerInfo:SetIsLogin(true);
        pPlayerInfo:SetPlayerId(cgMsg.user_id);
        pPlayerInfo:SetAccount(cgMsg.account);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create player:{} link:{}............", pPlayerInfo:GetPlayerId(), unLinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo:GetPlayerId(), unLinkId);
    else
        if pPlayerInfo:GetLinkId() > 0 and pPlayerInfo:GetLinkId() ~= unLinkId then
            local pOtherInfo = NFProxySession.GetSession(pPlayerInfo:GetLinkId())
            if pOtherInfo then
                ProxyPlayerModule.KickPlayer(pPlayerInfo:GetLinkId());
                pOtherInfo:SetPlayerId(0);
            end
        end

        pPlayerInfo:SetLinkId(unLinkId);
        pPlayerInfo:SetIpAddr(pLinkInfo:GetIpAddr());
        pPlayerInfo:SetIsLogin(true);
        pPlayerInfo:SetPlayerId(cgMsg.user_id);
        pPlayerInfo:SetAccount(cgMsg.account);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "new link, player:{} link:{}............", pPlayerInfo:GetPlayerId(), unLinkId);
    end
end

function ProxyPlayerModule.OnHandlePlayerReconnectFromClient(msgId, packet, param1, param2)
end

function ProxyPlayerModule.KickPlayer(unLinkId, reason)
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "kick linkId:{}", unLinkId);
    local kitMsg = proto_ff.Proto_SCKetPlayerNotify.New()
    kitMsg.result = reason
    LuaNFrame.SendMsgByLinkId(unLinkId, proto_ff.NF_SC_Msg_KitPlayer_Notify, kitMsg);
    LuaNFrame.CloseLinkId(unLinkId);
    return 0;
end