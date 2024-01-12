LoginCommon = LoginCommon or {}
LoginCommon.FISH_LOGIN_TOKEN = "Fish_ShmNFrame"

function LoginCommon.GetLoginToken(account, userId, time)
    local token = account .. "_" .. userId .. "_" .. time .. "_" .. LoginCommon.FISH_LOGIN_TOKEN
    return LuaNFrame.GetMD5(token);
end
