ProxyPlayerModule = {}

function ProxyPlayerModule.Init()
    --LuaNFrame.RegisterServerMessage(NF_ST_LOGIC_SERVER,  "NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ",  LogicServerModule.HandleMsg, true)
    local linkId = LuaNFrame.GetServerLinkId(NF_ST_PROXY_SERVER)
    if linkId > 0 then
        LuaNFrame.AddEventCallBack(NF_ST_PROXY_SERVER, linkId,  ProxyPlayerModule.OnHandleSocketEvent)
    end
end

function ProxyPlayerModule.OnHandleSocketEvent(nEvent,  linkId)
    if nEvent == eMsgType_CONNECTED then

    elseif nEvent == eMsgType_DISCONNECTED then

    end
end


function ProxyPlayerModule.Execute()

end

function ProxyPlayerModule.Shut()

end
