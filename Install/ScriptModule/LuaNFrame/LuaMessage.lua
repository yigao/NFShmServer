
function LuaNFrame.RegisterClientMessage(eServerType, nMsgID, luaFunc)
	if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

	if type(nMsgID) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("luaFunc Para Error"))
		return
    end
    
	local function RegisterExecute()
		CPPNFrame:RegisterClientMessage(eServerType, nMsgID, luaFunc)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.RegisterClientMessage error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID).." luaFunc:"..__G__FUNCTION__(luaFunc), msg)
    end
end

function LuaNFrame.RegisterServerMessage(eServerType, nMsgID, luaFunc)
	if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

	if type(nMsgID) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
		return
    end

	if type(luaFunc) ~= "function" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("luaFunc Para Error"))
		return
    end
	
	local function RegisterExecute()
		CPPNFrame:RegisterServerMessage(eServerType, nMsgID, luaFunc)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.RegisterServerMessage error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID).." luaFunc:"..__G__FUNCTION__(luaFunc), msg)
    end
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
	else if type(nMsgID) == "number" then
		return nMsgID
    end
end


function LuaNFrame.SendMsgToMasterServer(eServerType, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)

	local function RegisterExecute()
		CPPNFrame:SendMsgToMasterServer(eServerType, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendMsgToMasterServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendProxyMsgByBusId(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendProxyMsgByBusId error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, nMsgType, nMsgData)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

    if type(ids) ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("ids Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
		return
    end

	nMsgID = LuaNFrame.GetMsgId(nMsgID)
	if nMsgID == nil then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)

	local function RegisterExecute()
        CPPNFrame:SendRedirectMsgToProxyServer(eServerType, nDstId, ids, nMsgID, xData)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendRedirectMsgToProxyServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID,  nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendMsgToProxyServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendMsgToProxyServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendMsgToWorldServer(eServerType, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendMsgToWorldServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendMsgToMasterServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendTransToWorldServer(eServerType, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

	if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendTransToWorldServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendTransToWorldServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendMsgToGameServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendMsgToGameServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendTransToGameServer(eServerType, nDstId, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendTransToGameServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendTransToGameServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, nMsgType, nMsgData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendMsgToLogicServer(eServerType, nDstId, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(valueId, "LuaNFrame.SendMsgToLogicServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendTransToLogicServer(eServerType, nDstId, nMsgID, nMsgType, nMsgData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nDstId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nDstId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendTransToLogicServer(eServerType, nDstId, nMsgID, xData, req_trans_id, rsp_trans_id)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.SendTransToLogicServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendMsgToSnsServer(eServerType, nModuleId, nMsgType, nMsgData, xData, nParam1, nParam2)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

    if type(nModuleId) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nModuleId Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendMsgToSnsServer(eServerType, nModuleId, nMsgID, xData, nParam1, nParam2)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.SendMsgToSnsServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end

function LuaNFrame.SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
    if type(eServerType) ~= "number" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("eServerType Para Error"))
		return
    end

	if type(nMsgType) ~= "string" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgType Para Error"))
		return
    end

	if type(nMsgData)  ~= "table" then
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgData Para Error"))
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
		LuaNFrame.Error(NFLogId.NF_LOG_SYSTEMLOG, 0, __G__TRACKBACK__("nMsgID Para Error"))
    end

	local xData = LuaNFrame.Encode(nMsgType, nMsgData)
	
	local function RegisterExecute()
        CPPNFrame:SendTransToSnsServer(eServerType, nMsgID, xData, req_trans_id, rsp_trans_id)
	end
	
	local status, msg = xpcall (RegisterExecute, __G__TRACKBACK__)

	if not status then
		LuaNFrame.SendErrorLog(0, "LuaNFrame.SendTransToSnsServer error, eServerType:"..tostring(eServerType).." nMsgID:"..tostring(nMsgID), msg)
    end
end




