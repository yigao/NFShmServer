NF_LOG_LEVEL_TRACE = 0 --    trace = 0,
NF_LOG_LEVEL_DEBUG = 1 --    debug = 1,
NF_LOG_LEVEL_INFO = 2  --    info = 2,
NF_LOG_LEVEL_WARN = 3  --    warn = 3,
NF_LOG_LEVEL_ERROR = 4 --    err = 4,


NFLogId = {
	--0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						--默认LOG
	NF_LOG_SYSTEMLOG = 1,					--系统LOG
	NF_LOG_RECV_MSG = 3,					--接受消息
	NF_LOG_RECV_MSG_JSON_PRINTF = 4,		--接受消息Json输出
	NF_LOG_LOAD_CONFIG = 5;				--加载配置
	NF_LOG_PROTOBUF_PARSE = 6,				--protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 7,			--引擎加载器
	NF_LOG_MAX_ID = 100, --最大LOGID
}

	--0-100是基础框架层LOG
NF_LOG_DEFAULT = 0;						--默认LOG
NF_LOG_SYSTEMLOG = 1;					--系统LOG
NF_LOG_RECV_MSG = 3;					--接受消息
NF_LOG_RECV_MSG_JSON_PRINTF = 4;		--接受消息Json输出
NF_LOG_LOAD_CONFIG = 5;				--加载配置
NF_LOG_PROTOBUF_PARSE = 6;				--protobuf解析出错
NF_LOG_PLUGIN_MANAGER = 7;			--引擎加载器
NF_LOG_MAX_ID = 100; --最大LOGID

LuaNFrame.fmt = require "fmt"

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
	if playerId == nil then
		playerId = 0
	end
	if func_log == nil then
		func_log = ""
	end
	if errorLog == nil then
		errorLog = ""
	end
	LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, playerId, 3, func_log)
	LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, playerId, 3, errorLog)

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

function LuaNFrame.TraceWithThread(logId, guid, thread, ...)
	if LuaNFrame.IsDebug() then
		if type(logId) == nil then
			logId = NFLogId.NF_LOG_SYSTEMLOG
		elseif type(logId) ~= "number" then
			logId = tonumber(logId)
		end
		if type(guid) == nil then
			guid = 0
		elseif type(guid) ~= "number" then
			guid = tonumber(guid)
		end
		local cStackInfo = debug.getinfo(thread, "Sl")
		local cName = debug.getinfo(thread, "n")
		if cStackInfo ~= nil  and cStackInfo.short_src ~= nil and  cStackInfo.currentline ~= nil  then
			if cName ~= nil and cName.name ~= nil then
				CPPNFrame:Trace(logId, guid, cStackInfo.short_src, cStackInfo.currentline, cName.name, tostring(...))
			else
				CPPNFrame:Trace(logId, guid, cStackInfo.short_src, cStackInfo.currentline,  "NoLuaFunc", tostring(...))
			end
		else
			CPPNFrame:Trace(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
		end
	else
			CPPNFrame:Trace(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
	end
end

function LuaNFrame.DebugWithThread(logId, guid, thread, ...)
	if LuaNFrame.IsDebug() then
		if type(logId) == nil then
			logId = NFLogId.NF_LOG_SYSTEMLOG
		elseif type(logId) ~= "number" then
			logId = tonumber(logId)
		end
		if type(guid) == nil then
			guid = 0
		elseif type(guid) ~= "number" then
			guid = tonumber(guid)
		end
		local cStackInfo = debug.getinfo(thread, "Sl")
		local cName = debug.getinfo(thread, "n")
		if cStackInfo ~= nil  and cStackInfo.short_src ~= nil and  cStackInfo.currentline ~= nil  then
			if cName ~= nil and cName.name ~= nil then
				CPPNFrame:Debug(logId, guid, cStackInfo.short_src, cStackInfo.currentline, cName.name, tostring(...))
			else
				CPPNFrame:Debug(logId, guid, cStackInfo.short_src, cStackInfo.currentline,  "NoLuaFunc", tostring(...))
			end
		else
			CPPNFrame:Debug(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
		end
	else
			CPPNFrame:Debug(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
	end
end

function LuaNFrame.InfoWithThread(logId, guid, thread, ...)
	if LuaNFrame.IsDebug() then
		if type(logId) == nil then
			logId = NFLogId.NF_LOG_SYSTEMLOG
		elseif type(logId) ~= "number" then
			logId = tonumber(logId)
		end
		if type(guid) == nil then
			guid = 0
		elseif type(guid) ~= "number" then
			guid = tonumber(guid)
		end
		local cStackInfo = debug.getinfo(thread, "Sl")
		local cName = debug.getinfo(thread, "n")
		if cStackInfo ~= nil  and cStackInfo.short_src ~= nil and  cStackInfo.currentline ~= nil  then
			if cName ~= nil and cName.name ~= nil then
				CPPNFrame:Info(logId, guid, cStackInfo.short_src, cStackInfo.currentline, cName.name, tostring(...))
			else
				CPPNFrame:Info(logId, guid, cStackInfo.short_src, cStackInfo.currentline,  "NoLuaFunc", tostring(...))
			end
		else
			CPPNFrame:Info(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
		end
	else
			CPPNFrame:Info(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
	end
end

function LuaNFrame.WarnWithThread(logId, guid, thread, ...)
	if LuaNFrame.IsDebug() then
		if type(logId) == nil then
			logId = NFLogId.NF_LOG_SYSTEMLOG
		elseif type(logId) ~= "number" then
			logId = tonumber(logId)
		end
		if type(guid) == nil then
			guid = 0
		elseif type(guid) ~= "number" then
			guid = tonumber(guid)
		end
		local cStackInfo = debug.getinfo(thread, "Sl")
		local cName = debug.getinfo(thread, "n")
		if cStackInfo ~= nil  and cStackInfo.short_src ~= nil and  cStackInfo.currentline ~= nil  then
			if cName ~= nil and cName.name ~= nil then
				CPPNFrame:Warn(logId, guid, cStackInfo.short_src, cStackInfo.currentline, cName.name, tostring(...))
			else
				CPPNFrame:Warn(logId, guid, cStackInfo.short_src, cStackInfo.currentline,  "NoLuaFunc", tostring(...))
			end
		else
			CPPNFrame:Warn(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
		end
	else
			CPPNFrame:Warn(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
	end
end

function LuaNFrame.ErrorWithThread(logId, guid, thread, ...)
	if LuaNFrame.IsDebug() then
		if type(logId) == nil then
			logId = NFLogId.NF_LOG_SYSTEMLOG
		elseif type(logId) ~= "number" then
			logId = tonumber(logId)
		end
		if type(guid) == nil then
			guid = 0
		elseif type(guid) ~= "number" then
			guid = tonumber(guid)
		end
		local cStackInfo = debug.getinfo(thread, "Sl")
		local cName = debug.getinfo(thread, "n")
		if cStackInfo ~= nil  and cStackInfo.short_src ~= nil and  cStackInfo.currentline ~= nil  then
			if cName ~= nil and cName.name ~= nil then
				CPPNFrame:Error(logId, guid, cStackInfo.short_src, cStackInfo.currentline, cName.name, tostring(...))
			else
				CPPNFrame:Error(logId, guid, cStackInfo.short_src, cStackInfo.currentline,  "NoLuaFunc", tostring(...))
			end
		else
			CPPNFrame:Error(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
		end
	else
			CPPNFrame:Error(logId, guid, "NoLuaFile", 0, "NoLuaFunc", tostring(...))
	end
end

function LuaNFrame.Trace(logId, guid, ...)
	LuaNFrame.TraceWithThread(logId, guid, 3, LuaNFrame.fmt(...))
end

function LuaNFrame.Debug(logId, guid, ...)
	LuaNFrame.DebugWithThread(logId, guid, 3, LuaNFrame.fmt(...))
end

function LuaNFrame.Info(logId, guid, ...)
	LuaNFrame.InfoWithThread(logId, guid, 3, LuaNFrame.fmt(...))
end

function LuaNFrame:Warn(logId, guid, ...)
	LuaNFrame.WarnWithThread(logId, guid, 3, LuaNFrame.fmt(...))
end

function LuaNFrame.Error(logId, guid, ...)
	LuaNFrame.ErrorWithThread(logId, guid, 3, LuaNFrame.fmt(...))
end