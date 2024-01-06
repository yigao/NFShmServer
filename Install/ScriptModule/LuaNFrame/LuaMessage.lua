eMsgType_Num = 0
eMsgType_CONNECTED = 1
eMsgType_DISCONNECTED = 2
eMsgType_RECIVEDATA = 3
eMsgType_SENDBUFFER = 4

NF_MODULE_SERVER= 0  --服务器内网通讯
NF_MODULE_CLIENT = 1   --客户端外部协议
NF_MODULE_MAX = 2

function LuaNFrame.GetServerByServerType(eSendType, serverTypes)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	return CPPNFrame:GetServerByServerType(eSendType, serverTypes)
end

function LuaNFrame.GetFirstServerByServerType(eSendType, serverTypes)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	return CPPNFrame:GetFirstServerByServerType(eSendType, serverTypes)
end

function LuaNFrame.GetFirstServerByCross(eSendType, serverTypes, crossServer)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	if type(crossServer) ~= "boolean" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	return CPPNFrame:GetFirstServerByCross(eSendType, serverTypes, crossServer)
end

function LuaNFrame.GetRandomServerByServerType(eSendType, serverTypes)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	return CPPNFrame:GetRandomServerByCross(eSendType, serverTypes)
end

function LuaNFrame.GetRandomServerByCross(eSendType, serverTypes, crossServer)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	if type(crossServer) ~= "boolean" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	return CPPNFrame:GetRandomServerByCross(eSendType, serverTypes, crossServer)
end

function LuaNFrame.GetSuitServerByServerType(eSendType, serverTypes, value)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end
	
	if type(value) == "number" then
		return CPPNFrame:GetSuitServerByInt(eSendType, serverTypes, value)
	elseif type(value) == "string" then
		return CPPNFrame:GetSuitServerByStr(eSendType, serverTypes, value)
	else
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "value Para Error")
		return
	end
end

function LuaNFrame.GetSuitServerByStrCross(eSendType, serverTypes, value, crossServer)
	if type(eSendType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(serverTypes) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	if type(crossServer) ~= "boolean" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverTypes Para Error")
		return
    end

	if type(value) == "number" then
		return CPPNFrame:GetSuitServerByIntCross(eSendType, serverTypes, value, crossServer)
	elseif type(value) == "string" then
		return CPPNFrame:GetSuitServerByStrCross(eSendType, serverTypes, value, crossServer)
	else
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "value Para Error")
		return
	end
end

function LuaNFrame.RegisterClientMessage(eServerType, nMsgID,  strLuaFunc, createCo)
	if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
	end
    
	CPPNFrame:RegisterClientMessage(eServerType, nMsgID, strLuaFunc, createCo)
end

function LuaNFrame.RegisterServerMessage(eServerType, nMsgID, strLuaFunc, createCo)
	if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
	end
	
	CPPNFrame:RegisterServerMessage(eServerType, nMsgID, strLuaFunc, createCo)
end

--执行服务器协议处理函数
function LuaNFrame.DispatchClientMessage(luaFunc, strLuaFunc, msgId, packet, param1, param2)
	local function TcpExecute()
		luaFunc(msgId, packet, param1, param2)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchClientMessage error, luaFunc:"..strLuaFunc.." msgId:"..tostring(msgId), msg)
    end
end

function LuaNFrame.DispatchServerMessage(luaFunc, strLuaFunc, msgId, packet, param1, param2)
	local function TcpExecute()
		luaFunc(msgId, packet, param1, param2)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchServerMessage error, luaFunc:"..strLuaFunc.." msgId:"..tostring(msgId), msg)
    end
end

function LuaNFrame.SendMsgByLinkId(usLinkId, nMsgID, nMsgData, nParam1, nParam2)
	if type(usLinkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "usLinkId Para Error")
		return
    end

	if type(nMsgID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	if type(nMsgData)  ~= "table" and type(nMsgData)  ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	if  type(nMsgData)  == "table" then 
		local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
		CPPNFrame:SendMsgByLinkId(usLinkId, nMsgID, xData, nParam1, nParam2)
	elseif type(nMsgData)  == "string" then
		CPPNFrame:SendMsgByLinkId(usLinkId, nMsgID, nMsgData, nParam1, nParam2)
	end
end



function LuaNFrame.SendMsgToMasterServer(eServerType, nMsgID, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(nMsgID) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)

	CPPNFrame:SendMsgToMasterServer(eServerType, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, nMsgData)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

    if type(ids) ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "ids Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)

   CPPNFrame:SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, xData)
end

function LuaNFrame.SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID,  nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendMsgToWorldServer(eServerType, nModuleId, nMsgID, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToWorldServer(eServerType, nModuleId, nMsgID, nMsgData.__cname, nParam1, nParam2)
end

function LuaNFrame.SendTransToWorldServer(eServerType, nMsgID, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(req_trans_id) == "string" then
		req_trans_id = tonumber(req_trans_id)
	else
		req_trans_id = 0
    end

	if type(rsp_trans_id) == "string" then
		rsp_trans_id = tonumber(rsp_trans_id)
	else
		rsp_trans_id = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendTransToWorldServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToGameServer(eServerType, nDstId, nMsgID, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(req_trans_id) == "string" then
		req_trans_id = tonumber(req_trans_id)
	else
		req_trans_id = 0
    end

	if type(rsp_trans_id) == "string" then
		rsp_trans_id = tonumber(rsp_trans_id)
	else
		rsp_trans_id = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendTransToGameServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToLogicServer(eServerType, nDstId, nMsgID, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(req_trans_id) == "string" then
		req_trans_id = tonumber(req_trans_id)
	else
		req_trans_id = 0
    end

	if type(rsp_trans_id) == "string" then
		rsp_trans_id = tonumber(rsp_trans_id)
	else
		rsp_trans_id = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendTransToLogicServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToSnsServer(eServerType, nModuleId, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(nParam1) == "string" then
		nParam1 = tonumber(nParam1)
	else
		nParam1 = 0
    end

	if type(nParam2) == "string" then
		nParam2 = tonumber(nParam2)
	else
		nParam2 = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendMsgToSnsServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToSnsServer(eServerType, nMsgID, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	if type(req_trans_id) == "string" then
		req_trans_id = tonumber(req_trans_id)
	else
		req_trans_id = 0
    end

	if type(rsp_trans_id) == "string" then
		rsp_trans_id = tonumber(rsp_trans_id)
	else
		rsp_trans_id = 0
    end

	local xData = LuaNFrame.Encode(nMsgData.__cname, nMsgData)
	
    CPPNFrame:SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

----------------------------------------rpc service---------------------------------------------------------------------------------------------------------------
function LuaNFrame.AddRpcService(serverType, nMsgId, reqType, rspType, strLuaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(reqType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType Para Error")
		return
	else
		local name = LuaNFrame.pb.type(reqType)
		if name == nil then
			LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType Para Error, reqType.."..reqType.." is not a protobuf message")
			return
		end
    end

	if type(rspType)  ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "rspType Para Error")
		return
	else
		local name = LuaNFrame.pb.type(rspType)
		if name == nil then
			LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType Para Error, rspType.."..rspType.." is not a protobuf message")
			return
		end
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddRpcService(serverType, nMsgId, reqType, rspType, strLuaFunc, createCo)
end

function LuaNFrame.GetRpcService(serverType, dstServerType, dstBusId, msgId, reqType, request, rspType)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(dstServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "dstServerType Para Error")
		return
    end

	if type(dstBusId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "dstBusId Para Error")
		return
    end

	if type(request) ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "request Para Error")
		return
	end

	if type(reqType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType Para Error")
		return
	else
		local name = LuaNFrame.pb.type(reqType)
		if name == nil then
			LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType Para Error, reqType.."..reqType.." is not a protobuf message")
			return
		end
    end

	if type(rspType)  ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "rspType Para Error")
		return
	else
		local name = LuaNFrame.pb.type(rspType)
		if name == nil then
			LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "rspType Para Error, rspType:"..rspType.." is not a protobuf message")
			return
		end
    end

	local reqeustData = LuaNFrame.Encode(reqType, request)
	if type(reqeustData) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType:"..reqType.." Encode Failed")
		return
	end

	local respone, iRetCode = CPPNFrame:GetRpcService(serverType, dstServerType, dstBusId, msgId, reqType, reqeustData, rspType)
	if iRetCode == 0 then
		return LuaNFrame.Decode(rspType, respone)
	else
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "GetRpcService Failed, reqType:"..reqType.." rspType:"..rspType.." iRetCode:"..iRetCode)
	end
end

function LuaNFrame.DispatchRpcMessage(luaFunc,  strLuaFunc, reqType,  request,  rspType, respone)
	local function TcpExecute()
		local reqMsg = LuaNFrame.Decode(reqType, request)
		local rspMsg = LuaNFrame.Defaults(rspType)
		luaFunc(reqMsg, rspMsg)
		if type(rspMsg) == "table" then
			local data = LuaNFrame.Encode(rspType, rspMsg)
			if type(data) == "string" then
				respone = data
			end
		end
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.DispatchRpcMessage error, luaFunc:"..strLuaFunc.." reqType:"..reqType.." rspType:"..rspType,  msg)
    end
end


----------------------------------------rpc service---------------------------------------------------------------------------------------------------------------
function LuaNFrame.GetClientLinkId(serverType)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return 0
    end

    return CPPNFrame:GetClientLinkId(serverType)
end

function LuaNFrame.GetServerLinkId(serverType)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return 0
    end

    return CPPNFrame:GetServerLinkId(serverType)
end

--添加连接事件，掉线事件的处理函数
function  LuaNFrame.AddEventCallBack(serverType, linkId,  strLuaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddEventCallBack(serverType, linkId,  strLuaFunc, createCo)
end

--未没有注册过的消息，添加一个统一处理的回调函数
function  LuaNFrame.AddOtherCallBack(serverType, linkId, strLuaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddOtherCallBack(serverType, linkId, strLuaFunc, createCo)
end
 
--对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
function  LuaNFrame.AddAllMsgCallBack(serverType, strLuaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(strLuaFunc) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc Para Error")
		return
    end

	local luaFunc = LuaNFrame.GetLuaData(strLuaFunc)
	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "strLuaFunc:"..strLuaFunc.." Is Not a Function")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddAllMsgCallBack(serverType, strLuaFunc, createCo)
end

function LuaNFrame.DispatchSocketEvent(luaFunc,  strLuaFunc, nEvent, unLinkId)
	local function TcpExecute()
		luaFunc(nEvent, unLinkId)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.DispatchSocketEvent error, strLuaFunc:"..strLuaFunc.." nEvent:"..nEvent.." unlinkId:"..unLinkId, msg)
    end
end

function LuaNFrame.DispatchOtherMessage(luaFunc,  strLuaFunc, unLinkId, packet)
	local function TcpExecute()
		luaFunc(unLinkId, packet)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.DispatchOtherMessage error, luaFunc"..strLuaFunc.." packet:"..packet:ToString(), msg)
    end
end

function LuaNFrame.DispatchAllOtherMessage(luaFunc,  strLuaFunc, unLinkId, packet)
	local function TcpExecute()
		luaFunc(unLinkId, packet)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.DispatchAllOtherMessage error, luaFunc:"..strLuaFunc.." packet:"..packet:ToString(), msg)
    end
end