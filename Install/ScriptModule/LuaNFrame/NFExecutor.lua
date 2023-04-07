--lua5.3 没有math.mod函数
function math.mod(a, b)
	a = tonumber(a)
	b = tonumber(b)
	return math.fmod(a,b)
end

g_platfrom = 'luaself'           --g_platfrom init for luaself

function md5(md5Str)
	return LuaNFrame.GetMD5(md5Str)
end

g_randomsee = 0
function math.myrandom(...)
	local arg = {...}
	if g_randomsee == 0 then
		math.newrandomseed()
		g_randomsee = 1
	end
	for i = 1, #arg do
		arg[i] = math.floor(arg[i])
	end

	return math.random(table.unpack(arg))
end

function LogFile(file, msg)
	local cStackInfo = debug.getinfo(2, "Sl")
	if cStackInfo then
		if type(file) == "string" then
			if file == "error" then
				CPPNFrame:Error(NFLogId.NF_LOG_SYSTEMLOG, 0, "["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(msg))
				return
			end
		end
		CPPNFrame:Info(NFLogId.NF_LOG_SYSTEMLOG, 0, "["..tostring(cStackInfo.short_src)..":"..tostring(cStackInfo.currentline).."] | "..tostring(msg))
	else
		CPPNFrame:Info(NFLogId.NF_LOG_SYSTEMLOG, 0, tostring(msg))
	end
end

function SendMessage(useridList, retMsgID, buffLen, retString)

	if useridList == nil or buffLen == 0  then
		return 
	end

	local userIDStr = {}
	if type(useridList) == "table" then
		if #useridList == 0 then
			return
		end
		
		for key,values in pairs(useridList) do
			if RobotService.IsRobot(values) ~= true and tonumber(values) > 1000 then
				table.insert(userIDStr, tonumber(values))
			end
			if #userIDStr >= 20 then
				LuaNFrame.SendMsgToManyPlayer(userIDStr, retMsgID, buffLen, retString)
				userIDStr = {}
			end
		end
		if #userIDStr > 0 then
			LuaNFrame.SendMsgToManyPlayer(userIDStr, retMsgID, buffLen, retString)
		end
	else
		if RobotService.IsRobot(useridList) ~= true and tonumber(useridList) > 1000 then
			LuaNFrame.SendMsgToPlayer(0, tonumber(useridList), retMsgID, buffLen, retString)
		end
	end
end

function Sha256(content)
	return LuaNFrame.Sha256(content)
end

function HttpPost(url,content)
	local str = LuaNFrame.HttpPost(url,content)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpPostWithHead(url,content,head)
	local str = LuaNFrame.HttpPostWithHead(url,content,head)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpGet(url)
	local str = LuaNFrame.HttpGet(url)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end

function HttpGetWithHead(url,head)
	local str LuaNFrame.HttpGetWithHead(url,head)
	if type(str) ~= "string" then
		str = "{}"
	else
		if str == "" then
			str = "{}"
		end
	end
	return str
end