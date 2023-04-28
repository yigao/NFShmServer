
function LuaNFrame.FireCppExecute(serverType, nEventID, bySrcType, nSrcID, nMsgType, nMsgData)
    if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(nEventID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(bySrcType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(nSrcID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

    CPPNFrame:FireExecute(serverType, nEventID, bySrcType, nSrcID, nMsgData)

    local xData = LuaNFrame.Encode(nMsgType, nMsgData)

    CPPNFrame:FireCppExecute(serverType, nEventID, bySrcType, nSrcID, nMsgType, xData)
end

function LuaNFrame.FireExecute(serverType, nEventID, bySrcType, nSrcID, luaData)
    if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(nEventID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(bySrcType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(nSrcID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    CPPNFrame:FireExecute(serverType, nEventID, bySrcType, nSrcID, luaData)
end

function LuaNFrame.Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc, luaFunc)
    if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(nEventID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(bySrcType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

    if type(nSrcID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nEventID Para Error")
		return
    end

    if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

    CPPNFrame:Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc, luaFunc)
end

function LuaNFrame.DispatchEvent(luaFunc,  serverType, nEventID, bySrcType, nSrcID, message)
	local function TcpExecute()
		luaFunc(serverType, nEventID, bySrcType, nSrcID, message)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchEvent error, serverType:"..serverType.." nEventID:"..nEventID.." bySrcType"..bySrcType.." nSrcID:"..nSrcID, msg)
    end
end

function LuaNFrame.DispatchEventStrMsg(luaFunc,  serverType, nEventID, bySrcType, nSrcID, msgType, msgData)
	local function TcpExecute()
        local reqMsg = LuaNFrame.Decode(msgType, msgData)
        if reqMsg ~= nil then
		    luaFunc(serverType, nEventID, bySrcType, nSrcID, reqMsg)
        end
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchEvent error, serverType:"..serverType.." nEventID:"..nEventID.." bySrcType"..bySrcType.." nSrcID:"..nSrcID.." msgType:"..msgType, msg)
    end
end
----------------------------------------event system---------------------------------------------------------------------------------------------------------------