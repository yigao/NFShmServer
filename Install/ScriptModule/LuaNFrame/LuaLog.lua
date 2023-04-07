NF_LOG_LEVEL_TRACE = 0 --    trace = 0,
NF_LOG_LEVEL_DEBUG = 1 --    debug = 1,
NF_LOG_LEVEL_INFO = 2  --    info = 2,
NF_LOG_LEVEL_WARN = 3  --    warn = 3,
NF_LOG_LEVEL_ERROR = 4 --    err = 4,


NFLogId = {
	--0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						--默认LOG
	NF_LOG_SYSTEMLOG = 1,					--系统LOG
	NF_LOG_ACTOR_PLUGIN = 2,				--Actor 引擎 
	NF_LOG_KERNEL_PLUGIN = 3,				--kernel 引擎
	NF_LOG_LUA_PLUGIN = 4,					--lua 引擎
	NF_LOG_MONGO_PLUGIN = 5,				--mongo 引擎
	NF_LOG_MONITOR_PLUGIN = 5,				--monitor 引擎
	NF_LOG_MYSQL_PLUGIN = 7,				--mysql 引擎
	NF_LOG_NET_PLUGIN = 8,					--net 引擎
	NF_LOG_SQLITE_PLUGIN = 9,				--sqlite 引擎
	NF_LOG_TEST_PLUGIN = 10,				--test 引擎


	NF_LOG_LOAD_CONFIG = 21,				--加载配置
	NF_LOG_PROTOBUF_PARSE = 22,				--protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 100,			--引擎加载器
	NF_LOG_MAX_SYSTEM_PLUGIN = 100,

	------------------------------------------------------------------------------------------
	NF_LOG_BEGIN_SERVER_LOG = 101,			--101-1000是系统框架层LOG

	NF_LOG_SERVER_CONNECT_SERVER = 101,		--服务器与服务器连接LOG
	NF_LOG_SERVER_NOT_HANDLE_MESSAGE = 102,		--服务器未处理消息的LOG

	NF_LOG_END_SERVER_LOG = 1000,			--

	-------------------------------------------------------------------------


	NF_LOG_BEGIN_LOGIC_LOG = 1001,			--1001以后是逻辑框架层
	NF_LOG_MAX_ID = 10240, --最大LOGID
}

--设置LOG等级
function LuaNFrame.SetLogLevel(level)
    CPPNFrame:SetLogLevel(level)
end

--设置LOG立马刷新等级
function LuaNFrame.SetFlushOn(level)
    CPPNFrame:SetFlushOn(level)
end


LuaNFrame.ErrorLogMsg = LuaNFrame.ErrorLogMsg or {}
function LuaNFrame.SendErrorLog(playerId, func_log, errorLog)
	LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, playerId,  func_log)
	LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, playerId, errorLog)

	local error_md5 = LuaNFrame.GetMD5(errorLog)
	if LuaNFrame.ErrorLogMsg[error_md5] == nil or type(LuaNFrame.ErrorLogMsg[error_md5]) ~= "number" then
		LuaNFrame.ErrorLogMsg[error_md5] = 1
		CPPNFrame:SendErrorLog(playerId, func_log, errorLog, 1)
	else
		LuaNFrame.ErrorLogMsg[error_md5] = LuaNFrame.ErrorLogMsg[error_md5] + 1
		local count = LuaNFrame.ErrorLogMsg[error_md5]
		if count == 10 or count == 30 or count == 50 then
			CPPNFrame:SendErrorLog(playerId, func_log, errorLog, count)
		elseif count % 50 == 0 then
			CPPNFrame:SendErrorLog(playerId, func_log, errorLog, count)
		end
	end
end

function LuaNFrame.Debug(logId, guid, ...)
	local cStackInfo = debug.getinfo(2, "Sl")
	if cStackInfo then
		CPPNFrame:Debug(logId, guid,"["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(...))
	else
		CPPNFrame:Debug(logId, guid, tostring(...))
	end
end

function LuaNFrame.Info(logId, guid, ...)
	local cStackInfo = debug.getinfo(2, "Sl")
	if cStackInfo then
		CPPNFrame:Info(logId, guid,"["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(...))
	else
		CPPNFrame:Info(logId, guid,tostring(...))
	end
end

function LuaNFrame.Warn(logId, guid, ...)
	local cStackInfo = debug.getinfo(2, "Sl")
	if cStackInfo then
		CPPNFrame:Warn(logId, guid,"["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(...))
	else
		CPPNFrame:Warn(logId, guid,tostring(...))
	end
end

function LuaNFrame.Error(logId, guid, ...)
	if type(guid) == nil then
		guid = 0
	elseif type(guid) == "number" then
		guid = tonumber(guid)
	end
	local cStackInfo = debug.getinfo(2, "Sl")
	if cStackInfo then
		CPPNFrame:Error(logId, guid, "["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(...))
	else
		CPPNFrame:Error(logId, guid, tostring(...))
	end
end