ProxyPlayerModule = {}

function ProxyPlayerModule.Init()
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_CS_Msg_HeartBeat_REQ)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SC_Msg_HeartBeat_RSP)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SERVER_TO_SERVER_HEART_BEAT)
    LuaNFrame.RegisterSpecialMsg(NF_MODULE_CLIENT,  NF_SERVER_TO_SERVER_HEART_BEAT_RSP)

    local proxyClientLinkId = LuaNFrame.GetClientLinkId(NF_ST_PROXY_SERVER)
    if proxyClientLinkId > 0 then
        LuaNFrame.AddEventCallBack(NF_ST_PROXY_SERVER, linkId,  "ProxyPlayerModule.OnProxyClientSocketEvent")
        LuaNFrame.AddOtherCallBack(NF_ST_PROXY_SERVER, linkId,  "ProxyPlayerModule.OnHandleProxyClientOtherMessage")
    end
end

function ProxyPlayerModule.OnProxyClientSocketEvent(nEvent,  linkId)
    if nEvent == eMsgType_CONNECTED then

    elseif nEvent == eMsgType_DISCONNECTED then

    end
end

function ProxyPlayerModule.OnHandleProxyClientOtherMessage(unLinkId, packet)

end

function ProxyPlayerModule.Execute()

end

function ProxyPlayerModule.Shut()

end
