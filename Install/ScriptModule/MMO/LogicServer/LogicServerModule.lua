LogicServerModule = {}
LogicServerModule.serverIdMap = {}
function LogicServerModule.Init()
    LuaNFrame.RegisterServerMessage(NF_ST_LOGIC_SERVER,  "NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ",  "LogicServerModule.HandleMsg", true)
    LuaNFrame.AddTimer("LogicServerModule.UpdateMsg",  10)
end

LogicServerModule.cur_seq = 0 
function LogicServerModule.UpdateMsg(nTimerId, callCount)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0,  "nTimerId:{} callCount:{}", nTimerId, callCount)
    local pServerConfig = LuaNFrame.GetAppConfig(NF_ST_LOGIC_SERVER)
    local xData = LuaNFrame.Defaults("proto_ff.Proto_TestOtherServerToWorldServer")
    xData.server_id = pServerConfig:GetServerId()
    xData.server_name = pServerConfig:GetServerName()
    LogicServerModule.cur_seq = LogicServerModule.cur_seq + 1
    xData.seq = LogicServerModule.cur_seq;
    LuaNFrame.SendMsgToWorldServer(NF_ST_LOGIC_SERVER, 0, "NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ", "proto_ff.Proto_TestOtherServerToWorldServer", xData,
                                                               1, 2);

end

LogicServerModule.last_seq =  -1
function LogicServerModule.HandleMsg(msgId, packet, param1, param2)
    local xMsg = LuaNFrame.DecodePackage("proto_ff.Proto_TestSendWorldMsgToOtherServer", packet)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "msgId:"..msgId.." packet:"..packet:ToString())

    if LogicServerModule.last_seq  < 0 then
        LogicServerModule.last_seq  = xMsg.seq;
    else
        if LogicServerModule.last_seq + 1 ~= xMsg.seq then
            LuaNFrame.Error(NF_LOG_SYSTEMLOG, 0, "world server send seq error, last_seq:{} seq:{}", LogicServerModule.last_seq, xMsg.seq);
        end
        LogicServerModule.last_seq = xMsg.seq
    end

    local pServerConfig = LuaNFrame.GetAppConfig(NF_ST_LOGIC_SERVER)
    local request = LuaNFrame.Defaults("proto_ff.RpcRequestGetServerInfo")
    request.server_id = pServerConfig:GetServerId()

    local respone = LuaNFrame.GetRpcService(NF_ST_LOGIC_SERVER, NF_ST_WORLD_SERVER,  0, "NF_RPC_SERVICE_GET_SERVER_INFO_REQ",  "proto_ff.RpcRequestGetServerInfo", request,  "proto_ff.ServerInfoReport")
   if respone ~= nil then
        LuaNFrame.PrintProto(respone)
   end
end

function LogicServerModule.Execute()

end

function LogicServerModule.Shut()

end
