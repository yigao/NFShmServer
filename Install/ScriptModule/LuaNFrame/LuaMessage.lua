eMsgType_Num = 0
eMsgType_CONNECTED = 1
eMsgType_DISCONNECTED = 2
eMsgType_RECIVEDATA = 3
eMsgType_SENDBUFFER = 4

function LuaNFrame.RegisterClientMessage(eServerType, nMsgID, luaFunc, createCo)
	if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
	end
    
	CPPNFrame:RegisterClientMessage(eServerType, nMsgID, luaFunc, createCo)
end

function LuaNFrame.RegisterServerMessage(eServerType, nMsgID, luaFunc, createCo)
	if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
	end
	
	CPPNFrame:RegisterServerMessage(eServerType, nMsgID, luaFunc, createCo)
end

--执行服务器协议处理函数
function LuaNFrame.DispatchMessage(luaFunc, msgId, packet, param1, param2)
	local function TcpExecute()
		luaFunc(msgId, packet, param1, param2)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchMessage error, luaFunc:"..__G__FUNCTION__(luaFunc).." msgId:"..tostring(msgId), msg)
    end
end



function LuaNFrame.GetMsgId(nMsgID)
	if type(nMsgID) == "string" then
		local msgId = LuaNFrame.Enum("proto_ff.ClientServerCmd",  nMsgID)
		if msgId == nil then
			msgId = LuaNFrame.Enum("proto_ff.Proto_SvrMsgID",  nMsgID)
		end
		return msgId
	elseif type(nMsgID) == "number" then
		return nMsgID
    end
end


function LuaNFrame.SendMsgToMasterServer(eServerType, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
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

	local nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)

	CPPNFrame:SendMsgToMasterServer(eServerType, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
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

	if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, nMsgType, nMsgData)
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

	if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgData Para Error")
		return
    end

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)

   CPPNFrame:SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, xData)
end

function LuaNFrame.SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID,  nMsgType, nMsgData, nParam1, nParam2)
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

	if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendMsgToWorldServer(eServerType, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToWorldServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToWorldServer(eServerType, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

	if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendTransToWorldServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
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

	if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToGameServer(eServerType, nDstId, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendTransToGameServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
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

	if type(nMsgType) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgType Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToLogicServer(eServerType, nDstId, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nDstId Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendTransToLogicServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
end

function LuaNFrame.SendMsgToSnsServer(eServerType, nModuleId, nMsgType, nMsgData, xData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nModuleId Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendMsgToSnsServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
end

function LuaNFrame.SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "eServerType Para Error")
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

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
    CPPNFrame:SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
end

----------------------------------------rpc service---------------------------------------------------------------------------------------------------------------
function LuaNFrame.AddRpcService(serverType, nMsgId, reqType, rspType, luaFunc, createCo)
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

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

	local nRealMsgId = LuaNFrame.GetMsgId(nMsgId)
	if nRealMsgId == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end
    return CPPNFrame:AddRpcService(serverType, nRealMsgId, reqType, rspType, luaFunc, createCo)
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

	local nRealMsgId = LuaNFrame.GetMsgId(msgId)
	if nRealMsgId == nil then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "nMsgID Para Error")
		return
    end

	local reqeustData = LuaNFrame.Encode(reqType, request)
	if type(reqeustData) ~= "string" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "reqType:"..reqType.." Encode Failed")
		return
	end

	local respone, iRetCode = CPPNFrame:GetRpcService(serverType, dstServerType, dstBusId, nRealMsgId, reqType, reqeustData, rspType)
	if iRetCode == 0 then
		return LuaNFrame.Decode(rspType, respone)
	else
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "GetRpcService Failed, reqType:"..reqType.." rspType:"..rspType.." iRetCode:"..iRetCode)
	end
end

function LuaNFrame.DispatchRpcMessage(luaFunc,  reqType,  request,  rspType, respone)
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
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchRpcMessage error, reqType:"..reqType.." rspType:"..rspType,  msg)
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
function  LuaNFrame.AddEventCallBack(serverType, linkId,  luaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddEventCallBack(serverType, linkId,  luaFunc, createCo)
end

--未没有注册过的消息，添加一个统一处理的回调函数
function  LuaNFrame.AddOtherCallBack(serverType, linkId, luaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddOtherCallBack(serverType, linkId, luaFunc, createCo)
end
 
--对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
function  LuaNFrame.AddAllMsgCallBack(serverType, luaFunc, createCo)
	if type(serverType) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "serverType Para Error")
		return
    end

	if type(linkId) ~= "number" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "linkId Para Error")
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.ErrorWithThread(NFLogId.NF_LOG_SYSTEMLOG, 0, 3, "luaFunc Para Error")
		return
    end

	if type(createCo) ~= "boolean" then
		createCo = false
    end

    return CPPNFrame:AddAllMsgCallBack(serverType, luaFunc, createCo)
end

function LuaNFrame.DispatchSocketEvent(luaFunc,  nEvent, unLinkId)
	local function TcpExecute()
		luaFunc(nEvent, unLinkId)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchSocketEvent error, nEvent:"..nEvent.." unlinkId:"..unLinkId, msg)
    end
end

function LuaNFrame.DispatchOtherMessage(luaFunc,  unLinkId, packet)
	local function TcpExecute()
		luaFunc(unLinkId, packet)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchOtherMessage error, packet:"..packet:ToString(), msg)
    end
end

function LuaNFrame.DispatchAllOtherMessage(luaFunc,  unLinkId, packet)
	local function TcpExecute()
		luaFunc(unLinkId, packet)
	end
	
	local status, msg = xpcall (TcpExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.DispatchAllOtherMessage error, packet:"..packet:ToString(), msg)
    end
end