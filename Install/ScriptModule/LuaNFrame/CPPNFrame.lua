
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
        --local info = debug.getinfo(luaFunc)
        --return info.short_src
        return "luaFunc"
    else
        return "NoLuaFunc"
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

function CPPNFrame:IsInited()
    return self.luaModule:IsInited()
end

function CPPNFrame:IsServerStopping()
    return self.luaModule:IsServerStopping()
end

function CPPNFrame:GetAppConfig(serverType)
    return self.luaModule:GetAppConfig(serverType)
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

function CPPNFrame:Trace(logId, guid, file, line, func, str)
	self.luaModule:LuaTrace(logId, guid, file, line, func, str)
end

function CPPNFrame:Debug(logId, guid, file, line, func, str)
	self.luaModule:LuaDebug(logId, guid, file, line, func, str)
end

function CPPNFrame:Info(logId, guid, file, line, func, str)
	self.luaModule:LuaInfo(logId, guid, file, line, func, str)
end

function CPPNFrame:Warn(logId, guid, file, line, func, str)
	self.luaModule:LuaWarn(logId, guid, file, line, func, str)
end

function CPPNFrame:Error(logId, guid, file, line, func, str)
    self.luaModule:LuaError(logId, guid, file, line, func, str)
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

function CPPNFrame:RegisterClientMessage(eServerType, nMsgID, luaFunc, createCo)
    return self.luaModule:RegisterClientMessage(eServerType, nMsgID, luaFunc, createCo)
end

function CPPNFrame:RegisterServerMessage(eServerType, nMsgID, luaFunc, createCo)
    return self.luaModule:RegisterServerMessage(eServerType, nMsgID, luaFunc, createCo)
end

function CPPNFrame:SendMsgToMasterServer(eServerType, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToMasterServer(eServerType, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, xData)
    return self.luaModule:SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, xData)
end

function CPPNFrame:SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendMsgToWorldServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToWorldServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendTransToWorldServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
    return self.luaModule:SendTransToWorldServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function CPPNFrame:SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendTransToGameServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
    return self.luaModule:SendTransToGameServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function CPPNFrame:SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendTransToLogicServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
    return self.luaModule:SendTransToLogicServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function CPPNFrame:SendMsgToSnsServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
    return self.luaModule:SendMsgToSnsServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function CPPNFrame:SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
    return self.luaModule:SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

----------------------------------------rpc service---------------------------------------------------------------------------------------------------------------
function CPPNFrame:AddRpcService(serverType, nMsgId, reqType, rspType, luaFunc, createCo)
    return self.luaModule:AddRpcService(serverType, nMsgId, reqType, rspType, luaFunc, createCo)
end

function CPPNFrame:GetRpcService(serverType, dstServerType, dstBusId, msgId, reqType, request, rspType)
    return self.luaModule:GetRpcService(serverType, dstServerType, dstBusId, msgId, reqType, request, rspType)
end


----------------------------------------rpc service---------------------------------------------------------------------------------------------------------------
----------------------------------------event system---------------------------------------------------------------------------------------------------------------
function CPPNFrame:FireCppExecute(serverType, nEventID, bySrcType, nSrcID, msgTypeName, msgData)
    return self.luaModule:FireCppExecute(serverType, nEventID, bySrcType, nSrcID, msgTypeName, msgData)
end

function CPPNFrame:FireExecute(serverType, nEventID, bySrcType, nSrcID, luaData)
    return self.luaModule:FireExecute(serverType, nEventID, bySrcType, nSrcID, luaData)
end

function CPPNFrame:Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc, luaFunc)
    return self.luaModule:Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc, luaFunc)
end
----------------------------------------event system---------------------------------------------------------------------------------------------------------------
function CPPNFrame:GetClientLinkId(serverType)
    return self.luaModule:GetClientLinkId(serverType)
end

function CPPNFrame:GetServerLinkId(serverType)
    return self.luaModule:GetServerLinkId(serverType)
end

--添加连接事件，掉线事件的处理函数
function  CPPNFrame:AddEventCallBack(serverType, linkId,  luaFunc, createCo)
    return self.luaModule:AddEventCallBack(serverType, linkId,  luaFunc, createCo)
end

--未没有注册过的消息，添加一个统一处理的回调函数
function  CPPNFrame:AddOtherCallBack(serverType, linkId, luaFunc, createCo)
    return self.luaModule:AddOtherCallBack(serverType, linkId, luaFunc, createCo)
end
 
--对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
function  CPPNFrame:AddAllMsgCallBack(serverType, luaFunc, createCo)
    return self.luaModule:AddAllMsgCallBack(serverType, luaFunc, createCo)
end