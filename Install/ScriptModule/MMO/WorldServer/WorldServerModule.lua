WorldServerModule = {}

function WorldServerModule.Init()
    LuaNFrame.RegisterServerMessage(NF_ST_WORLD_SERVER,  44,  WorldServerModule.HandleMsg)
end

function WorldServerModule.HandleMsg(msgId, packet, param1, param2)
    LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "msgId:"..msgId.." packet:"..packet:ToString())
end


function WorldServerModule.AfterInit()

end


function WorldServerModule.Execute()

end

function WorldServerModule.BeforeShut()

end

function WorldServerModule.Shut()

end
