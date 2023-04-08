
CPPNFrame = CPPNFrame or {}

function __G__TRACKBACK__(msg)
    if CPPNFrame:IsDebug() then
        local traceback = string.split(debug.traceback("", 2), "\n")
        string.trim(traceback[3])
        
        local trace = debug.traceback()
        local logData = "LUA_ERROR:"..string.trim(traceback[3]).."\n"..tostring(msg).."\n".."trace msg:"..trace.."\n"
        
        return logData
    else
        return tostring(msg)
    end
end

function __G__FUNCTION__(luaFunc)
    if CPPNFrame:IsDebug() then
        return ""
    else
        return ""
    end
end

function CPPNFrame:init(luaModule)

    if luaModule == nil then
        self:error("初始化失败。。。。。。。。。")
    end
    self.luaModule = luaModule
    self.app_name = luaModule:GetAppName()
    self.app_id = luaModule:GetAppID()
    self.app_dir = self.app_name
end

function CPPNFrame:GetAppName()
    return self.app_name
end

function CPPNFrame:GetAppID()
    return self.app_id
end

function CPPNFrame:IsDebug()
    return self.luaModule:IsDebug()
end

--添加服务器定时器, 返回定时器ID
function CPPNFrame:AddTimer(luaFunc, nInterVal, nCallCount, dataStr)
    return self.luaModule:AddTimer(luaFunc, nInterVal, nCallCount, dataStr)
end

--停止服务器定时器
function CPPNFrame:StopTimer(timerId)
    self.luaModule:StopTimer(timerId)
end

function CPPNFrame:AddClocker(luaFunc, startSec, intervalSec, nCallCount, dataStr)
    return self.luaModule:AddClocker(luaFunc, startSec, intervalSec, nCallCount, dataStr)
end

function CPPNFrame:StopClocker(timerId)
    return self.luaModule:StopClocker(timerId)
end

--创建全局唯一的UUID
function CPPNFrame:GetUUID()
    return self.luaModule:GetUUID()
end

--通过字符串获得MD5, 返回MD5字符串
function CPPNFrame:GetMD5(str)
    return self.luaModule:GetMD5(str)
end

--通过字符串获得对应的CRC32, 返回数字
function CPPNFrame:GetCRC32(str)
    return self.luaModule:GetCRC32(str)
end

--通过字符串获得对应的CRC16, 返回数字
function CPPNFrame:GetCRC16(str)
    return self.luaModule:GetCRC16(str)
end

--通过字符串获得对应的Base64Encode, 返回字符串
function CPPNFrame:Base64Encode(str)
    return self.luaModule:Base64Encode(str)
end

--通过字符串获得对应的Base64Decode, 返回字符串
function CPPNFrame:Base64Decode(str)
    return self.luaModule:Base64Decode(str)
end

--获得服务器开启时间，单位ms
function CPPNFrame:GetInitTime()
    return self.luaModule:GetInitTime()
end

--获得服务器当前时间，单位ms, 服务器主循环loop里更新， 在同一个循环里时间是一样的
function CPPNFrame:GetNowTime()
    return self.luaModule:GetNowTime()
end

--获得服务器当前时间，单位ms
function CPPNFrame:GetMsecTime()
    return self.luaModule:GetMsecTime()
end

--获得服务器当前时间，单位s
function CPPNFrame:GetSecTime()
    return self.luaModule:GetSecTime()
end

--设置LOG等级
function CPPNFrame:SetLogLevel(level)
    self.luaModule:SetLogLevel(level)
end

--设置LOG立马刷新等级
function CPPNFrame:SetFlushOn(level)
    self.luaModule:SetFlushOn(level)
end

function CPPNFrame:Debug(logId, guid, str)
	self.luaModule:LuaDebug(logId, guid, str)
end

function CPPNFrame:Info(logId, guid, str)
	self.luaModule:LuaInfo(logId, guid, str)
end

function CPPNFrame:Warn(logId, guid, str)
	self.luaModule:LuaWarn(logId, guid, str)
end

function CPPNFrame:Error(logId, guid, str)
    self.luaModule:LuaError(logId, guid, str)
end

function CPPNFrame:BeginProfiler(name)
    self.luaModule:BeginProfiler(name)
end

function CPPNFrame:EndProfiler()
    self.luaModule:EndProfiler()
end

function CPPNFrame:Sha256(str)
    return self.luaModule:Sha256(str)
end

function CPPNFrame:Platform()
    return self.luaModule:Platform()
end

function CPPNFrame:IsThreadModule()
    return self.luaModule:IsThreadModule()
end

function CPPNFrame:SendErrorLog(playerId, func_log, errorLog, count)
    return self.luaModule:SendErrorLog(playerId, func_log, errorLog, count)
end

function CPPNFrame:RegisterClientMessage(eServerType, nMsgID, luaFunc)
    return self.luaModule:RegisterClientMessage(eServerType, nMsgID, luaFunc)
end

function CPPNFrame:RegisterServerMessage(eServerType, nMsgID, luaFunc)
    return self.luaModule:RegisterServerMessage(eServerType, nMsgID, luaFunc)
end


