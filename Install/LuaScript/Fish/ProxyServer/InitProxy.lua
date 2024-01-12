ProxyServer = { }

function ProxyServer.load_script_file()
	register_module(ProxyPlayerModule, "ProxyPlayerModule")
end

--加载所有的module
LuaNFrame.InsertLoadFunc(ProxyServer.load_script_file)