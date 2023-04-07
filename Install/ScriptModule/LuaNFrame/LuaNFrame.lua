uaNFrame = LuaNFrame or {}

--用来存放加载函数
LuaNFrame.LoadScriptList = { }

function LuaNFrame.GetAppName()
    return CPPNFrame:GetAppName()
end

function LuaNFrame.GetAppID()
    return CPPNFrame:GetAppID()
end

function LuaNFrame.LoadCPP(luaModule)

	CPPNFrame:init(luaModule)
	--用来存放加载的module
	LuaNFrame.ScriptList = { }

end

--执行函数, 函数被字符串表达出来
--比如说，要执行LoginModule.Init函数，
--LuaNFrame.RunStringFunction("LoginModule.Init")
function LuaNFrame.RunStringFunction(strFunction,...)
    local v = _G;
    for w in string.gmatch(strFunction,"[%[%]%w_\"]+") do
      local index = string.find(w, "%[");
      if index == nil then
          v = v[w]
          if v == nil then
            break
          end
      else
          local key = string.match(w, "([%w_]+)%[")
          if key == nil then
              return;
          else
              v = v[key]
              for val in string.gmatch(w, "%[[\"%w_]+%]") do
                  local value = string.match(val, "%[([\"%w_]+)%]")
                  local value_str = string.match(value,"\"([%w_]+)\"");
                  if value_str ~= nil then
                      v = v[value_str];
                  else
                      local value_num = tonumber(value);
                      if value_num ~= nil then
                          v = v[value_num];
                      else
                        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("strFunction:"..strFunction.." is not a function"));
                      end
                  end
              end
          end
      end
    end
    if type(v) == "function" then
      return v(...);
    else
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("strFunction:"..strFunction.." is not a function"));
    end
  end



--创建全局唯一的UUID
function LuaNFrame.GetUUID()
    return CPPNFrame:GetUUID()
end

--获得服务器开启时间，单位ms
function LuaNFrame.GetInitTime()
    return CPPNFrame:GetInitTime()
end

--获得服务器当前时间，单位ms
function LuaNFrame.GetNowTime()
    return CPPNFrame:GetNowTime()
end

--获得服务器当前时间，单位ms
function LuaNFrame.GetMsecTime()
    return CPPNFrame:GetMsecTime()
end

--获得服务器当前时间，单位s
function LuaNFrame.GetSecTime()
    return CPPNFrame:GetSecTime()
end

--通过字符串获得MD5, 返回MD5字符串
function LuaNFrame.GetMD5(str)
	if type(str) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("GetMD5 Para Error"))
		return
    end
    return CPPNFrame:GetMD5(str)
end

--通过字符串获得对应的CRC32, 返回数字
function LuaNFrame.GetCRC32(str)
	if type(str) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("GetCRC32 Para Error"))
		return
    end
    return CPPNFrame:GetCRC32(str)
end

--通过字符串获得对应的CRC16, 返回数字
function LuaNFrame.GetCRC16(str)
	if type(str) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("GetCRC16 Para Error"))
		return
    end
    return CPPNFrame:GetCRC16(str)
end

--通过字符串获得对应的Base64Encode, 返回字符串
function LuaNFrame.Base64Encode(str)
	if type(str) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("Base64Encode Para Error"))
		return
    end
    return CPPNFrame:Base64Encode(str)
end

--通过字符串获得对应的Base64Decode, 返回字符串
function LuaNFrame.Base64Decode(str)
	if type(str) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("Base64Decode Para Error"))
		return
    end
    return CPPNFrame:Base64Decode(str)
end

function LuaNFrame.Sha256(str)
    return CPPNFrame:Sha256(str)
end

function LuaNFrame.Platform()
    return CPPNFrame:Platform()
end

function LuaNFrame.IsThreadModule()
    return CPPNFrame:IsThreadModule()
end



function LuaNFrame.ExeFunc(func)
	local status, msg = xpcall (func, __G__TRACKBACK__)

    if not status then
        LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, msg)
    end
end

function LuaNFrame.BeginProfiler(name)
    CPPNFrame:BeginProfiler(name)
end

function LuaNFrame.EndProfiler()
    CPPNFrame:EndProfiler()
end

function LuaNFrame.SendMsgToPlayer(unLinkId, nPlayerId, nMsgId, nLen, strData)
	if type(unLinkId) == "number" and type(nMsgId) == "number" and type(strData) == "string" and type(nPlayerId) == "number" and type(nLen) == "number" then
		if tonumber(nLen) == string.len(strData) or tonumber(nLen) == 0 then
			if tonumber(nLen) == 0 then
				nLen = string.len(strData)
			end
			CPPNFrame:SendMsgToPlayer(unLinkId, nPlayerId, nMsgId, nLen, strData)
		end
	else
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("LuaNFrame.SendMsgToPlayer Para Error"))
	end
end

function LuaNFrame.SendMsgToManyPlayer(nPlayerIdList, nMsgId, nLen, strData)
	if type(nPlayerIdList) == "table" and type(nMsgId) == "number" and type(strData) == "string" and type(nLen) == "number" then
		if tonumber(nLen) == string.len(strData) or tonumber(nLen) == 0 then
			if tonumber(nLen) == 0 then
				nLen = string.len(strData)
			end
			CPPNFrame:SendMsgToManyPlayer(nPlayerIdList, nMsgId, nLen, strData)
		end
	else
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("LuaNFrame.SendMsgToManyPlayer Para Error"))
	end
end

function LuaNFrame.SendMsgToAllPlayer(nMsgId, nLen, strData)
	if type(nMsgId) == "number" and type(strData) == "string" and type(nLen) == "number" then
		if tonumber(nLen) == string.len(strData) or tonumber(nLen) == 0 then
			if tonumber(nLen) == 0 then
				nLen = string.len(strData)
			end
			CPPNFrame:SendMsgToAllPlayer(nMsgId, nLen, strData)
		end
	else
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("LuaNFrame.SendMsgToAllPlayer Para Error"))
	end
end

function LuaNFrame.SendMsgToMaster(unLinkId, nPlayerId, nMsgId, nLen, strData)
	if type(unLinkId) == "number" and type(nMsgId) == "number" and type(strData) == "string" and type(nPlayerId) == "number" and type(nLen) == "number" then
		if tonumber(nLen) == string.len(strData) or tonumber(nLen) == 0  then
			if tonumber(nLen) == 0 then
				nLen = string.len(strData)
			end
			CPPNFrame:SendMsgToMaster(unLinkId, nPlayerId, nMsgId, nLen, strData)
		end
	else
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("LuaNFrame.SendMsgToMaster Para Error"))
	end
end

function LuaNFrame.SendMsgToHttpServer(servertype, requestId, nLen, strData)
	if type(servertype) == "number" and type(requestId) == "number" and type(strData) == "string" and type(nLen) == "number" then
		if tonumber(nLen) == string.len(strData) or tonumber(nLen) == 0  then
			if tonumber(nLen) == 0 then
				nLen = string.len(strData)
			end
			CPPNFrame:SendMsgToHttpServer(servertype, requestId, strData)
		end
	else
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("LuaNFrame.SendMsgToHttpServer Para Error"))
	end
end


--执行游戏服务器信息
function LuaNFrame.DispatchGameTcp(unLinkId, valueId, nMsgId, strMsg)
	local function TcpExecute()
		local retMsgID,controller = tcpManager:createController(nMsgId)
	
		if controller == nil then
			LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, valueId, "nMsgId:"..nMsgId.." not handled!")
		else
			g_operateID = g_operateID + 1
			local playerID, retCode, retBufferLen, retString, otString = controller.execute(nMsgId, g_operateID, strMsg)
			if type(playerID) == "number" and playerID == 0 then
				playerID = valueId
			end

			--登录协议特殊处理一下
			if nMsgId == 1001 then
				LuaNFrame.SendMsgToPlayer(unLinkId, valueId, retMsgID, retBufferLen, retString)
			else
				LuaNFrame.SendMsgToPlayer(unLinkId, playerID, retMsgID, retBufferLen, retString)
			end
		end
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchGameTcp error, unLinkId:"..tostring(unLinkId).." valueId:"..tostring(valueId).." nMsgId:"..nMsgId, msg)
    end
end

--执行游戏服务器信息
function LuaNFrame.DispatchWorldTcp(unLinkId, valueId, nMsgId, strMsg)
	local function TcpExecute()
		local retMsgID,controller = tcpManager:createController(nMsgId)
	
		if controller == nil then
			LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, valueId, "nMsgId:"..nMsgId.." not handled!")
		else
			g_operateID = g_operateID + 1
			local playerID, retCode, retBufferLen, retString, otString = controller.execute(nMsgId, g_operateID, strMsg)
			if type(playerID) == "number" and playerID == 0 then
				playerID = valueId
			end

			--登录协议特殊处理一下
			if nMsgId == 1001 then
				LuaNFrame.SendMsgToPlayer(unLinkId, valueId, retMsgID, retBufferLen, retString)
			else
				LuaNFrame.SendMsgToPlayer(unLinkId, playerID, retMsgID, retBufferLen, retString)
			end
		end
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchWorldTcp error, unLinkId:"..tostring(unLinkId).." valueId:"..tostring(valueId).." nMsgId:"..nMsgId, msg)
    end
end

