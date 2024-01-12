
LuaNFrame.Class("NFAccountLogin")

NFAccountLogin.mapData = NFMap.New()

function NFAccountLogin.CreateAccount(account, password, playerId, accountType, deviceId, phonenum)
    local accountLogin = NFAccountLogin.New()
    accountLogin.mAccount = account
    accountLogin.mPassword = password;
	accountLogin.mPlayerId = playerId;
	accountLogin.mAccountType = accountType;
	accountLogin.mLastLoginTime = LuaNFrame.GetSecTime()
	accountLogin.mDeviceId = deviceId;
	accountLogin.mPhoneNum = phonenum;
    NFAccountLogin.mapData:Insert(account, accountLogin)
    return accountLogin
end

function NFAccountLogin.FindAccount(account)
    return NFProxyPlayerInfo.mapData:Find(account)
end

function NFAccountLogin.DeleteAccount(account)
    NFProxyPlayerInfo.mapData:Remove(account)
end

function NFAccountLogin:Ctor()
	self.mAccount = "";
	self.mPassword = "";
	self.mDeviceId = "";
	self.mPhoneNum = 0;
	self.mPlayerId = 0;
	self.mLastLoginTime = LuaNFrame.GetSecTime();
	self.mAccountType = 0;
end

NFAccountLogin.MAX_ACCOUNT_EXIST_TIME = 300
function NFAccountLogin.Tick(timeId, callCount, dataStr)
    local now = LuaNFrame.GetSecTime();
    local removeAccount = {}
    for key, value in pairs(NFAccountLogin.mapData.map) do
        if now - valuev.mLastLoginTime >= NFAccountLoginMgr.MAX_ACCOUNT_EXIST_TIME then
            removeAccount[key] = 0
        end
    end

    for key in pairs(removeAccount) do
        NFAccountLogin.DeleteAccount(key)
    end
end