ProxyPlayerModule = {}

function ProxyPlayerModule.Init()
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_CS_Msg_HeartBeat_REQ)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SC_Msg_HeartBeat_RSP)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SERVER_TO_SERVER_HEART_BEAT)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SERVER_TO_SERVER_HEART_BEAT_RSP)

    local proxyClientLinkId = LuaNFrame.GetClientLinkId(NF_ST_PROXY_SERVER)
    if proxyClientLinkId > 0 then
        LuaNFrame.AddEventCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId,  "ProxyPlayerModule.OnProxyClientSocketEvent")
        LuaNFrame.AddOtherCallBack(NF_ST_PROXY_SERVER, proxyClientLinkId,  "ProxyPlayerModule.OnHandleProxyClientOtherMessage")
    end

    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_CS_MSG_AccountLoginReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_CS_MSG_RegisterAccountReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_CS_MSG_UserLoginReq, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_CS_Msg_HeartBeat_REQ, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_SERVER_TO_SERVER_HEART_BEAT, "ProxyPlayerModule.OnHandleClientMessage", true)
    LuaNFrame.RegisterClientMessage(NF_ST_PROXY_SERVER,  NF_CS_Msg_ReConnect_REQ, "ProxyPlayerModule.OnHandleClientMessage", true)
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
    if (msgId == NF_SERVER_TO_SERVER_HEART_BEAT) then
        LuaNFrame.SendMsgByLinkId(packet:GetObjectLinkId(), NF_SERVER_TO_SERVER_HEART_BEAT_RSP,  "");
    elseif (msgId == NF_CS_Msg_HeartBeat_REQ) then
        ProxyPlayerModule.OnHandleClientHeartBeat(msgId, packet, param1, param2);
    elseif (msgId == NF_CS_MSG_AccountLoginReq) then
        ProxyPlayerModule.OnHandleAccountLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == NF_CS_MSG_RegisterAccountReq) then
        ProxyPlayerModule.OnHandleRegisterLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == NF_CS_MSG_UserLoginReq) then
        ProxyPlayerModule.OnHandlePlayerLoginFromClient(msgId, packet, param1, param2);
    elseif (msgId == NF_CS_Msg_ReConnect_REQ) then
        ProxyPlayerModule.OnHandlePlayerReconnectFromClient(msgId, packet, param1, param2);
    else
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", msgId, packet:ToString());
    end
    return 0;
end

function ProxyPlayerModule.OnHandleClientHeartBeat(msgId, packet, param1, param2)
end

function ProxyPlayerModule.OnHandleAccountLoginFromClient(msgId, packet, param1, param2)
    local cgMsg = LuaNFrame.DecodePackage("proto_ff.Proto_CSAccountLoginReq", packet)
    local unLinkId = packet:GetObjectLinkId()
    local pLinkInfo = NFProxySession.GetSession(unLinkId);
    if (pLinkInfo == nil) then
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pLinkInfo == nil")
    end

    local ip = LuaNFrame.GetLinkIp(unLinkId)
    local pServerData = LuaNFrame.GetSuitServerByServerType(NF_ST_PROXY_SERVER, NF_ST_LOGIN_SERVER, cgMsg.account);
    if pServerData ~= nil then
        local loginId = pServerData:GetBusId()
        NFLogError(NF_LOG_SYSTEMLOG, 0, "loginId:{}", loginId)
    end
end

function ProxyPlayerModule.OnHandleRegisterLoginFromClient(msgId, packet, param1, param2)
end

function ProxyPlayerModule.OnHandlePlayerLoginFromClient(msgId, packet, param1, param2)
end

function ProxyPlayerModule.OnHandlePlayerReconnectFromClient(msgId, packet, param1, param2)
end