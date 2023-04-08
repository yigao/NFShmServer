WorldServerModule = {}
WorldServerModule.serverIdMap = {}
function WorldServerModule.Init()
    LuaNFrame.RegisterServerMessage(NF_ST_WORLD_SERVER,  44,  WorldServerModule.HandleMsg)
end

function WorldServerModule.HandleMsg(msgId, packet, param1, param2)
    local xMsg = LuaNFrame.DecodePackage("proto_ff.Proto_TestOtherServerToWorldServer", packet)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "msgId:"..msgId.." packet:"..packet:ToString())

    if WorldServerModule.serverIdMap[xMsg.server_id] == nil then
        WorldServerModule.serverIdMap[xMsg.server_id] = xMsg.seq
    else
        if WorldServerModule.serverIdMap[xMsg.server_id] + 1 ~= xMsg.seq then
            --LuaNFrame.Error(NF_LOG_SYSTEMLOG, 0, "serverId:{} serverName:{} last_seq:{} seq:{} Error", xMsg.server_id, xMsg.server_name, WorldServerModule.serverIdMap[xMsg.server_id] , xMsg.seq)
            LuaNFrame.Error(NF_LOG_SYSTEMLOG, 0, "serverId"..xMsg.server_id.." serverName:"..xMsg.server_name.." last_seq:".. WorldServerModule.serverIdMap[xMsg.server_id].." seq:"..xMsg.seq)
        end
        WorldServerModule.serverIdMap[xMsg.server_id] = xMsg.seq
    end
    local xData = LuaNFrame.Defaults("proto_ff.Proto_TestSendWorldMsgToOtherServer")
    xData.seq = xMsg.seq;
    LuaNFrame.SendMsgToLogicServer(NF_ST_WORLD_SERVER,  packet:GetSrcId(), 0, LuaNFrame.Enum("proto_ff.Proto_SvrMsgID", "NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ"), xData, 3, 4);
end


function WorldServerModule.AfterInit()

end


function WorldServerModule.Execute()

end

function WorldServerModule.BeforeShut()

end

function WorldServerModule.Shut()

end
