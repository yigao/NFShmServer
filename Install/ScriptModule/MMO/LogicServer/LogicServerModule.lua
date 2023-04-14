LogicServerModule = {}
LogicServerModule.serverIdMap = {}
function LogicServerModule.Init()
    --LuaNFrame.RegisterServerMessage(NF_ST_LOGIC_SERVER,  "NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ",  LogicServerModule.HandleMsg, true)
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

    local request = LuaNFrame.Defaults("proto_ff.RpcRequestGetServerInfo")

    --local respone = LuaNFrame.GetRpcService(NF_ST_LOGIC_SERVER, NF_ST_WORLD_SERVER,  0, "NF_RPC_SERVICE_GET_SERVER_INFO_REQ",  "proto_ff.RpcRequestGetServerInfo", request,  "proto_ff.ServerInfoReport")
    --if respone ~= nil then
    --    LuaNFrame.PrintProto(respone)
    --end
end

function LogicServerModule.Execute()

end

function LogicServerModule.Shut()

end
