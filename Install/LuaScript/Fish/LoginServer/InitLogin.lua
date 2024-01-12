LoginServer = { }

function LoginServer.load_script_file()
	register_module(LoginPlayerModule, "LoginPlayerModule")
end

--加载所有的module
LuaNFrame.InsertLoadFunc(LoginServer.load_script_file)