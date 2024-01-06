
LuaNFrame.Class("NFProxyPlayerInfo")

NFProxyPlayerInfo.mapData = NFMap.New()

function NFProxyPlayerInfo.Create(playerId)
    local playerInfo = NFProxyPlayerInfo.New()
    playerInfo:SetPlayerId(playerId)
    NFProxyPlayerInfo.mapData:Insert(playerId, playerInfo)
    return playerInfo
end

function NFProxyPlayerInfo.GetPlayerInfo(playerId)
    return NFProxyPlayerInfo.mapData:Find(playerId)
end

function NFProxyPlayerInfo.DeletePlayerInfo(playerId)
    NFProxyPlayerInfo.mapData:Remove(playerId)
end

function NFProxyPlayerInfo:Ctor()
    self.m_linkId = 0;
    self.m_worldBusId = 0;
    self.m_gameId = 0;
    self.m_roomId = 0;
    self.m_gameBusId = 0;
    self.m_logicBusId = 0;
    self.m_disconnectTime = 0;
    self.m_online = false;
    self.m_isLogin = false;
    self.m_playerId = 0;
    self.m_ipAddr = "127.0.0.1";
    self.m_account = "none";
end

function NFProxyPlayerInfo:GetLinkId()
    return self.m_linkId
end

function NFProxyPlayerInfo:SetLinkId(linkId)
    self.m_linkId = linkId
end

function GetWorldBusId()
    return self.m_worldBusId
end

function NFProxyPlayerInfo:SetWorldBusId(worldBusId)
    self.m_worldBusId = worldBusId
end

function NFProxyPlayerInfo:GetGameBusId()
    return self.m_gameBusId
end
function NFProxyPlayerInfo:SetGameBusId(gameBusId)
    self.m_gameBusId = gameBusId
end

function NFProxyPlayerInfo:GetLogicBusId()
    return self.m_logicBusId
end

function NFProxyPlayerInfo:SetLogicBusId(logicBusId)
    self.m_logicBusId = logicBusId
end

function NFProxyPlayerInfo:GetDisconnectTime()
    return self.m_disconnectTime
end

function NFProxyPlayerInfo:SetDisconnectTime(disconnectTime)
    self.m_disconnectTime = disconnectTime
end

function NFProxyPlayerInfo:IsOnline()
    return self.m_online
end

function NFProxyPlayerInfo:SetOnline(online)
    self.m_online = online
end
function NFProxyPlayerInfo:IsLogin()
    return self.m_isLogin
end

function NFProxyPlayerInfo:SetIsLogin(isLogin)
    self.m_isLogin = isLogin
end

function NFProxyPlayerInfo:GetPlayerId()
    return self.m_playerId
end

function NFProxyPlayerInfo:SetPlayerId(uid)
    self.m_playerId = uid
end

function NFProxyPlayerInfo:GetIpAddr()
    return self.m_ipAddr
end

function NFProxyPlayerInfo:SetIpAddr(ipAddr)
    self.m_ipAddr = ipAddr
end

function NFProxyPlayerInfo:GetAccount()
    return self.m_account
end

function NFProxyPlayerInfo:SetAccount(account)
    self.m_account = account
end

function NFProxyPlayerInfo:GetGameId()
    return self.m_gameId
end

function NFProxyPlayerInfo:GetRoomId() 
    return self.m_roomId
end

function NFProxyPlayerInfo:SetGameId(gameId)
    self.m_gameId = gameId
end
    
function NFProxyPlayerInfo:SetRoomId(roomId) 
    self.m_roomId = roomId
end

