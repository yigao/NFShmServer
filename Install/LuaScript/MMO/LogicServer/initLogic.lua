LogicServer = { }

function LogicServer.load_script_file()
	register_module(LogicServerModule, "LogicServerModule")
end

--加载所有的module
LuaNFrame.InsertLoadFunc(LogicServer.load_script_file)
