
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
    CPPNFrame:Subscribe(serverType, nEventID, bySrcType, nSrcID, strLuaFunc, luaFunc)
end
----------------------------------------event system---------------------------------------------------------------------------------------------------------------