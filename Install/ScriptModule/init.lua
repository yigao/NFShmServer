
LuaNFrame = LuaNFrame or {}

--加载LUA文件， path为路径，subdir加载子目录，会一直递归
function LoadLuaFile(path, subdir)
	local sep = string.match (package.config, "[^\n]+")
	for file in lfs.dir(path) do
		if file ~= "." and file ~= ".." then
			local f = path..sep..file
			local attr = lfs.attributes(f)
			if attr.mode == "directory"  then
				if subdir == true then
					LoadLuaFile(f, subdir)
				end
			else
				if string.find(file, ".lua") ~= nil then
					dofile(f)
					print("load lua file:"..file)
				end
			end
		end
	end
end

function LuaNFrame.InitLoad()
	require("LuaNFrame/CPPNFrame")
	require("LuaNFrame/LuaNFrame")
	require("LuaNFrame/LuaProto")
	require("LuaNFrame/NFExtrend")
	require("LuaNFrame/NFLogDefine")
	require("LuaNFrame/ServerDefine")
	require("LuaNFrame/NFExecutor")
	require("LuaNFrame/NFReload")
	require("LuaNFrame/libprotobuf/protobuf")
	--require("LuaNFrame/NFTimeUtils")
end

function LuaNFrame.InitScript(luaModule)
	package.path = package.path .. ";../../ScriptModule/?.lua;"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/?.lua;"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/libprotobuf/?.lua"
	package.path = package.path .. ";../../ScriptModule/LuaNFrame/lua/?.lua"

	LuaNFrame.InitLoad()

	--初始化LuaNFrame
	LuaNFrame.init(luaModule)
	--初始化热更
	NFLuaReload.Init()

	if type(LuaNFrame.Platfrom) == 'function' then
		g_platfrom = LuaNFrame.Platfrom()    --from C++ always is 'win32' or 'linux'
	end

	if LuaNFrame.IsThreadModule() == false then
		if g_platfrom == "win32" then
			if  LuaNFrame.GetAppName() == "RebotServer" then
				breakSocketHandle,debugXpCall = require("LuaDebug")("localhost",7004)
			else
				breakSocketHandle,debugXpCall = require("LuaDebug")("localhost",7003)
			end

			LuaNFrame.AddTimer("update_debugsocket", 1)

		else
			--require("mobdebug").start("127.0.0.1", 8872);
			breakSocketHandle,debugXpCall = require("LuaDebug")("localhost",7004)
		end
	end

	local function timerExecute()
		if LuaNFrame.GetAppName() == "AllServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("GameServer/LoadHelper")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "GameServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("GameServer/LoadHelper")
			require("GameServer/GameTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "WorldServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("WorldServer/WorldLoadHelper")
			require("WorldServer/WorldTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "LoginServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("LoginServer/LoginLoadHelper")
			require("LoginServer/LoginTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "WebServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"
			
			require("WebServer/WebLoadHelper")
			require("WebServer/WebTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "LocationServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"
			
			require("LocationServer/LocationLoadHelper")
			require("LocationServer/LocationTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "LogServer" then
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"
			
			require("LogServer/LogLoadHelper")
			require("LogServer/LogTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			redisItem = redisConnect.new()
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		elseif LuaNFrame.GetAppName() == "RebotServer" then
			package.path = package.path .. ";../ScriptModule/RebotServer/?.lua;"
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("RebotServer/RebotLoadHelper")
			require("RebotServer/RebotTimerManager")
			require("GameServer/common/LoadProto")

			redisItem = redisConnect.new()
		elseif LuaNFrame.GetAppName() == "CheckServer" then
			package.path = package.path .. ";../ScriptModule/CheckServer/?.lua;"
			package.path = package.path .. ";../ScriptModule/GameServer/?.lua;"
			package.path = package.path..";../ScriptModule/GameServer/trdlib/libprotobuf/?.lua"   --由于这里protobuf的特殊性，必须把包含protobuf的目录加到环境变量中
			package.path = package.path..";../ScriptModule/GameServer/trdlib/lua/?.lua"

			require("CheckServer/CheckServerLoadHelper")
			require("CheckServer/CheckServerTimerManager")
			require("GameServer/common/LoadProto")

			mysqlItem = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
			mysqlLog = mysqlConnect.new(g_dbtype, g_dbUser, g_dbPassword, g_dbHost, g_dbPort, g_dbDatabase)
		end

		math.newrandomseed()
		require("LuaNFrame/NFTimeUtils")

		--记录所有文件的当前修改时间，为以后热更新做准备, 时间大概300ms
		NFLuaReload.RecordAllFilesTimes()

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