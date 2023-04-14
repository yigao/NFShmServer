WorldServerModule = {}
WorldServerModule.serverIdMap = {}
function WorldServerModule.Init()
    LuaNFrame.RegisterServerMessage(NF_ST_WORLD_SERVER,  "NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ",  WorldServerModule.HandleMsg, true)
    LuaNFrame.AddRpcService(NF_ST_WORLD_SERVER, "NF_RPC_SERVICE_GET_SERVER_INFO_REQ", "proto_ff.RpcRequestGetServerInfo", "proto_ff.ServerInfoReport", WorldServerModule.OnRpcServiceGetServerInfo)
end

function WorldServerModule.HandleMsg(msgId, packet, param1, param2)
    local xMsg = LuaNFrame.DecodePackage("proto_ff.Proto_TestOtherServerToWorldServer", packet)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "msgId:"..msgId.." packet:"..packet:ToString())

    if WorldServerModule.serverIdMap[xMsg.server_id] == nil then
        WorldServerModule.serverIdMap[xMsg.server_id] = xMsg.seq
    else
        if WorldServerModule.serverIdMap[xMsg.server_id] + 1 ~= xMsg.seq then
            LuaNFrame.Error(NF_LOG_SYSTEMLOG, 0, "serverId:{} serverName:{} last_seq:{} seq:{} Error", xMsg.server_id, xMsg.server_name, WorldServerModule.serverIdMap[xMsg.server_id] , xMsg.seq)
        end
        WorldServerModule.serverIdMap[xMsg.server_id] = xMsg.seq
    end

    LuaNFrame.Info(NF_LOG_SYSTEMLOG, 0, "{} serverId:{} serverName:{} last_seq:{} seq:{}",  pServerConfig, xMsg.server_id, xMsg.server_name, WorldServerModule.serverIdMap[xMsg.server_id] , xMsg.seq)
    local pServerConfig = LuaNFrame.GetAppConfig(NF_ST_WORLD_SERVER)

    local xData = LuaNFrame.Defaults("proto_ff.Proto_TestSendWorldMsgToOtherServer")
    xData.seq = xMsg.seq;
    xData.server_id = pServerConfig:GetServerId()
    xData.server_name = pServerConfig:GetServerName()
    LuaNFrame.SendMsgToLogicServer(NF_ST_WORLD_SERVER,  packet:GetSrcId(), 0,"NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ", "proto_ff.Proto_TestOtherServerToWorldServer", xData, 3, 4);

end

function WorldServerModule.OnRpcServiceGetServerInfo(request, respone)
    if request ~= nil then
        LuaNFrame.PrintProto(request)
    end

    if respone ~= nil then
        LuaNFrame.PrintProto(respone)
    end
end

function WorldServerModule.Execute()

end

function WorldServerModule.Shut()

end
