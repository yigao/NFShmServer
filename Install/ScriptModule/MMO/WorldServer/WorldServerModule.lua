WorldServerModule = {}

function WorldServerModule.Init()
end

function WorldServerModule.WorldServerNetEvent(nEvent, unLinkId, serverData)
    local cmd = {}
    if nEvent == NF_MSG_TYPE.eMsgType_CONNECTED then
        Zone.zone_connect(cmd, serverData)
    end
    if nEvent == NF_MSG_TYPE.eMsgType_DISCONNECTED then
        Zone.zone_disconnect(cmd, serverData)
    end
end

--特殊协议
function WorldServerModule.GameRecvHandleJson(unLinkId, valueId, nMsgId, strMsg)
    local table_msg = json2table(strMsg)
    if type(table_msg["do"]) == "string" then
        if table_msg["do"] == "Cmd.UserUpdate_C" then
        else
            unilight.debug(tostring(valueId) .. " | recv game msg |" .. strMsg)
        end
    end
    --协议规则
    if table_msg ~= nil then
        local cmd = table_msg["do"]
        if type(cmd) == "string" then
            local i, j = string.find(cmd, "Cmd.")
            local strcmd = string.sub(cmd, j+1, -1)
            if strcmd ~= "" then
                strcmd = "Cmd" .. strcmd
                if type(Zone[strcmd]) == "function" then
                    local zonetask = ZoneInfo.ZoneLinkTaskMap[unLinkId]
                    if zonetask ~= nil then
                        Zone[strcmd](table_msg, zonetask)
                    end
                end
            end
        end
    end
    -- body
end

function WorldServerModule.AfterInit()

end


function WorldServerModule.Execute()

end

function WorldServerModule.BeforeShut()

end

function WorldServerModule.Shut()

end
