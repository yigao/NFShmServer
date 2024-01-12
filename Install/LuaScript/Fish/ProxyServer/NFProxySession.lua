
LuaNFrame.Class("NFProxySession")

NFProxySession.mapData = NFMap.New()

function NFProxySession.Create(linkId)
    local session = NFProxySession.New()
    NFProxySession.mapData:Insert(linkId, session)
    return session
end

function NFProxySession.GetSession(linkId)
    return NFProxySession.mapData:Find(linkId)
end

function NFProxySession.DeleteSession(linkId)
    NFProxySession.mapData:Remove(linkId)
end

function NFProxySession:Ctor()
    self.m_linkId = 0;
    self.m_playerId = 0;
    self.m_lastHeartBeatTime = 0;
    self.m_port = 0;
    self.m_timeOut = 0;
    self.m_lastActiveTime = 0;
    self.m_ipAddr = "127.0.0.1";
end

function NFProxySession:GetLinkId()
    return self.m_linkId
end

 function NFProxySession:SetLinkId(mLinkId)
    self.m_linkId = mLinkId
 end

 function NFProxySession:GetPlayerId()
    return self.m_playerId
 end

 function NFProxySession:SetPlayerId(playerId)
    self.m_playerId = playerId
 end

 function NFProxySession:GetIpAddr()
    return self.m_ipAddr
 end

 function NFProxySession: SetIpAddr(mIpAddr)
    self.m_ipAddr = mIpAddr
 end

 function NFProxySession:GetPort()
    return self.m_port 
 end

 function NFProxySession:SetPort(mPort)
    self.m_port  = mPort
 end

 function NFProxySession:GetLastHeartBeatTime()
    return self.m_lastHeartBeatTime
 end

function NFProxySession:SetLastHeartBeatTime(mLastHeartBeatTime)
    self.m_lastHeartBeatTime = mLastHeartBeatTime
end

function NFProxySession:GetLastActiveTime()
    return self.m_lastActiveTime
end

function NFProxySession:SetLastActiveTime(mLastActiveTime)
    self.m_lastActiveTime = mLastActiveTime
end

function NFProxySession:GetTimeOut()
    return self.m_timeOut
end

function NFProxySession:SetTimeOut(mTimeOut)
    self.m_timeOut = mTimeOut
end