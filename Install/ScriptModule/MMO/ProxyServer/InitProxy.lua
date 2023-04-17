ProxyServer = { }

function ProxyServer.load_script_file()
	register_module(WorldServerModule, "WorldServerModule")
end

--加载所有的module
LuaNFrame.InsertLoadFunc(ProxyServer.load_script_file)