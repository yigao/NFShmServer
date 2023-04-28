
LuaNFrame = LuaNFrame or {}

--加载LUA文件， path为路径，subdir加载子目录，会一直递归
function LoadLuaFile(path, subdir, subpath)
	local path_attr = lfs.attributes(path)
	if path_attr.mode == "directory" and subpath == nil then
		package.path = package.path .. ";"..path.."/?.lua;"
	end
	local sep = string.match (package.config, "[^\n]+")
	for file in lfs.dir(path) do
		if file ~= "." and file ~= ".." then
			local f = path..sep..file
			local attr = lfs.attributes(f)
			if attr.mode == "directory"  then
				local l_subpath = subpath
				if subdir == true then
					if l_subpath == nil then
						l_subpath = file
					else
						l_subpath = l_subpath..sep..file
					end
					LoadLuaFile(f, subdir, l_subpath)
				end
			else
				if string.find(file, ".lua") ~= nil then
					local temp_file = ""
					if subpath == nil then
						temp_file = file
					else
						temp_file = subpath..sep..file
					end
					local array = string.split(temp_file, ".lua")
					require(array[1])
					LuaNFrame.Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "load lua file:"..temp_file)
				end
			end
		end
	end
end

function LuaNFrame.InitLoad()
	require("LuaNFrame/CPPNFrame")
	require("LuaNFrame/LuaNFrame")
	require("LuaNFrame/LuaMessage")
	require("LuaNFrame/LuaEvent")
	require("LuaNFrame/LuaModule")
	require("LuaNFrame/LuaProto")
	require("LuaNFrame/NFExtrend")
	require("LuaNFrame/LuaLog")
	require("LuaNFrame/LuaTimer")
	require("LuaNFrame/ServerDefine")
	require("LuaNFrame/NFExecutor")
	require("LuaNFrame/NFReload")
	require("LuaNFrame/libprotobuf/protobuf")
	require("LuaNFrame/NFTimeUtils")
end

function LuaNFrame.InitScript(luaModule)
	package.path = package.path .. ";../../ScriptModule/?.lua;"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/?.lua;"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/libprotobuf/?.lua"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/lua/?.lua"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/luaprotobuf/?.lua"

	require("LuaPanda").start("127.0.0.1",8818)

	--初始化LuaNFrame
	LuaNFrame.InitLoad()
	LuaNFrame.LoadCPP(luaModule)
	--初始化热更
	NFLuaReload.Init()



	if type(LuaNFrame.Platform) == 'function' then
		g_platfrom = LuaNFrame.Platform()    --from C++ always is 'win32' or 'linux'
	end

	local function timerExecute()
		--LuaNFrame.SetLogLevel(NF_LOG_LEVEL_TRACE)
		--LuaNFrame.SetFlushOn(NF_LOG_LEVEL_TRACE)

		if LuaNFrame.GetAppName() == "AllServer" then
			LoadLuaFile("../../ScriptModule/MMO", true)
		else
			LoadLuaFile("../../ScriptModule/MMO/"..LuaNFrame.GetAppName(), true)
		end

		--记录所有文件的当前修改时间，为以后热更新做准备, 时间大概300ms
		NFLuaReload.RecordAllFilesTimes()

		--加载应用程序的Lua  Module
		LuaNFrame.load_script_file()
		LuaNFrame.LoadPbFile("../../ScriptModule/CommonProto/proto_server.proto.ds")
		LuaNFrame.AddTimerMSec(LuaNFrame.Execute,  100)

		--启动垃圾回收
		collectgarbage("setpause",100)
		--200 到 500 均可
		collectgarbage("setstepmul",500)
	end
	
	local status, msg = xpcall (timerExecute, __G__TRACKBACK__)

    if not status then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
	end
end

update_debugsocket = update_debugsocket or {}
function update_debugsocket.execute()
	if breakSocketHandle ~= nil then
		breakSocketHandle()
	end
end